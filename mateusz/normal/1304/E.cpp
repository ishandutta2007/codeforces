#include <bits/stdc++.h>

using namespace std;

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}

template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.st <<","<<P.nd <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 100005, LOG = 17;

int n, k;
int a, b;
vector<int> V[N];
bool vis[N];
int inTime[N], outTime[N], timer;
int par[N][LOG + 5];
int parent[N];
int depth[N];
bool taken[N];
int x, y, q;

void DFS(int w) {
    inTime[w] = ++timer;
    vis[w] = true;
    par[w][0] = parent[w];
    for (int i = 1; i < LOG; i++) {
        par[w][i] = par[par[w][i - 1]][i - 1];
    }
    
    for (int u : V[w]) {
        if (!vis[u]) {
            parent[u] = w;
            depth[u] = depth[w] + 1;
            DFS(u);
        }
    }
    outTime[w] = ++timer;
}

bool isAncestor(int anc, int w) {
    return inTime[anc] <= inTime[w] && outTime[anc] >= outTime[w];
}

int LCA(int a, int b) {
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[a] - (1 << i) >= depth[b]) {
            a = par[a][i];
        }
    }
    
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[b] - (1 << i) >= depth[a]) {
            b = par[b][i];
        }
    }
    
    if (a == b) {
        return a;
    }
    
    for (int i = LOG - 1; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
            a = par[a][i];
            b = par[b][i];
        }
    }
    
    return par[a][0];
}



int main() {
    depth[0] = -1;
    scanf("%d", &n);
    
    for (int i = 2; i <= n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    DFS(1);
   
    scanf("%d", &q);
    
    while (q--) {
        scanf("%d %d %d %d %d", &x, &y, &a, &b, &k);
        int LCAab = LCA(a, b);
        int dist = depth[a] + depth[b] - 2 * depth[LCAab];
        if (dist <= k && (k - dist) % 2 == 0) {
            printf("YES\n");
            continue;
        }
        
        int LCAax = LCA(a, x);
        int LCAby = LCA(b, y);
        int distax = depth[a] + depth[x] - 2 * depth[LCAax];
        int distby = depth[b] + depth[y] - 2 * depth[LCAby];
        dist = distax + distby + 1;
        if (dist <= k && (k - dist) % 2 == 0) {
            printf("YES\n");
            continue;
        }
        
        swap(a, b);
        
        LCAax = LCA(a, x);
        LCAby = LCA(b, y);
        distax = depth[a] + depth[x] - 2 * depth[LCAax];
        distby = depth[b] + depth[y] - 2 * depth[LCAby];
        dist = distax + distby + 1;
        if (dist <= k && (k - dist) % 2 == 0) {
            printf("YES\n");
            continue;
        }
        
        printf("NO\n");
    }
    
    return 0;
}