#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans = -1;
        unordered_map<int, int> freq;
        for(int x : nums){
            freq[x]++;
        }

        if(k == nums.size()){
            ans =  *max_element(nums.begin(), nums.end());
        }
        else if(k == 1){
            for(auto x : freq){
                if(x.second == 1){
                    ans = max(ans, x.first);
                }
            }
        }
        else{
            if(freq[nums[0]] == 1)
                ans = nums[0];
            if(freq[nums[nums.size() - 1]] == 1)
                ans = max(ans, nums[nums.size() - 1]);
            
        }
        return ans;
    }
};