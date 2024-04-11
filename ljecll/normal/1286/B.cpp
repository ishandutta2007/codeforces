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
#define MAXN 2013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, R, T;
int parent[MAXN], val[MAXN];
vi edge[MAXN];
int st[MAXN], ft[MAXN], rev[MAXN];
ll ans[MAXN];

void dfs(int u)
{
    // cerr << u << ' ' << T << endl;
    st[u] = T; ft[u] = T; rev[T] = u;
    T++;
    for (int v : edge[u])
    {
        dfs(v);
        ft[u] = ft[v];
    }
}
void solve(int u)
{
    for (int v : edge[u]) solve(v);
    if (val[u] > ft[u] - st[u])
    {
        cout << "NO\n";
        exit(0);
    }
    vl compress;
    FOR(i, st[u] + 1, ft[u] + 1)
    {
        compress.PB(ans[rev[i]] * N + i);
    }
    // cerr << "SOLVE " << u << endl;
    sort(ALL(compress));
    FOR(i, st[u] + 1, ft[u] + 1)
    {
        ans[rev[i]] = LB(ALL(compress), ans[rev[i]] * N + i) - compress.begin();
        // cerr << ans[rev[i]] << endl;
        ans[rev[i]]++; ans[rev[i]] *= 2;
        // cerr << "ASSIGN " << rev[i] << ' ' << ans[rev[i]] << endl;
    }
    ans[u] = 2 * val[u] + 1;
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    FOR(i, 0, N)
    {
        cin >> parent[i] >> val[i]; parent[i]--;
        if (parent[i] == -1)
        {
            parent[i] = N;
            R = i;
        }
        else
        {
            edge[parent[i]].PB(i);
        }
    }
    dfs(R);
    solve(R);
    cout << "YES\n";
    FOR(i, 0, N)
    {
        ans[i]++;
        cout << ans[i] << " \n"[i == N - 1];
    }
    return 0;
    //solve your subtree lol.
}