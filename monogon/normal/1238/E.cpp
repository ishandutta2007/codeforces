
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5, M = 25;
string s;
int n, m;
int cnt[M][M];
ll dp[1 << 20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i - 1]) {
            cnt[s[i] - 'a'][s[i - 1] - 'a']++;
            cnt[s[i - 1] - 'a'][s[i] - 'a']++;
        }
    }
    int upper = (1 << m);
    for(int s = 1; s < upper; s++) {
        dp[s] = LLONG_MAX;
        int pos = __builtin_popcount(s);
        for(int i = 0; i < m; i++) {
            if((s >> i) & 1) {
                ll sum = 0;
                for(int j = 0; j < m; j++) {
                    if(i == j) continue;
                    if((s >> j) & 1) {
                        sum += cnt[i][j];
                    }else {
                        sum -= cnt[i][j];
                    }
                }
                dp[s] = min(dp[s], (sum * pos) + dp[s - (1 << i)]);
            }
        }
    }
    cout << dp[upper - 1] << endl;
}