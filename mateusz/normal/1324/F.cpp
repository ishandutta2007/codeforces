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

int n, a, b, ans[N], dp[N];
int color[N];
vector<int> V[N];

void DFS(int w, int par = -1) {
    dp[w] = color[w];
    for (int u : V[w]) {
        if (par == u) continue;
        DFS(u, w);
        dp[w] += (dp[u] > 0) * dp[u];
    }
}

void DFS2(int w, int par = -1) {
    ans[w] = max(ans[w], dp[w]);
    for (int u : V[w]) {
        if (par == u) continue;
        dp[u] = dp[u] + ((dp[w] - ((dp[u] > 0) * dp[u])) > 0) * (dp[w] - ((dp[u] > 0) * dp[u]));
        DFS2(u, w);
    }
}

void solve() {
    DFS(1);
    DFS2(1);
}

int main() {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
        if (color[i] == 0) color[i] = -1;
    }
    
    for (int i = 2; i <= n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
//         color[i] = -color[i];
        ans[i] = -1e9;
    }
    solve();
//     f
//     solve();
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}