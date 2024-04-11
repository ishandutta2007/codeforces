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

const int MAXN = 1005;

int n, k, ar[10][MAXN], ind[10][MAXN], dp[MAXN], ans;

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k;
    for (int i=0; i<k; i++)
        for (int j=0; j<n; j++) {
            cin >> ar[i][j];
            ind[i][ar[i][j]] = j;
        }

    for (int i=1; i<=n; i++) dp[i] = 1;

    for (int i=0; i<n; i++) {
        int x = ar[0][i];
        for (int j=1; j<=n; j++)
            if (x != j) {
                bool b = 1;
                for (int i1=0; i1<k; i1++)
                    if (ind[i1][x]<ind[i1][j]) b = 0;
                if (!b) continue;
                dp[x] = max(dp[x], dp[j]+1);
            }
        ans = max(ans, dp[x]);
    }

    cout << ans << '\n';
    return 0;
}