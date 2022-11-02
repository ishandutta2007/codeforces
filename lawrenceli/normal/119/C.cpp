#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

struct data {
    ll a, b, c, d;
    bool operator<(const data& d) const {
        return c < d.c;
    }
};

const int MAXN = 55;
const int MAXC = 105;
const ll INF = 1e18;

int n, m, K;
data ar[MAXN];
ll dp[MAXN][MAXN][MAXC];
pll from[MAXN][MAXN][MAXC];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> K;
    for (int i=0; i<m; i++) {
        cin >> ar[i].a >> ar[i].b >> ar[i].c;
        ar[i].d = i+1;
    }
    sort(ar, ar+m);
    for (int i=0; i<MAXN; i++)
        for (int j=0; j<MAXN; j++)
            for (int k=0; k<MAXC; k++)
                dp[i][j][k] = -INF;
    dp[0][0][0] = 0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            for (int k=0; k<=ar[j-1].b-ar[j-1].a; k++)
                for (int j1=0; j1<j; j1++)
                    if (!j1 && i==1 || j1 && ar[j1-1].c < ar[j-1].c) {
                        ll k1 = k+ar[j-1].a-K;
                        if (!j1 || ar[j1-1].a <= k1 && k1 <= ar[j1-1].b) {
                            ll res = j1 ? dp[i-1][j1][k1-ar[j1-1].a]+k+ar[j-1].a : k+ar[j-1].a;
                            if (res > dp[i][j][k])
                                dp[i][j][k] = res, from[i][j][k] = pll(j1, k1-ar[j1-1].a);
                        }
                        if ((k+ar[j-1].a)%K==0) {
                            k1 = (k+ar[j-1].a)/K;
                            if (!j1 || ar[j1-1].a <= k1 && k1 <= ar[j1-1].b) {
                                ll res = j1 ? dp[i-1][j1][k1-ar[j1-1].a]+k+ar[j-1].a : k+ar[j-1].a;
                                if (res > dp[i][j][k])
                                    dp[i][j][k] = res, from[i][j][k] = pll(j1, k1-ar[j1-1].a);
                            }
                        }
                    }
    vector<pll> v;
    ll ans=-INF;
    int x=n, y, z;
    for (int i=1; i<=m; i++)
        for (int j=0; j<MAXC; j++)
            if (dp[n][i][j] > ans)
                ans = dp[n][i][j], y = i, z = j;
    if (ans < 0) {
        cout << "NO\n";
        return 0;
    }
    while (x>0) {
        v.push_back(pll(ar[y-1].d, z+ar[y-1].a));
        pll p = from[x][y][z];
        x--, y = p.first, z = p.second;
    }
    cout << "YES\n";
    for (int i=n-1; i>=0; i--)
        cout << v[i].first << ' ' << v[i].second << '\n';
    return 0;
}