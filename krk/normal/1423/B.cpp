#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 100005;
#define MAX 100001
#define NIL 0
#define INF (1<<28)
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, e;
int A[Maxn], B[Maxn], C[Maxn];
vector <int> un;
vector< int > G[MAX];
int m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0]  G1[G[1---n]]  G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

bool Solve(int x)
{
    for (int i = 1; i <= n + m; i++) {
        G[i].clear();
        match[i] = NIL;
    }
    for (int i = 0; i < e; i++) if (C[i] <= x) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    return hopcroft_karp() >= n;
}
 
int main()
{
    scanf("%d %d", &n, &e);
    m = n;
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
        B[i] += n;
        un.push_back(C[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    int lef = 0, rig = int(un.size()) - 1;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Solve(un[mid])) rig = mid - 1;
        else lef = mid + 1;
    }
    printf("%d\n", lef >= un.size()? -1: un[lef]);
    return 0;
}