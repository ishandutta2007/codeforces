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

const int MOD = 1e6 + 3;

int n, m;
vector<vector<int> > mat;
int ans = 1;

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    mat.resize(n, vector<int>(m));
    rep(i, n)
        rep(j, m) {
            char c; cin >> c;
            if (c == '.') mat[i][j] = 0;
            else mat[i][j] = c-'0';
        }

    rep(j, m) {
        int x = -1;
        rep(i, n)
            if (mat[i][j]) {
                int y = (mat[i][j] == 1 || mat[i][j] == 4) ^ (i&1);
                if (x == -1) x = y;
                else if (x != y) {
                    cout << 0;
                    return 0;
                }
            }
        if (x == -1) ans = (ans*2)%MOD;
    }

    rep(i, n) {
        int x = -1;
        rep(j, m)
            if (mat[i][j]) {
                int y = (mat[i][j] == 1 || mat[i][j] == 2) ^ (j&1);
                if (x == -1) x = y;
                else if (x != y) {
                    cout << 0;
                    return 0;
                }
            }
        if (x == -1) ans = (ans*2)%MOD;
    }

    cout << ans << '\n';
    return 0;
}