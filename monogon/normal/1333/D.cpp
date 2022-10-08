
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, k;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s;
    vector<vector<int>> ops;
    int sum = 0;
    while(true) {
        vector<int> v;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == 'R' && s[i + 1] == 'L') {
                v.push_back(i);
                s[i] = 'L';
                s[i + 1] = 'R';
                i++;
                sum++;
            }
        }
        if(v.empty()) break;
        ops.push_back(v);
    }
    if(k < (int) ops.size() || k > sum) {
        cout << "-1\n";
        return 0;
    }
    int i = 0, j = 0;
    for(; i < (int) ops.size(); i++) {
        if(k == sum) {
            break;
        }
        int num = min((int) ops[i].size() - j, sum - k + 1);
        cout << num;
        for(int l = 0; l < num; l++) {
            cout << " " << ops[i][j] + 1;
            j++;
            sum--;
        }
        cout << "\n";
        if(j == (int) ops[i].size()) j = 0;
        else break;
        k--;
    }
    for(; i < (int) ops.size(); i++) {
        for(; j < (int) ops[i].size(); j++) {
            cout << "1 " << ops[i][j] + 1 << "\n";
        }
        j = 0;
    }
}