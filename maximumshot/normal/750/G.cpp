#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef pair< ll, ll > pll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

ll const MAXC = 55;

ll dp[2][2 * MAXC][2];

ll calc(ll sum, ll ones, ll c1, ll c2) {
    for(int i = 0;i < 2 * MAXC;i++) {
        dp[0][i][0] = dp[0][i][1] = 0;
    }
    dp[0][0][0] = 1;
    int last = 0;
    for(int cur, i = 1;(1ll << (i - 1)) <= sum;i++) {

        last = i % 2;

        for(int j = 0;j < 2 * MAXC;j++) {
            dp[i % 2][j][0] = dp[i % 2][j][1] = 0;
        }

        cur = (sum >> (i - 1)) & 1;

        for(int x = 0;x < (i <= c1 ? 2 : 1);x++) {
            for(int y = 0;y < (i <= c2 ? 2 : 1);y++) {
                for(int ost = 0;ost < 2;ost++) {
                    int new_cur = (x + y + ost) % 2;
                    int new_ost = (x + y + ost) / 2;
                    if(new_cur != cur) continue;
                    for(int prev = 0;prev + x + y <= ones;prev++) {
                        dp[i % 2][prev + x + y][new_ost] += dp[(i - 1) % 2][prev][ost];
                    }
                }
            }
        }
    }
    return dp[last][ones][0];
}

int main() {

    ll s;

    cin >> s;

    ll res = 0;

    for(ll c1 = 0;c1 < MAXC;c1++) {
        for(ll c2 = 0;c2 < MAXC;c2++) {
            ll A = (1ll << (c1 + 1)) + (1ll << (c2 + 1)) - 3;
            if(A > s) break;
            ll z = s / A;
            for(ll ones = 0;ones <= c1 + c2;ones++) {
                ll sm = s + ones - z * A + 1 - (1ll << c2);
                if(sm < 0 || sm % 2) continue;
                sm /= 2;
                res += calc(sm, ones, c1? c1 - 1 : 0, c2 ? c2 - 1 : 0);
            }
        }
    }

    cout << res << "\n";

    return 0;
}