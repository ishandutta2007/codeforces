#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

vector<pii> adj[maxn];
bool dead[maxn];
int64 M, I;

int64 gcd(int64 a, int64 b, int64 &x, int64 &y){
    if (b == 0){
        x = 1, y = 0;
        return a;
    }

    int64 g = gcd(b, a % b, x, y);
    int64 t = y;
    y = x - y * (a / b);
    x = t;

    return g;
}

int64 inverse(int64 a, int64 M){
    int64 x, y;
    int64 g = gcd(a, M, x, y);
    assert(g == 1);
    x %= M;
    if (x < 0) x += M;
    return x;
}

int q[maxn];
int f[maxn];
int sz[maxn];
int mx[maxn];

int centroid(int s){
    // cout << "calc centroid starting from: " << s << endl;
    int t = 1; q[0] = s, f[s] = -1;

    for (int i = 0; i < t; ++i){
        int u = q[i];
        sz[u] = mx[u] = 0;
        // cout << u << " ";
        for (auto e : adj[u]){
            int v = e.first;
            if (dead[v] || f[u] == v)
                continue;
            q[t++] = v;
            f[v] = u;
        }
    }
    // cout << endl;

    for (int i = t - 1; i >= 0; --i){
        int u = q[i];
        sz[u]++;
        int ch = max(mx[u], t - sz[u]);
        // cout << u << " " << mx[u] << " " << sz[u] << endl;
        if (2 * ch <= t) return u;
        sz[f[u]] += sz[u];
        mx[f[u]] = max(mx[f[u]], sz[u]);
    }

    assert(false);
    return -1;
}

map<int64,int64> freq;
int64 pw[maxn];
int64 ipw[maxn];

void dfs1(int s, int p, int64 val, int d){
    freq[val] += 1;

    if (dead[s]) return;

    for (auto e : adj[s]){
        int u = e.first;
        if (u == p) continue;
        dfs1(u, s, (val + e.second * pw[d]) % M, d + 1);
    }
}

int64 dfs2(int s, int p, int64 B, int d){
    int64 answer = freq[(M - B) * ipw[d] % M];

    // cout << "(2)node " << s << " : " << answer << endl;
    // cout << B << endl;

    if (dead[s]) return answer;

    for (auto e : adj[s]){
        int u = e.first;
        if (u == p)continue;
        answer += dfs2(u, s, (B * 10 + e.second) % M, d + 1);
    }

    return answer;
}

int64 go(int s){

    int64 answer = 0;

    freq.clear();
    // cout << "FIRST" << endl;
    for (auto e : adj[s]){
        answer += dfs2(e.first, s, e.second % M, 1);
        dfs1(e.first, s, e.second % M, 1);
    }

    reverse(adj[s].begin(), adj[s].end());

    freq.clear();
    // cout << "SECOND" << endl;
    for (auto e : adj[s]){
        answer += dfs2(e.first, s, e.second % M, 1);
        dfs1(e.first, s, e.second % M, 1);
    }

    return answer;
}

int64 solve(int s){
    int c = centroid(s);

    int64 answer = go(c);
    // cout << "centroid " << c << " : " << answer << endl;

    dead[c] = true;

    for (auto e : adj[c]){
        int u = e.first;
        if(dead[u]) continue;
        answer += solve(u);
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    int n;
    cin >> n >> M;

    I = inverse(10, M);
    pw[0] = ipw[0] = 1;

    for (int i = 1; i < n; ++i){
        pw[i] = pw[i - 1] * 10 % M;
        ipw[i] = ipw[i - 1] * I % M;
    }

    int64 answer = 0;

    for (int i = 0; i < n - 1; ++i){
        int u, v, w;
        cin >> u >> v >> w;

        if (w % M == 0)
            answer += 2;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    answer += solve(0);

    cout << answer << endl;

    return 0;
}