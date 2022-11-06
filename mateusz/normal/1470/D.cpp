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

const int N = 300005;

int n, m, a, b;
int color[N];
bool vis[N];
vector<int> V[N];

void DFS(int w) {
    vis[w] = true;
    color[w] = 1;
    for (auto u : V[w]) {
        if (vis[u] && color[u]) {
            color[w] = 0;
            break;
        }
    }
    for (int u : V[w]) {
        if (!vis[u]) {
            DFS(u);
        }
    }
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            V[i].clear();
            vis[i] = false;
            color[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &a, &b);
            V[a].push_back(b);
            V[b].push_back(a);
        }
        
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                cnt++;
                DFS(i);
            }
            if (cnt > 1) break;
        }
        
        if (cnt > 1) {
            printf("NO\n");
            continue;
        }
        
        printf("YES\n");
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (color[i] == 1) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
        for (int i = 1; i <= n; i++) {
            if (color[i] == 1) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    
    return 0;
}