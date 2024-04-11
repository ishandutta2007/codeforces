#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 2005;
const int INF = 1e9 + 5;

int n, d[MAXN][MAXN];
pii ar[MAXN];

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    rep(i, n)
        rep(j, n) {
            scanf("%d", &d[i][j]);
            if ((i == j) ^ (d[i][j] == 0)) {
                printf("NO\n");
                return 0;
            }
            if (i == 0) ar[j] = pii(d[i][j], j);
        }

    rep(i, n)
        rep(j, n)
            if (d[i][j] != d[j][i]) {
                printf("NO\n");
                return 0;
            }

    sort(ar, ar+n);
    for (int i=1; i<n; i++) {
        int j = ar[i].se;
        int mi = INF, x = -1;
        rep(k, i)
            if (d[ar[k].se][j] < mi)
                mi = d[ar[k].se][j], x = ar[k].se;
        rep(k, i)
            if (d[ar[k].se][x]+d[x][j] != d[ar[k].se][j]) {
                printf("NO\n");
                return 0;
            }
    }
    printf("YES\n");
    return 0;
}