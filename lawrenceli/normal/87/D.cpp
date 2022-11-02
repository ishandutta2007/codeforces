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

const int MAXN = 100100;

int n;
struct data {
    int a, b, d, i;
} ar[MAXN];
pii par[MAXN];

vector<int> adj[MAXN];
int dep[MAXN];

pii getpar(int a) { return par[a].fi == a ? par[a] : par[a] = getpar(par[a].fi); }
void merge(int a, int b) {
    pii pa = getpar(a), pb = getpar(b);
    a = pa.fi, b = pb.fi;
    par[a].fi = b;
    par[b].se += par[a].se;
}

void dfs(int cur, int p=-1) {
    dep[cur] = p == -1 ? 0 : dep[p]+1;
    rep(i, adj[cur].size()) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        dfs(nxt, cur);
    }
}

bool cmp(data d1, data d2) {
    return d1.d != d2.d ? d1.d < d2.d : dep[d1.a] > dep[d2.a];
}

ll num[MAXN];

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n-1) {
        cin >> ar[i].a >> ar[i].b >> ar[i].d;
        ar[i].a--, ar[i].b--;
        ar[i].i = i+1;
        adj[ar[i].a].push_back(ar[i].b);
        adj[ar[i].b].push_back(ar[i].a);
    }

    rep(i, n) par[i] = pii(i, 1);
    dfs(0);
    rep(i, n-1)
        if (dep[ar[i].a] < dep[ar[i].b])
            swap(ar[i].a, ar[i].b);

    sort(ar, ar+n-1, cmp);

    for (int i=0, j; i<n-1; i=j) {
        for (j=i; j<n-1 && ar[j].d == ar[i].d; j++)
            num[ar[j].i] = getpar(ar[j].a).se, merge(ar[j].a, ar[j].b);
        for (int k=i; k<j; k++)
            num[ar[k].i] = 2*ll(num[ar[k].i])*(getpar(ar[k].a).se-num[ar[k].i]);
    }

    vector<int> ans;
    ll ma = 0;
    for (int i=1; i<n; i++)
        if (num[i] > ma)
            ans.clear(), ans.push_back(i), ma = num[i];
        else if (num[i] == ma) ans.push_back(i);

    cout << ma << ' ' << ans.size() << '\n';
    rep(i, ans.size()) cout << ans[i] << ' ';
    return 0;
}