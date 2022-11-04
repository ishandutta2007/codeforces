#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
 
const int MX = 200005;
int n, u, v, dist[MX], mx[MX], a, b, c, dia, deg[MX];
vi adj[MX];
bitset<MX> ex;

typedef tuple<int, int, int> iii;
vector<iii> res;
ll sum = 0;

void dfs (int u, int p, int d, int o) {
    if (dist[u] < d) {
        dist[u] = d;
        mx[u] = o;
    }

    for (int v : adj[u]) {
        if (v == p)
            continue;
        dfs(v, u, d + 1, o);
    }
}

queue<int> q;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        deg[u]++;
        deg[v]++;
    }

    dfs(1, 1, 0, 1);
    a = 2;

    for (int i = 3; i <= n; i++)
        if (dist[i] > dist[a])
            a = i;

    fill(dist, dist+MX, 0);

    dfs(a, a, 0, a);

    b = 1;
    for (int i = 2; i <= n; i++)
        if (dist[i] > dist[b])
            b = i;

    dfs(b, b, 0, b);
    dia = dist[b];

    ex.set();
    for (int i = 1; i <= n; i++) {
        if (i != a && i != b && deg[i] == 1) {
            q.push(i);
            ex[i] = 0;
        }
    }

    while (q.size()) {
        int u = q.front();
        q.pop();

        res.emplace_back(u, mx[u], u);
        sum += dist[u];

        for (int v : adj[u]) {
            deg[v]--;
            if (ex[v] && deg[v] == 1) {
                ex[v] = 0;
                q.push(v);
            }
        }
    }

    while (dia) {
        sum += dia--;
        res.emplace_back(a, b, b);
        ex[b] = 0;
        for (int v : adj[b])
            if (ex[v])
                b = v;
    }

    cout << sum << endl;
    for (auto x : res) {
        tie(a, b, c) = x;
        cout << a << " " << b << " " << c << endl;
    }

    return 0;
}