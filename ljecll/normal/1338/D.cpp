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
int dp[MAXN][2]; //dp[0] = you didn't take htis node. //dp[1] - you did take this node.
int ans;

void dfs(int u, int p)
{
    if (u)
    {
        edge[u].erase(find(ALL(edge[u]), p));
    }
    for (int v : edge[u])
    {
        dfs(v, u);
    }
    //don't take htis node.
    //that means for all ur chidlren, they can take
    dp[u][0] = SZ(edge[u]);
    int mx1 = -1, mx2 = -1;
    for (int v : edge[u])
    {
        if (dp[v][1] - 1 > mx1)
        {
            mx2 = mx1;
            mx1 = dp[v][1] - 1;
        }
        else if (dp[v][1] - 1 > mx2)
        {
            mx2 = dp[v][1] - 1;
        }
    }
    ckmax(ans, mx1 + mx2 + SZ(edge[u]) + !!(u));
    dp[u][0] += mx1;
    mx1 = 0; mx2 = 0;
    for (int v : edge[u])
    {
        if (dp[v][0] > mx1)
        {
            mx2 = mx1;
            mx1 = dp[v][0];
        }
        else if (dp[v][0] > mx2)
        {
            mx2 = dp[v][0];
        }
    }
    ckmax(ans, mx1 + mx2 + 1);
    dp[u][1] = mx1 + 1;
    //you do take this ndoe in fact.
    ckmax(dp[u][1], dp[u][0]);
}
//dp[x][3] = you didn't take it, and in a subtree, there's at most one node that like you didn't

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    FOR(i, 0, N - 1)
    {
        int u, v;
        cin >> u >> v; u--; v--;
        edge[u].PB(v);
        edge[v].PB(u);
    }
    dfs(0, N);
    cout << ans << '\n';
    return 0;
    //it's almost the max independent set, except i think if you take nodes from two separate subtrees yoyu can't take this?
}