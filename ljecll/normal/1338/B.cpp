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

const int MAXN = 100013;

int N;
vi edge[MAXN];
int dsu[MAXN];
int depth[MAXN];
int MN, MX;

int get(int u)
{
    return (u == dsu[u] ? u : dsu[u] = get(dsu[u]));
}
void merge(int u, int v)
{
    u = get(u);
    v = get(v);
    dsu[u] = v;
    return;
}
void dfs(int u, int p)
{
    for (int v : edge[u])
    {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}
bool check1()
{
    FOR(i, 0, N)
    {
        if (SZ(edge[i]) == 1 && (depth[i] % 2)) return false;
    }
    return true;
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    int S = -1;
    FOR(i, 0, N - 1)
    {
        int u, v;
        cin >> u >> v; u--; v--;
        edge[u].PB(v);
        edge[v].PB(u);
    }
    FOR(i, 0, N)
    {
        if (SZ(edge[i]) == 1) S = i;
    }
    MX = N - 1;
    FOR(u, 0, N)
    {
        int ch = 0;
        for (int v : edge[u])
        {
            if (SZ(edge[v]) == 1) ch++;
        }
        MX -= max(0, ch - 1);
    }
    dfs(S, N);
    //check if 1
    if (check1())
    {
        MN = 1;
    }
    else
    {
        MN = 3;
    }
    //minimum is always 1, 2, or 3.
    //check if 1 works. otherwise, check if 2 works.
    cout << MN << ' ' << MX << '\n';
    return 0;
}