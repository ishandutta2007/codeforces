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
const int N = 100005;
int n, k, a, b, m;

int vis[N], dist[N], par[N];
vector<int> V[N];

void DFS(int w) {
    vis[w] = 1;
    sort(V[w].begin(), V[w].end(), [&](int a, int b) { return dist[a] > dist[b]; });
    for (int u : V[w]) {
        if (vis[u] == 1 && par[w] != u) {
            if (dist[w] - dist[u] + 1 <= k) {
                int x = w;
                printf("2\n%d\n", dist[w] - dist[u] + 1);
                while (x != u) {
                    printf("%d ", x);
                    x = par[x];
                }
                printf("%d\n", x);
            } else {
                printf("1\n");
                int x = w;
                for (int i = 1; i <= (k + 1) / 2; i++) {
                    printf("%d ", x);
                    x = par[par[x]];
                }
                printf("\n");
            }
            exit(0);
        }
        if (!vis[u]) {
            par[u] = w;
            dist[u] = dist[w] + 1;
            DFS(u);
        }
    }
    vis[w] = 2;
}

int main() {
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    DFS(1);
    printf("1\n");
    int cnt = (k + 1) / 2;
    int cntEven = 0, cntOdd = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] % 2 == 0) cntEven++;
        else cntOdd++;
    }
    
    for (int i = 1; i <= n; i++) {
        if (cnt == 0) break;
        if (cntEven >= cntOdd && dist[i] % 2 == 0) {
            cnt--;
            printf("%d ", i);
        }
        if (cntOdd > cntEven && dist[i] % 2 == 1) {
            cnt--;
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}