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
const int INF = 1000000007;

int N, M, K;
bitset<MAXN> flag;
vi edge[MAXN];
int dist[MAXN];
int ds[MAXN];
vi nodes[MAXN];
int ans;
int best = -INF, best1 = -INF;

void bfs(int s)
{
    queue<int> q; q.push(s);
    FOR(i, 0, N)
    {
        dist[i] = INF;
    }
    dist[s] = 0;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v : edge[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M >> K;
    FOR(i, 0, K)
    {
        int x; cin >> x; x--;
        flag[x] = true;
    }
    FOR(i, 0, M)
    {
        int u, v; cin >> u >> v; u--; v--;
        edge[u].PB(v);
        edge[v].PB(u);
    }
    bfs(0);
    FOR(i, 0, N)
    {
        ds[i] = dist[i];
        // cerr << ds[i] << ' ';
    }
    // cerr << endl;
    bfs(N - 1);
    FOR(i, 0, N)
    {
        nodes[dist[i]].PB(i);
    }
    FOR(i, 0, N)
    {
        for (int u : nodes[i])
        {
            if (!flag[u]) continue;
            if (dist[u] > best)
            {
                best1 = best;
                best = dist[u];
            }
            else if (dist[u] > best1)
            {
                best1 = dist[u];
            }
        }
        for (int u : nodes[i])
        {
            if (!flag[u]) continue;
            // cerr << u << ' ' << ds[u] + 1 + (best == dist[u] ? best1 : best) << endl;
            ckmax(ans, ds[u] + 1 + (best == dist[u] ? best1 : best));
        }
    }
    // cerr << best << ' ' << best1 << endl;
    ckmin(ans, ds[N - 1]);
    cout << ans << '\n';
    return 0;
}