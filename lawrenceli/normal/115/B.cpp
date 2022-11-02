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

const int MAXN = 155;
const int INF = 1e9;

int n, m;
char mat[MAXN][MAXN];
int lt[MAXN], rt[MAXN], dp[MAXN][MAXN];

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    rep(i, n)
        rep(j, m)
            cin >> mat[i][j];

    rep(i, n) {
        lt[i] = m, rt[i] = -1;
        rep(j, m)
            if (mat[i][j] == 'W')
                lt[i] = min(lt[i], j), rt[i] = max(rt[i], j);
    }

    while (n>0)
        if (lt[n-1] == m) n--;
        else break;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    rep(i, MAXN)
        rep(j, MAXN)
            dp[i][j] = INF;
    dp[0][0] = 0;

    rep(i, n)
        rep(j, m) {
            if (i&1) { //left
                if (rt[i] > j) continue;
                for (int k=0; k<=min(lt[i], j); k++)
                    dp[i+1][k] = min(dp[i+1][k], dp[i][j]+j-k+1);
            } else { //right
                if (lt[i] < j) continue;
                for (int k=max(rt[i], j); k<m; k++)
                    dp[i+1][k] = min(dp[i+1][k], dp[i][j]+k-j+1);
            }
        }

    int ans = INF;
    rep(i, m)
        ans = min(ans, dp[n][i]-1);
    cout << ans << '\n';
    return 0;
}