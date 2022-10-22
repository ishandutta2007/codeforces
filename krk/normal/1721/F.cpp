#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int INF = 1000000000;
const int MAX = 400005;
const int NIL = 0;

vector< ii > G[MAX];
int n, m, match[MAX], matchedge[MAX], dist[MAX];
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
                v = G[u][i].first;
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
    int i, v, e, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i].first;
            e = G[u][i].second;
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    matchedge[v] = matchedge[u] = e;
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

int A[MAX], B[MAX];
int siz;
ll sum;
bool spec[MAX];
vector <int> neigh[MAX];
bool taken[MAX];
vector <int> seq;

void Traverse(int v)
{
    if (taken[v]) return;
    taken[v] = true;
    for (int i = 0; i < neigh[v].size(); i++)
        Traverse(neigh[v][i]);
}

int vertexToPrint(int v)
{
    if (v <= n) return v;
    v -= n;
    return -v;
}

int main()
{
    int e, q;
    scanf("%d %d %d %d", &n, &m, &e, &q);
    for (int i = 1; i <= e; i++) {
        int a, b; scanf("%d %d", &a, &b);
        b += n;
        A[i] = a; B[i] = b;
        G[a].push_back(ii(b, i));
        G[b].push_back(ii(a, i));
    }
    siz = hopcroft_karp();
    for (int i = 1; i <= n; i++)
        if (match[i] != NIL) {
            spec[matchedge[i]] = true;
            sum += matchedge[i];
        }
    for (int i = 1; i <= e; i++)
        if (spec[i]) neigh[B[i]].push_back(A[i]);
        else neigh[A[i]].push_back(B[i]);
    for (int i = 1; i <= n; i++) if (match[i] == NIL)
        Traverse(i);
    for (int i = 1; i <= n; i++)
        if (!taken[i]) seq.push_back(i);
    for (int i = n + 1; i <= n + m; i++)
        if (taken[i]) seq.push_back(i);
    while (q--) {
        int typ; scanf("%d", &typ);
        if (typ == 1) {
            printf("1\n");
            int v = seq.back(); seq.pop_back();
            printf("%d\n", vertexToPrint(v));
            sum -= matchedge[v];
            spec[matchedge[v]] = false;
            siz--;
            printf("%I64d\n", sum);
        } else {
            printf("%d\n", siz);
            bool pr = false;
            for (int i = 1; i <= e; i++) if (spec[i]) {
                if (pr) printf(" ");
                else pr = true;
                printf("%d", i);
            }
            printf("\n");
        }
        fflush(stdout);
    }
    return 0;
}