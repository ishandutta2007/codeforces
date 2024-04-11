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

const int MAXN = 405;

int n, m, mat[MAXN][MAXN], mat2[MAXN][MAXN];
int pre[MAXN][MAXN], pre2[MAXN][MAXN];
int ans;

void count() {
    rep(i, n)
        rep(j, m)
            pre[i+1][j+1] = pre[i][j] + mat[i][j];

    rep(i, n)
        rep(j, m)
            pre2[i][j+1] = pre2[i][j] + mat[i][j];

    rep(i, n)
        rep(j, m)
            if (!mat[i][j])
                for (int k=1; i+k<n && j-k>=0; k++) {
                    if (mat[i+k][j] || mat[i][j-k]) break;
                    if (pre[i+k+1][j+1]-pre[i+1][j-k+1]) continue;
                    ans++;
                }

    rep(i, n)
        rep(j, m)
            if (!mat[i][j])
                for (int k=1; i+k<n && j-k>=0 && j+k<m; k++) {
                    if (mat[i+k][j-k] || mat[i+k][j+k]) break;
                    if (pre2[i+k][j+k+1]-pre2[i+k][j-k+1]) continue;
                    ans++;
                }
}

void rot() {
    memset(mat2, 0, sizeof(mat2));
    rep(i, n)
        rep(j, m)
            mat2[j][n-1-i] = mat[i][j];
    memcpy(mat, mat2, sizeof(mat2));
    swap(n, m);
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    rep(i, n)
        rep(j, m) {
            char c; cin >> c;
            mat[i][j] = c-'0';
        }

    rep(i, 4) {
        count();
        rot();
    }
    cout << ans << '\n';
    return 0;
}