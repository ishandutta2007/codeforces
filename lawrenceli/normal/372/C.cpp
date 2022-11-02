#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <deque>

using namespace std;

#define fi first
#define se second

const int MAXN = 150100;
const int MAXM = 305;
const long long INF = 1e18;

typedef long long ll;
typedef pair<int, ll> pil;

int n, m, d;
int a[MAXM], b[MAXM], t[MAXM];
ll dp[MAXN][2];

pil dq[MAXN];
int lt, rt;

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n >> m >> d;
    for (int i=1; i<=m; i++) cin >> a[i] >> b[i] >> t[i];

    for (int i=1; i<=n; i++) dp[i][1] = -INF;

    for (int i=1; i<=m; i++) {
        ll dist = ll(d) * (t[i] - t[i-1]);

        lt = 0, rt = MAXN-1;
        for (int j=1; j<=n; j++) {
            pil p = pil(j, dp[j][0]);
            while ((rt+1)%MAXN != lt && dq[rt].se < p.se) rt = (rt-1+MAXN) % MAXN;
            rt = (rt+1)%MAXN, dq[rt] = p;
            while (dq[lt].fi < j - dist) lt = (lt+1)%MAXN;
            dp[j][1] = max(dp[j][1], b[i] - abs(a[i] - j) + dq[lt].se);
        }

        lt = 0, rt = MAXN-1;
        for (int j=n; j>=1; j--) {
            pil p = pil(j, dp[j][0]);
            while ((rt+1)%MAXN != lt && dq[lt].se < p.se) lt = (lt+1)%MAXN;
            lt = (lt-1+MAXN)%MAXN, dq[lt] = p;
            while (dq[rt].fi > j + dist) rt = (rt-1+MAXN)%MAXN;
            dp[j][1] = max(dp[j][1], b[i] - abs(a[i] - j) + dq[rt].se);
        }

        for (int j=1; j<=n; j++)
            dp[j][0] = dp[j][1], dp[j][1] = -INF;

    }

    ll ans = -INF;
    for (int i=1; i<=n; i++) ans = max(ans, dp[i][0]);

    cout << ans << endl;
    return 0;
}