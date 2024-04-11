#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
    if (a > b) a = b;
}

template<class T, class U>
void ckmax(T &a, U b)
{
    if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const int MAXN = 200013;

int N, K;
vi edge[MAXN];
int depth[MAXN], subtree[MAXN];
ll val[MAXN];
ll ans;

void dfs(int u, int p)
{
    subtree[u] = 1;
    for (int v : edge[u])
    {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        subtree[u] += subtree[v];
    }
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> K;
    FOR(i, 0, N - 1)
    {
        int u, v;
        cin >> u >> v; u--; v--;
        edge[u].PB(v);
        edge[v].PB(u);
    }
    dfs(0, N);
    FOR(i, 0, N)
    {
        val[i] = depth[i] - subtree[i] + 1;
    }
    sort(val, val + N, greater<ll>());
    FOR(i, 0, K)
    {
        ans += val[i];
    }
    cout << ans << '\n';
    return 0;
}