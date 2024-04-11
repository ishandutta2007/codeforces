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

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 10;
const int INF = 1e9;

int shape[4][3] = {{7, 2, 2}, {4, 7, 4}, {2, 2, 7}, {1, 7, 1}};
int n, m;
int dp[MAXN][1<<MAXN][1<<MAXN];
pii nxt[MAXN][1<<MAXN][1<<MAXN];
vector<pii> par[MAXN][1<<MAXN][1<<MAXN];

int state[3];
vector<pii> v;

char mat[MAXN][MAXN];

int cnt;
void dfs(int cur, int num, int r, int j1, int k1) {
    cnt++;
    if (cur+2 >= m) {
        if (num+sz(v) > dp[r+1][state[1]][state[2]])
            dp[r+1][state[1]][state[2]] = num+sz(v), par[r+1][state[1]][state[2]] = v, nxt[r+1][state[1]][state[2]] = pii(j1, k1);
    } else {
        for (int i=0; i<4; i++) {
            bool b = 1;
            for (int j=0; j<3; j++)
                if ((shape[i][j]<<cur) & state[j] & (7<<cur)) {
                    b = 0; break;
                }
            if (b) {
                v.push_back(pii(cur, i));
                for (int j=0; j<3; j++) state[j] ^= shape[i][j]<<cur;
                dfs(cur+1, num, r, j1, k1);
                for (int j=0; j<3; j++) state[j] ^= shape[i][j]<<cur;
                v.pop_back();
            }
        }
        dfs(cur+1, num, r, j1, k1);
    }
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    if (n<=2 || m<=2) {
        cout << "0\n";
        rep(i, n) {
            rep(j, m) cout << '.';
            cout << '\n';
        }
        return 0;
    }

    for (int i=2; i<n; i++)
        for (int j=0; j<1<<m; j++)
            for (int k=0; k<1<<m; k++) {
                state[0] = j, state[1] = k, state[2] = 0;
                v.clear();
                dfs(0, dp[i][j][k], i, j, k);
            }

    int ans=-1, _i = n, _j, _k;
    for (int j1=0; j1<1<<m; j1++)
        for (int k1=0; k1<1<<m; k1++)
            if (dp[n][j1][k1]>ans)
                ans = dp[n][j1][k1], _j = j1, _k = k1;

    rep(i, n)
        rep(j, m)
            mat[i][j] = '.';
    char cur = 'A';

    while (_i>2) {
        rep(ii, par[_i][_j][_k].size()) {
            pii p = par[_i][_j][_k][ii];
            for (int i1=0; i1<3; i1++)
                for (int j1=0; j1<3; j1++)
                    if (shape[p.se][i1]&1<<j1)
                        mat[_i+i1-3][p.fi+j1] = cur;
            cur++;
        }
        int j1 = nxt[_i][_j][_k].fi, k1 = nxt[_i][_j][_k].se;
        _i--, _j = j1, _k = k1;
    }

    cout << ans << '\n';
    rep(i, n) {
        rep(j, m) cout << mat[i][j];
        cout << '\n';
    }
    return 0;
}