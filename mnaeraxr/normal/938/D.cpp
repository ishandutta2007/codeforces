#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

vector<pair<int,int64>> adj[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int u, v;
        int64 w;
        cin >> u >> v >> w;

        adj[u].push_back({v, 2 * w});
        adj[v].push_back({u, 2 * w});
    }

    for (int i = 1; i <= n; ++i){
        int64 a; cin >> a;
        adj[0].push_back({i, a});
    }

    vector<int64> distance(n+1, oo);

    distance[0] = 0;

    priority_queue<pair<int64,int>> pq;
    pq.push({0, 0});

    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();

        int64 d = -cur.first;
        int u = cur.second;

        if (d > distance[u])
            continue;

        for (auto e : adj[u]){
            int v = e.first;
            int64 c = e.second;

            if (d + c < distance[v]){
                distance[v] = d + c;
                pq.push({-(d+c), v});
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << distance[i] << " ";
    cout << endl;

    return 0;
}