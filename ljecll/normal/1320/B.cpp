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
int dist[MAXN];
vi edge[MAXN];
queue<int> q;
vi path;
pii ans;
int flag[MAXN];

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    FOR(i, 0, M)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edge[v].PB(u);
    }
    cin >> K; path.resize(K);
    FOR(i, 0, K)
    {
        cin >> path[i];
        path[i]--;
    }
    FOR(i, 0, N) dist[i] = INF;
    dist[path.back()] = 0;
    q.push(path.back());
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
    // FOR(i, 0, N)
    // {
    //     cerr << "dist " << i << " = " << dist[i] << endl;
    // }
    FOR(u, 0, N)
    {
        //see if it's unique or not!
        if (dist[u] == INF) continue;
        int n = 0;
        for (int v : edge[u])
        {
            if (dist[v] == dist[u] + 1) flag[v]++;
        }
        // if (flag[u])
        // {
        //     cerr << "flag" << u << endl;
        // }
    }
    //minimum # of times it co ulda reacted: it only reacts if u not take shortest paht
    FOR(i, 0, K - 1)
    {
        int u = path[i], v = path[i + 1];
        if (dist[u] - 1 != dist[v]) ans.fi++;
        ans.se++;
        // cerr << dist[u] << ' ' << dist[v] << endl;
        if (dist[u] - 1 == dist[v] && flag[u] == 1)
        {
            // cerr << "fail " << u << ' ' << v << endl;
            ans.se--;
        }
    }
    cout << ans.fi << ' ' << ans.se << '\n';
    return 0;
    //max # of times it coulda reacted: it can react if it's not true that you took shortest paht and its onlys hortest path
}