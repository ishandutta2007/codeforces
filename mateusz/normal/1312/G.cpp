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

const int N = 1000005;

int n, m;
vector<pair<char, int> > V[N];
int query[N], dp[N], depth[N], ans[N];

int DFS(int w, int par, int bestVal, int lowerNo) {
    int ret = 0;

    dp[w] = dp[par] + 1;
        
    if (query[w]) {
        dp[w] = min(dp[w], bestVal + lowerNo + 1);
        ans[query[w]] = dp[w];
        ret = 1;
    }
    
    sort(V[w].begin(), V[w].end());
    
    for (auto p : V[w]) {
        int u = p.second;
        depth[u] = depth[w] + 1;
        int queriesNo = DFS(u, w, min(bestVal, dp[w] - lowerNo), ret + lowerNo);
        ret += queriesNo;
    }
    
    return ret;
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        int par;
        char c;
        scanf("%d %c", &par, &c);
        V[par].push_back({c, i});
    }
    
    scanf("%d", &m);
    
    for (int i = 1; i <= m; i++) {
        int w;
        scanf("%d", &w);
        query[w] = i;
    }
    
    dp[0] = -1;
    DFS(0, 0, 1e9, 0);
    
    for (int i = 1; i <= m; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    return 0;
}