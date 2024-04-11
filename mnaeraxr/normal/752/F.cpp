#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200010;

vi adj[maxn];

bool mk[maxn];
int q[maxn], p[maxn], sz[maxn], mc[maxn];
bool team[maxn];

int centroid(int c){
    int b = 0, e = 0;
    q[e++] = c, p[c] = -1, sz[c] = team[c], mc[c] = 0;

    int total = sz[c];

    while (b < e){
        int u = q[b++];
        for (auto v : adj[u]) if (v != p[u] && !mk[v]){
                p[v] = u, sz[v] = team[v], mc[v] = 0, q[e++] = v;
                total += sz[v];
        }
    }

    for (int i = e - 1; ~i; --i){
        int u = q[i];
        int bc = max(total - sz[u], mc[u]);
        if (2 * bc <= total) return u;
        sz[p[u]] += sz[u], mc[p[u]] = max(mc[p[u]], sz[u]);
    }

    assert(false);
    return -1;
}

vector<int> order;

void dfs(int s, int f){
    if (team[s]) order.push_back(s);
    for (auto u : adj[s]){
        if (u == f) continue;
        dfs(u, s);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;

    for (int i = 0; i + 1 < n; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for (int i = 0; i < 2 * k; ++i){
        int u; cin >> u;
        team[u] = true;
    }

    int c = centroid(1);

    dfs(c, -1);

    cout << 1 << endl << c << endl;

    for (int i = 0; i < k; ++i)
        cout << order[i] << " " << order[i + k] << " " << c << endl;

    return 0;
}