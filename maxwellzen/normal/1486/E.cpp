#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define F first
#define S second
int n, m, dist[200001], a, b, c, w, w2, temp;
vpi adj[200001];
priority_queue<pi> pq;
pi cur;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) dist[i]=INT_MAX;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a-1].pb(mp(b-1, w));
        adj[b-1].pb(mp(a-1, w));
    }
    dist[0]=0;
    pq.push(mp(0, 0));
    while (! pq.empty()) {
        cur = pq.top();
        pq.pop();
        a = cur.S;
        if (vis[a]) continue;
        vis[a]=true;
        dist[a]=min(dist[a], -cur.F);
        for (auto nb : adj[a]) {
            b = nb.F ; w = nb.S;
            for (auto nb2 : adj[nb.F]) {
                c = nb2.F; w2 = nb2.S;
                if (vis[c]) continue;
                temp = dist[a] + (w+w2)*(w+w2);
                if (temp < dist[c]) {
                    pq.push(mp(-temp, c));
                    dist[c] = temp;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i]==INT_MAX) cout << -1 << ' ';
        else cout << dist[i] << ' ';
    }
    cout << endl;
}