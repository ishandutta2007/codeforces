#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define db double
#define x first
#define y second
#define pi pair<ll, int>
#define vi vector<int>
using namespace std;
const int N = 2e5 + 10, P = 998244353;
string dig;
int num[N];
int dp[N][8][8];
void solve() {
    cin >> dig;
    int n = sz(dig);
    FOR(i, 0, n - 1) num[n - i] = dig[i] - '0';
    num[n + 1] = 0;
    FOR(i, 0, 7) dp[0][i][7] = 1;
    FOR(i, 1, n + 1) {
        FOR(j, 0, 7) {
            int m[3];
            FOR(k, 0, 2) m[k] = (j >> k & 1) ? num[i] : 1;
            FOR(k, 0, 7) {
                FOR(l, 0, 7) {
                    int va = 1;
                    FOR(p, 0, 2) if((l >> p & 1) > m[p]) {
                        va = 0;
                    }
                    if(!va) continue;
                    int a = (l & 1), b = (l >> 1 & 1), c = (l >> 2 & 1);
                    int x = a ^ b, y = b ^ c, z = c ^ a;
                    int sum = x + y + z;
                    int to = 7;
                    FOR(p, 0, 2) if((l >> p & 1) < m[p]) to &= (7 ^ (1 << p));
                    if(sum == 0) {
                        (dp[i][j][k] += dp[i - 1][j & to][k]) %= P;
                    } else {
                        int rto = 0;
                        if(!x) rto |= 1;
                        if(!y) rto |= 2;
                        if(!z) rto |= 4;
                        (dp[i][j][k] += dp[i - 1][j & to][k | rto]) %= P;
                    }
                }
            }
        }
    // cout << dp[i][7][0] << "\n";
    }
    cout << dp[n + 1][7][0] << "\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    for(; t--; ) solve();
    return 0;
}