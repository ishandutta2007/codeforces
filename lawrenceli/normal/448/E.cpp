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

const int MAXF = 10000;
const int MAX = 100000;
const int MAXLG = 18;

ll X, K;
vector<ll> vdiv, vd[MAXF];
map<ll, int> ind;
int cnt;
vector<ll> dp[MAXF][MAXLG];

void init() {
    for (int i=1; ll(i)*i<=X; i++)
        if (X%i == 0) vdiv.push_back(i);
    for (int i=sz(vdiv)-1; i>=0; i--)
        if (ll(vdiv[i])*vdiv[i] != X)
            vdiv.push_back(X/vdiv[i]);

    rep(i, sz(vdiv))
        ind[vdiv[i]] = cnt++;
    rep(i, sz(vdiv)) {
        int d = ind[vdiv[i]];
        rep(j, i+1)
            if (vdiv[i]%vdiv[j] == 0)
                vd[d].push_back(vdiv[j]);
    }
}

vector<ll> add1(vector<ll> v) {
    vector<ll> ret;
    rep(i, v.size()) {
        int n = ind[v[i]];
        rep(j, vd[n].size()) {
            ret.push_back(vd[n][j]);
            if (ret.size() == MAX) break;
        }
        if (ret.size() == MAX) break;
    }
    return ret;
}

vector<ll> mult2(vector<ll> v, ll x, int c) {
    vector<ll> ret;
    rep(i, v.size()) {
        int n = ind[v[i]];
        rep(j, dp[n][c].size()) {
            ret.push_back(dp[n][c][j]);
            if (ret.size() == MAX) break;
        }
        if (ret.size() == MAX) break;
    }
    return ret;
}

int exp(ll x, int n, int k) {
    if (k == 0) {
        dp[n][0].push_back(x);
        return 1;
    }
    int c = exp(x, n, k/2);
    vector<ll> v = dp[n][c-1];
    v = mult2(v, x, c-1);
    if (k&1) v = add1(v);
    dp[n][c] = v;
    return c+1;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> X >> K;
    if (K == 0) {
        cout << X;
        return 0;
    } else if (X == 1) {
        cout << 1;
        return 0;
    } else if (K > MAX) {
        rep(i, MAX) cout << "1 ";
        return 0;
    }
    init();

    vector<ll> ans;
    rep(i, vdiv.size()) {
        int c = exp(vdiv[i], ind[vdiv[i]], K-1)-1;
        rep(j, dp[i][c].size()) {
            ans.push_back(dp[i][c][j]);
            if (ans.size() == MAX) break;
        }
        if (ans.size() == MAX) break;
    }

    rep(i, ans.size())
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}