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

const int MAXN = 5e5 + 13;
const int INF = 1e9 + 7;

int N, M;
int dsu[MAXN];
vector<pair<int, pii> > edges;
vi ans;
int prod = 1;

int get(int u)
{
    return (u == dsu[u] ? u : dsu[u] = get(dsu[u]));
}
bool merge(int u, int v)
{
    u = get(u);
    v = get(v);
    if (u == v) return false;
    dsu[u] = v;
    return true;
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> M >> N;
    iota(dsu, dsu + N + 1, 0);
    FOR(i, 0, M)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int x;
            cin >> x;
            edges.PB({i, {0, x}});
        }
        else
        {
            int x, y;
            cin >> x >> y;
            edges.PB({i, {x, y}});
        }
    }
    for (auto e : edges)
    {
        int u = e.se.fi, v = e.se.se;
        if (merge(u, v))
        {
            ans.PB(e.fi);
            prod += prod; if (prod >= INF) prod -= INF;
        }
    }
    cout << prod << ' ' << SZ(ans) << '\n';
    FOR(i, 0, SZ(ans))
    {
        cout << ans[i] + 1 << " \n"[i == SZ(ans) - 1];
    }
    return 0;
}