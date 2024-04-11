#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;
int const DELT = 201005;

inline int sum(int a, int b) { return (a + b) % mod; }
inline int mul(int a, int b) { return (1ll * a * b) % mod; }
inline int raz(int a, int b) { return ((a - b) % mod + mod) % mod; }

int a, b, k, t;

int dp[2][DELT * 2 + 5];
int cnt[4005];

bool solve() {

    cin >> a >> b >> k >> t;

    int min_sum = a - b - 2 * k * t;
    int max_sum = a - b + 2 * k * t;

    for(int x = -k;x <= k;x++) {
        for(int y = -k;y <= k;y++) {
            cnt[x + y + 2000]++;
        }
    }

    //cout << min_sum << " " << max_sum << "  !\n";

    dp[0][a - b + DELT] = 1;

    for(int iter = 1;iter <= t;iter++) {
        for(int x = 0;x < DELT * 2 + 5;x++) dp[iter & 1][x] = 0;

        int tot = 0;
        int le = 0;
        int ri = 0;
        for(int add = 0;add <= 2 * k;add++) {
            if(min_sum + add > max_sum) break;
            tot = sum(
                    tot,
                    mul(
                            dp[(iter - 1) & 1][min_sum + add + DELT],
                            cnt[add + 2000]
                    )
            );
            ri = sum(
                ri,
                dp[(iter - 1) & 1][min_sum + add + DELT]
            );
        }
        /*cout << "iter = " << iter << " : ";
        for(int i = min_sum;i <= max_sum;i++) cout << dp[(iter - 1) & 1][i + DELT] << " ";
        cout << "\n";*/
        for(int Add, Del, Sum = min_sum;Sum <= max_sum;Sum++) {
            dp[iter & 1][Sum + DELT] = tot;

            Del = Sum - 2 * k;
            Add = Sum + 2 * k + 1;

            //int tle = le;
            //int tri = ri;

            int Le = le;
            int Ri = ri;

            /*int tle, tri, ttot;
            tle = tri = ttot = 0;

            for(int _add = -2 * k;_add <= 2 * k;_add++) {
                if(Sum + _add < min_sum || Sum + _add > max_sum) continue;
                if(_add < 0) tle = sum(tle, dp[(iter - 1) & 1][Sum + _add + DELT]) ;
                else tri = sum(tri, dp[(iter - 1) & 1][Sum + _add + DELT]);
                ttot = sum(
                        ttot,
                        mul(
                                cnt[_add + 2000],
                                dp[(iter - 1) & 1][Sum + _add + DELT]
                        )
                );
            }*/

            /*cout << "\n";
            cout << "Del = " << Del << ", Add = " << Add << "\n";
            cout << "Val = " << dp[(iter - 1) & 1][Del + DELT] <<
                    ", Val = " << dp[(iter - 1) & 1][Add + DELT] << "\n";
            cout << le << " " << tle << "\n";
            cout << ri << " " << tri << "\n";
            cout << tot << " " << ttot << "\n";
            cout << "\n";*/

            ri = raz(
                    ri,
                    dp[(iter - 1) & 1][Sum + DELT]
            );
            le = sum(
                    le,
                    dp[(iter - 1) & 1][Sum + DELT]
            );

            if(Del >= min_sum) {
                le = raz(
                        le,
                        dp[(iter - 1) & 1][Del + DELT]
                );
            }

            if(Add <= max_sum) {
                ri = sum(
                        ri,
                        dp[(iter - 1) & 1][Add + DELT]
                );
            }

            tot = raz(tot, Le);
            tot = sum(tot, ri);
            tot = raz(tot, dp[(iter - 1) & 1][Sum + DELT]);
        }
    }

    int res = 0;

    for(int Sum = 1;Sum <= max_sum;Sum++)
        res = sum(res, dp[t & 1][Sum + DELT]);

    cout << res << '\n';

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}