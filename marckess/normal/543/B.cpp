#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 3005;
vi adj[MX];
int n, m, u, v, s[2], t[2], l[2];
int dist[MX][MX];

void bfs (int s, int dist[]) {
    for (int i = 1; i <= n; i++)
        dist[i] = -1;

    queue<int> q;
    q.push(s);

    dist[s] = 0;

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int obtRes () {
    int mn = 1e9;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a = dist[s[0]][i] + dist[i][j] + dist[j][t[0]];
            int b = dist[s[1]][i] + dist[i][j] + dist[j][t[1]];

            if (a <= l[0] && b <= l[1])
                mn = min(mn, a + b - dist[i][j]); 
        }
    }

    return mn;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m; 

    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < 2; i++)
        cin >> s[i] >> t[i] >> l[i];

    for (int i = 1; i <= n; i++)
        bfs(i, dist[i]);

    if (dist[s[0]][t[0]] > l[0] || dist[s[1]][t[1]] > l[1]) {
        cout << -1 << endl;
        return 0;
    }

    int mn = dist[s[0]][t[0]] + dist[s[1]][t[1]];

    mn = min(mn, obtRes());
    swap(s[1], t[1]);
    mn = min(mn, obtRes());

    cout << m - mn << endl;

    return 0;
}