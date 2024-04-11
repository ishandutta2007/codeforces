#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int solve(vector<int> num, int k){
    if(k == num.size()){
        int sum = 0;
        for(int i = 0; i < num.size(); i++){
            if(num[i] < 0 || num[i] >= 19) sum = -100000;
            sum += num[i];
        }
        return sum;
    }
    vector<int> num1 = num;
    int a = solve(num1, k+1);
    if(k+1 < num.size()){
        num1[k]--;
        num1[k+1] += 10;
        a = max(a, solve(num1, k+1));
        num1[k]--;
        num1[k+1] += 10;
        a = max(a, solve(num1, k+1));
    }
    return a;
}

int main(){
    string s;
    cin >> s;
    vector<int> num;
    for(int i = 0; i < s.size(); i++){
        num.push_back(s[i] - '0');
    }
    cout << solve(num, 0) << '\n';
}