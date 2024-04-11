#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int64 n, m, L, s, t;
int U[maxn], V[maxn];
int64 W[maxn];

int bad[maxn], tot;
vector<pii> adj[maxn];

int64 dis[maxn];

int64 solve(int64 x){
    int64 len = x / max(tot, 1), rem = x % max(tot,1);

    for (int i = 0; i < tot; ++i)
        W[bad[i]] = len + (rem-- > 0);

    for (int i = 0; i < n; ++i) dis[i] = oo;

    set<pair<int64,int>> heap;
    dis[s] = 0;
    heap.insert({0, s});

    while (!heap.empty()){
        auto cur = *heap.begin(); heap.erase(heap.begin());
        int64 d = cur.first;
        int u = cur.second;

        if (u == t) break;

        for (auto e : adj[u]){
            int v = e.first;

            if (d + W[e.second] < dis[v]){
                heap.erase({dis[v], v});
                dis[v] = d + W[e.second];
                heap.insert({dis[v], v});
            }
        }
    }

    return dis[t];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    cin >> n >> m >> L >> s >> t;

    for (int i = 0; i < m; ++i){
        cin >> U[i] >> V[i] >> W[i];
        if (!W[i]) bad[tot++] = i;
        adj[U[i]].push_back({V[i], i});
        adj[V[i]].push_back({U[i], i});
    }

    int64 lo = tot, hi = m * L + 1;

    if (solve(lo) > L || solve(hi) < L){
        cout << "NO" << endl;
        return 0;
    }

    while (lo + 1 < hi){
        int64 mid = (lo + hi) >> 1;
        if (solve(mid) <= L)
            lo = mid;
        else
            hi = mid;
    }

    solve(lo);

    cout << "YES" << endl;
    for (int i = 0; i < m; ++i)
        cout << U[i] << " " << V[i] << " " << W[i] << endl;

    return 0;
}