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

int const N = 16;

int n;
char c[N];
int r[N];
int b[N];
int dp[1 << N][N * N + 10];
int cnt_r[1 << N];
int cnt_b[1 << N];

int main() {

    cin >> n;

    int tot_r = 0;
    int tot_b = 0;

    for(int i = 0;i < n;i++) {
        cin >> c[i] >> r[i] >> b[i];
        tot_r += r[i];
        tot_b += b[i];
    }

    for(int mask = 0;mask < (1 << n);mask++) {
        for(int i = 0;i < n;i++) {
            if((1 << i) & mask) {
                if(c[i] == 'R') {
                    cnt_r[mask]++;
                }else {
                    cnt_b[mask]++;
                }
            }
        }
    }

    for(int i = 0;i < (1 << N);i++) {
        for(int j = 0;j < N * N + 10;j++) {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;

    for(int mask = 0;mask < (1 << n);mask++) {
        for(int cr = 0;cr < N * N + 10;cr++) {
            int cb = dp[mask][cr];
            if(cb == -1) continue;
            for(int nw = 0;nw < n;nw++) {
                if((1 << nw) & mask) continue;
                int nw_mask = mask ^ (1 << nw);
                int nw_cr = cr + min(r[nw], cnt_r[mask]);
                int nw_cb = cb + min(b[nw], cnt_b[mask]);
                if(nw_cr < N * N + 10) {
                    dp[nw_mask][nw_cr] = max(
                        dp[nw_mask][nw_cr],
                        nw_cb
                    );
                }
            }
        }
    }

    int res = inf;
    int all = (1 << n) - 1;

    for(int cr = 0;cr < N * N + 10;cr++) {
        if(dp[all][cr] == -1) continue;
        res = min(res, max(tot_r - cr, tot_b - dp[all][cr]) );
    }

    cout << res + n << "\n";

    return 0;
}