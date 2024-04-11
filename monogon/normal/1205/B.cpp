
#include <bits/stdc++.h>

#define ll long long
using namespace std;

typedef pair<int, int> PII;

const int MAX_N = 1e5 + 5;
int n;
ll a[MAX_N];
int bitcount[60];
vector<int> withbit[60];
vector<int> adj[MAX_N];
bool visited[MAX_N];
int dist[MAX_N];

int dijkstra(int u, int v) {
    fill(visited, visited + n, false);
    fill(dist, dist + n, INT_MAX);
    dist[u] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > q;
    q.push({0, u});
    while(!q.empty()) {
        int w = q.top().second;
        q.pop();

        if(visited[w]) {
            continue;
        }
        if(w == v || dist[w] == INT_MAX) {
            return dist[w];
        }
        visited[w] = true;
        for(int w2 : adj[w]) {
            if((w != u || w2 != v) && !visited[w2] && dist[w] + 1 < dist[w2]) {
                dist[w2] = dist[w] + 1;
                q.push({dist[w2], w2});
            }
        }
    }
    return INT_MAX;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < 60; j++) {
            bitcount[j] += ((a[i] >> j) & 1);
        }
    }
    for(int i = 0; i < 60; i++) {
        if(bitcount[i] >= 3) {
            cout << 3 << endl;
            return 0;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 60; j++) {
            if((a[i] >> j) & 1) {
                withbit[j].push_back(i);
            }
        }
    }
    for(int i = 0; i < 60; i++) {
        if(withbit[i].size() == 2) {
            int j = withbit[i][0];
            int k = withbit[i][1];
            adj[j].push_back(k);
            adj[k].push_back(j);
        }
    }
    int M = INT_MAX;
    for(int i = 0; i < n; i++) {
        for(int j : adj[i]) {
            M = 1 + min(M - 1, dijkstra(i, j));
        }
    }
    cout << (M == INT_MAX ? -1 : M) << endl;
}