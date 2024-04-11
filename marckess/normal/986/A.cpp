#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;
bitset<MX> bs[105];
int dist[105][MX], a[MX], c[MX];
int n, m, u, v, s, k, res[MX];
vi adj[MX];
queue<int> q, t;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m >> k >> s;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        bs[a[i]][i] = 1;
        c[i] = 1; 
    }

    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        q.push(i);
        t.push(a[i]);
    }

    while (q.size()) {
        int u = q.front(); q.pop();
        int w = t.front(); t.pop();

        for (int v : adj[u]) {
            if (!bs[w][v]) {
                bs[w][v] = 1;
                dist[w][v] = dist[w][u] + 1;
                
                if (c[v] < s) {
                    c[v]++;
                    res[v] += dist[w][v];
                }

                q.push(v);
                t.push(w);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}