#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    if (s.length()%2!=0) {
        cout << "NO\n";
        return;
    }
    bool dp[100], next[100];
    memset(dp, false, 100);
    dp[0]=true;
    for (int i = 0; i < s.length(); i++) {
        memset(next, false, 100);
        if (s[i]=='(') {
            for (int i = 0; i < 100; i++) {
                if (i>0) next[i]=dp[i-1];
            }
        } else if (s[i]==')') {
            for (int i = 0; i < 100; i++) {
                if (i<99) next[i]=dp[i+1];
            }
        } else if (s[i]=='?') {
            for (int i = 0; i < 100; i++) {
                if ((i<99 && dp[i+1]) || (i>0 && dp[i-1])) next[i]=true;
            }
        }
        for (int i = 0; i < 100; i++) dp[i]=next[i];
    }
    if (dp[0]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}