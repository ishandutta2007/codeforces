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

const int MAXN = 400013;

int N, S, M, ans, n;
int val[MAXN], arr[MAXN], sorted[MAXN];
vi moves[MAXN];
vi cyc[MAXN];
bitset<MAXN> vis;
vi compress;
int freq[MAXN];
pii range[MAXN];
vi edge[MAXN];
vi tour;
int ind[MAXN];

int indexof(vi &v, int x)
{
    return UB(ALL(v), x) - v.begin() - 1;
}
void dfs(int u)
{
    while(!edge[u].empty())
    {
        int v = edge[u].back();
        edge[u].pop_back();
        dfs(v);
    }
    tour.PB(u);
}
void solve()
{
    //k = 0 or min(M, s - n)
    int k = min(M, S - n);
    if (k <= 2)
    {
        ans = M;
        FOR(i, 0, M)
        {
            moves[i] = cyc[i];
        }
    }
    else
    {
        ans = M - k + 2;
        //0...M-k-1. M-k. M-k+1.
        FOR(i, 0, M - k)
        {
            moves[i] = cyc[i];
        }
        FOR(i, M - k, M)
        {
            moves[M - k].insert(moves[M - k].end(), ALL(cyc[i]));
            moves[M - k + 1].PB(cyc[i][0]);
        }
        reverse(ALL(moves[M - k + 1]));
    }
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> S;
    FOR(i, 0, N)
    {
        cin >> val[i];
        compress.PB(val[i]);
    }
    sort(ALL(compress));
    compress.erase(unique(ALL(compress)), compress.end());
    FOR(i, 0, N)
    {
        val[i] = indexof(compress, val[i]);
        sorted[i] = val[i];
    }
    sort(sorted, sorted + N);
    FOR(i, 0, N)
    {
        if (val[i] == sorted[i])
        {
            vis[i] = true;
            arr[i] = i;
            continue;
        }
        edge[i].PB(val[i] + N);
        edge[sorted[i] + N].PB(i);
        // cerr << i << " " << val[i] + N << endl;
        // cerr << sorted[i] + N << " " << i << endl;
    }
    FOR(i, 0, N)
    {
        if (vis[i]) continue;
        tour.clear();
        dfs(i);
        reverse(ALL(tour));
        // for (int x : tour)
        // {
        //     cerr << x << ' ';
        // }
        // cerr << endl;
        for (int j = 0; j + 2 < SZ(tour); j += 2)
        {
            int u = tour[j];
            int v = tour[j + 2];
            arr[u] = v;
            // cerr << u << " -> " << v << endl;
        }
        tour.clear();
    }
    // FOR(i, 0, N)
    // {
    //     cerr << arr[i] << ' ';
    // }
    // cerr << endl;
    vis.reset();
    //GET THE ARRAY.
    FOR(i, 0, N)
    {
        if (vis[i]) continue;
        if (arr[i] == i)
        {
            continue;
        }
        cyc[M].PB(i);
        do
        {
            vis[cyc[M].back()] = true;
            cyc[M].PB(arr[cyc[M].back()]);
        }
        while(cyc[M].back() != i);
        cyc[M].pop_back();
        M++;
    }
    FOR(i, 0, M)
    {
        n += SZ(cyc[i]);
    }
    if (S < n)
    {
        cout << "-1\n";
        return 0;
    }
    solve();
    assert(ans == min(M, max(2, 2 + M - S + n)));
    cout << ans << '\n';
    FOR(i, 0, ans)
    {
        cout << SZ(moves[i]) << '\n';
        for (int x : moves[i])
        {
            cout << x + 1 << " \n"[x == moves[i].back()];
        }
    }
    //the min s is just the # of numbers out of place, that's all.
    //assign the #s so that the # of cycles is minimized.
}