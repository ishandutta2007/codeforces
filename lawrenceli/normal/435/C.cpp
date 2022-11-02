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

int n, ar[MAXN], y[MAXN];
char mat[MAXN][MAXN];

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n) {
        cin >> ar[i];
        if (i&1) y[i+1] = y[i] - ar[i];
        else y[i+1] = y[i] + ar[i];
    }
    int mi = 0;
    rep(i, n+1) {
        y[i] = -y[i];
        mi = min(mi, y[i]);
    }
    rep(i, n+1) y[i] -= mi;
    int ma = 0;
    rep(i, n+1) ma = max(ma, y[i]);

    rep(i, MAXN)
        rep(j, MAXN)
            mat[i][j] = ' ';

    int curx = 0, cury = y[0]-1;
    rep(i, n) {
        if (i&1) {
            rep(j, ar[i])
                mat[cury++][curx++] = '\\';
            cury--;
        } else {
            rep(j, ar[i])
                mat[cury--][curx++] = '/';
            cury++;
        }
    }
    rep(i, ma) {
        rep(j, curx)
            cout << mat[i][j];
        cout << '\n';
    }
    return 0;
}