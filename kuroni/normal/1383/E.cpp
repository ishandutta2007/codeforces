#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 1E6 + 5, MOD = 1E9 + 7;

int cnt = 1;
long long ans = 1, cur = 1, dp[N];
bool st = true;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    for (int i = 0; ; i++) {
        if (i == s.size()) {
            ans = (ans * cnt % MOD * cur - st) % MOD;
            return cout << (ans + MOD) % MOD, 0;
        }
        if (s[i] == '0') {
            cnt++;
        } else {
            if (st) {
                ans = cnt;
                st = false;
            } else {
                long long lst = cur;
                for (int i = 1; i <= cnt; i++) {
                    (cur += lst - dp[i]) %= MOD;
                    dp[i] = lst;
                }
            }
            cnt = 1;
        }
    }
}