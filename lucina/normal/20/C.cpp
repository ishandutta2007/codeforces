#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct State {
    int nod, from;
    long long distance;

    State (int nod, int from ,int distance) : nod (nod), from  (from) , distance (distance) {}

    bool operator < (const State & o) const {
        return distance > o.distance;
    }
};

priority_queue<State> pq;
long long dist[N];
bool vis[N];
int parent[N];
const long long inf = 1e17;

vector<pair< int, int>> adj[N];

int main () {
    int n, m;

    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= m ; ++ i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    fill(dist + 1 , dist + 1 + n, inf);

    dist[1] = 0;
    priority_queue<State> pq;
    pq.push(State(1,  0, 0));

    while(!pq.empty()) {
        State cur = pq.top();
        pq.pop();
        if (vis[cur.nod]) continue;
        vis[cur.nod] = true;
        parent[cur.nod] = cur.from;

        for (auto &it : adj[cur.nod]) {
            if (!vis[it.first] && dist[it.first] > dist[cur.nod] + it.second) {
                dist[it.first] = dist[cur.nod] + it.second;
                pq.push(State(it.first, cur.nod, dist[it.first]));
            }
        }
    }
    vector<int> path;

    int now = n;
    do {
        path.push_back(now);
        now = parent[now];
    }while(now > 0);

    if (dist[n] == inf) return !printf("-1");

    for (auto it = path.rbegin(); it != path.rend () ; ++ it)
        printf("%d ", *it);
}