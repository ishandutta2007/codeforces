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
  return os <<"("<<P.first <<","<<P.second <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 200005;

int n, m, a, b;
vector<int> V[N], Vrev[N];
vector<int> topo;
int vis[N];
int dpLeft[N], dpRight[N];

bool DFS(int w) {
    vis[w] = 1;
    for (int u : V[w]) {
        if (vis[u] == 1) return false;
        if (vis[u] == 2) continue;
        if (!DFS(u)) {
            return false;
        }
    }
    vis[w] = 2;
    topo.push_back(w);
    return true;
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        Vrev[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (!DFS(i)) {
                printf("-1\n");
                return 0;
            }
        }
    }
    
    for (int i = 0; i < topo.size(); i++) {
        int w = topo[i];
        dpRight[w] = w;
        for (int u : V[w]) {
            dpRight[w] = min(dpRight[w], dpRight[u]);
        }
    }
    
    for (int i = topo.size() - 1; i >= 0; i--) {
        int w = topo[i];
        dpLeft[w] = w;
        for (int u : Vrev[w]) {
            dpLeft[w] = min(dpLeft[w], dpLeft[u]);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (min(dpLeft[i], dpRight[i]) >= i) {
            ans++;
        }
    }
    
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        if (min(dpLeft[i], dpRight[i]) >= i) {
            printf("A");
        } else {
            printf("E");
        }
    }
    printf("\n");
    
    return 0;
}