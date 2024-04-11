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

int mult(int a, int b) {
    ll ret = ll(a)*b;
    if (ret>MAXN) return MAXN;
    return ret;
}

int n, k, d;
int ans[MAXN][MAXN], ar[MAXN], num;

void dfs(int cur) {
    if (num == n) return;
    if (cur == d) {
        rep(i, d) ans[i][num] = ar[i];
        num++;
    } else {
        for (int i=1; i<=k; i++) {
            if (num == n) return;
            ar[cur] = i;
            dfs(cur+1);
        }
    }
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k >> d;
    int x = 1;
    rep(i, d) x = mult(x, k);

    if (n>x) {
        cout << -1;
        return 0;
    }

    dfs(0);

    rep(i, d) {
        rep(j, n)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}