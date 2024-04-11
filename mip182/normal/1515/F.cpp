#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}
#define in(x); { for (auto &to : x) cin >> to;}
#define out(x); { for (auto &to : x) cout << to << " "; cout << '\n'; }

template<class T>
bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }

template<class T>
bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const ll INFLL = 1e18;
const int MAXN = 3e5 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;
int a[MAXN];
vvpii g;
int par[MAXN], ranks[MAXN];
ll cost[MAXN];

void make_set(int s) {
    par[s] = s;
    ranks[s] = 0;
    cost[s] = a[s];
}

int find_set(int s) {
    if (par[s] == s)
        return s;
    return par[s] = find_set(par[s]);
}

int n, m, x;

void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u != v) {
        if (ranks[u] < ranks[v])
            swap(u, v);
        par[v] = u;
        if (ranks[u] == ranks[v])
            ranks[u]++;
        cost[u] += cost[v] - x;
    }
}

int tin[MAXN];
int tout[MAXN];
stack<pii > st;
int times = 0;

bool check(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void dfs(int s, int p) {
    tin[s] = times++;
    for (auto to:g[s]) {
        if (to.fi == p)
            continue;
        dfs(to.fi, s);
        ll c_s = cost[find_set(s)];
        ll c_to = cost[find_set(to.fi)];
        if (c_s + c_to >= x) {
            union_sets(s, to.fi);
            cout << to.se + 1 << '\n';
        } else
            st.push({to.fi, to.se});
    }
    tout[s] = times++;
    while (!st.empty()) {
        if (check(s, st.top().fi)) {
            int v = st.top().fi;
            ll c_s = cost[find_set(s)];
            ll c_to = cost[find_set(v)];
            if (c_s + c_to >= x) {
                cout << st.top().se + 1 << '\n';
                st.pop();
                union_sets(s, v);
            } else
                break;
        } else
            break;
    }
}

void solve() {
    cin >> n >> m >> x;
    g = vvpii(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    if (sum < 1ll * (n - 1) * x) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        make_set(i);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (find_set(u) == find_set(v))
            continue;
        union_sets(u, v);
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    for (int i = 0; i < n; i++)
        make_set(i);
//    cout<<"ahha\n";
//    for (int i = 0; i < n; i++)
//        cout << cost[i] << " ";
//    cout << '\n';
    dfs(0, 0);
}

int main() {
#ifdef Mip182
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int _t;
    _t = 1;
//    cin>>_t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}