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

int n, m, k, path[N], a, b;
vector<int> V[N], V2[N];
bool vis[N];
int dist[N];

void BFS(int v) {
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
    }
    vis[v] = true;
    queue<int> Q;
    Q.push(v);
    
    while (!Q.empty()) {
        int w = Q.front();
        Q.pop();
        for (int u : V2[w]) {
            if (vis[u]) continue;
            vis[u] = true;
            dist[u] = dist[w] + 1;
            Q.push(u);
        }
    }
} 

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V2[b].push_back(a);
    }
    
    scanf("%d", &k);
    
    for (int i = 1; i <= k; i++) {
        scanf("%d", &path[i]);
    }
    
    BFS(path[k]);
    
    int mini = 0;
    int maxi = 0;
    for (int i = 1; i < k; i++) {
        int w = path[i];
        int u = path[i + 1];
        bool isOnShortest = false;
        int countShortest = 0;
        for (int v : V[w]) {
            if (dist[w] == dist[v] + 1) {
                countShortest++;
                if (v == u) {
                    isOnShortest = true;
                }
            }
        }
        if (!isOnShortest) {
            mini++;
            maxi++;
        } else if (countShortest > 1) {
            maxi++;
        }
    }
    
    printf("%d %d\n", mini, maxi);
    
    return 0;
}