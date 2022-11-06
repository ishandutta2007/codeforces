#include <bits/stdc++.h>

using namespace std;
const int N = 2005;
const long long INF = 1e18;
bool vis[2][N];
long long dist[2][N];
bool byl[N][N][2];
long long M[N][N][2];
pair<long long, int> numer[N];
priority_queue<pair<long long, int> >Q;
vector<pair<int, int> >V[N];
vector<int>warstwa[2][N];
int ktoraWarstwa[2][N];
int pozycja[2][N];
int value[N];
int A, B, n, m, a, b, c;
void Dijkstra(int v, int s) {
    for(int i = 1; i <= n; i++) {
        dist[s][i] = INF;
    }
    dist[s][v] = 0;
    Q.push({0, v});
    while(!Q.empty()) {
        int w = Q.top().second;
        Q.pop();
        if(vis[s][w]) {
            continue;
        }
        vis[s][w] = true;
        for(int i = 0; i < V[w].size(); i++) {
            int u = V[w][i].first;
            int kr = V[w][i].second;
            if(dist[s][u] > dist[s][w] + kr) {
                dist[s][u] = dist[s][w] + kr;
                Q.push({-dist[s][u], u});
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        numer[i].second = i;
        numer[i].first = dist[s][i];
    }
    sort(numer + 1, numer + 1 + n);
    int in = -1;
    numer[0].first = -1;
    for(int i = 1; i <= n; i++) {
        if(numer[i].first != numer[i - 1].first) {
            in++;
        }
        warstwa[s][in].push_back(numer[i].second);
        ktoraWarstwa[s][numer[i].second] = in;
        pozycja[s][numer[i].second] = warstwa[s][in].size() - 1;
    }
}

long long solve(int w1, int w2, int ruch) {
    if(w1 > n || w2 > n) {
        return 0;
    }
    if(byl[w1][w2][ruch]) {
        return M[w1][w2][ruch];
    }
    
    long long ret = 0;
    int ww = ruch == 0? w1: w2;
    if(warstwa[ruch][ww].empty()) {
        if(ruch == 0){
            byl[w1][w2][ruch] = true;
            return M[w1][w2][ruch] = solve(w1 + 1, w2, ruch);
        }
        else {
            byl[w1][w2][ruch] = true;
            return M[w1][w2][ruch] = solve(w1, w2 + 1, ruch);
        }
    }
    for(int i = 0; i < warstwa[ruch][ww].size(); i++) {
        int w = warstwa[ruch][ww][i];
        int kW = ktoraWarstwa[1 - ruch][w];
        int p = pozycja[1 - ruch][w];
        if(ruch == 0) {
            ret += value[w];
        } else {
            ret -= value[w];
        }
        pozycja[1 - ruch][warstwa[1 - ruch][kW].back()] = p;
        swap(warstwa[1 - ruch][kW][p], warstwa[1 - ruch][kW].back());
        warstwa[1 - ruch][kW].pop_back();
    }
    if(ruch == 0) {
        ret += max(solve(w1 + 1, w2, ruch), solve(w1 + 1, w2, 1 - ruch));
    } else {
        ret += min(solve(w1, w2 + 1, ruch), solve(w1, w2 + 1, 1 - ruch));
    }
    
    for(int i = 0; i < warstwa[ruch][ww].size(); i++) {
        int w = warstwa[ruch][ww][i];
        int kW = ktoraWarstwa[1 - ruch][w];
        warstwa[1 - ruch][kW].push_back(w);
        pozycja[1 - ruch][w] = warstwa[1 - ruch][kW].size() - 1;
    }
    byl[w1][w2][ruch] = true;
    return M[w1][w2][ruch] = ret;
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d", &A, &B);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &value[i]);
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        V[a].push_back({b, c});
        V[b].push_back({a, c});
    }
    Dijkstra(A, 0);
    Dijkstra(B, 1);
    long long x = solve(0, 0, 0);
    if(x == 0) {
        printf("Flowers\n");
    } else if(x > 0) {
        printf("Break a heart\n");
    } else {
        printf("Cry\n");
    }
    return 0;
}