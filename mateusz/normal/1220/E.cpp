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

const int N = 200005;

int n, m, s, a, b;

int val[N];
bool canGetOut[N];
long long bestPath[N];
int vis[N];
vector<int> V[N];

void DFS(int w, int par = -1) {
    vis[w] = 1;
    canGetOut[w] = false;
    for (int u : V[w]) {
        if (vis[u] == 1 && u != par) {
            canGetOut[w] = true;
        }
        if (!vis[u]) {
            DFS(u, w);
            canGetOut[w] |= canGetOut[u];
            bestPath[w] = max(bestPath[w], bestPath[u]);
        }
    }
    bestPath[w] += val[w];
    vis[w] = 2;
}

int main() {
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    int s;
    scanf("%d", &s);
    
    DFS(s);
    long long ans = 0;
    long long best = 0;
    for (int i = 1; i <= n; i++) {
        if (canGetOut[i]) {
            ans += val[i];
        } else {
            best = max(best, bestPath[i]);
        }
    }
    
    printf("%lld\n", ans + best);
    
    return 0;
}