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

int n, m, a, b, s;
vector<int> V[N];
bool vis[N];
int color[N], par[N], depth[N], cnt[N];

void DFS(int w) {
    vis[w] = true;
    
    for (int u : V[w]) {
        if (vis[u] && depth[w] - depth[u] >= s - 1) {
            printf("2\n%d\n", depth[w] - depth[u] + 1);
            printf("%d ", u);
            while (w != u) {
                printf("%d ", w);
                w = par[w];
            }
            exit(0);
        }
        if (vis[u]) continue;
        color[u] = (color[w] + 1) % (s - 1);
        cnt[color[u]]++;
        par[u] = w;
        depth[u] = depth[w] + 1;
        DFS(u);
    }
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        if (i * i >= n) {
            s = i;
            break;
        }
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    DFS(1);
    cnt[color[1]]++;
    
    for (int i = 0; i < s - 1; i++) {
        if (cnt[i] >= s) {
            printf("1\n");
            int c = 0;
            for (int j = 1; j <= n; j++) {
                if (color[j] == i) {
                    printf("%d ", j);
                    c++;
                    if (c == s) {
                        exit(0);
                    }
                }
            }
        }
    }
    
    return 0;
}