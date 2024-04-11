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

const int MAXN = 105;

int n, m, k, mat[MAXN][MAXN], mat2[MAXN][MAXN], pat[MAXN], ans = 1e9;

void rot() {
    rep(i, n)
        rep(j, m)
            mat2[j][i] = mat[i][j];
    memcpy(mat, mat2, sizeof(mat2));
    swap(n, m);
}

void go() {
    int cur = 0;
    rep(i, n) {
        int a = 0, b = 0;
        rep(j, m)
            if (mat[i][j] == pat[j]) a++;
            else b++;
        cur += min(a, b);
    }
    ans = min(ans, cur);
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;
    rep(i, n)
        rep(j, m)
            cin >> mat[i][j];

    if (n <= k) {
        rot();
        rep(i, 1<<m) {
            rep(j, m)
                pat[j] = bool(i&1<<j);
            go();
        }
    } else {
        rep(i, k+1) {
            rep(j, m)
                pat[j] = mat[i][j];
            go();
        }
    }

    if (ans>k) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}