#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
 
string s1, s2, s3;
 
int main() {
    ios::sync_with_stdio(false);
    cin >> s1 >> s2 >> s3;
    int num1 = s1[0] - '0';
    int num2 = s2[0] - '0';
    int num3 = s3[0] - '0';
    int nums[] = {num1, num2, num3};
    if(s1[1] == s2[1] && s1[1] == s3[1]) {
        // all same suit
        sort(nums, nums + 3);
        if((nums[0] == nums[1] - 1 && nums[1] == nums[2] - 1) || nums[0] == nums[2]) {
            cout << 0 << endl;
        }else if(nums[1] - nums[0] <= 2 || nums[2] - nums[1] <= 2) {
            cout << 1 << endl;
        }else {
            cout << 2 << endl;
        }
    }else if(s1[1] == s2[1] || s1[1] == s3[1] || s2[1] == s3[1]) {
        if(s1[1] == s3[1]) {
            num2 = num3;
        }else if(s2[1] == s3[1]) {
            num1 = num3;
        }
        if(abs(num1 - num2) <= 2) {
            cout << 1 << endl;
        }else {
            cout << 2 << endl;
        }
    }else {
        cout << 2 << endl;
    }
}