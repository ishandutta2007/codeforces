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

const int N = 200005, M = 998244353;

int n, fact[N], deg[N], a, b;
vector<int> V[N];
bool vis[N];
int dp[N], dp2[N];
int subSize[N];

void DFS(int w) {
    int ans = 1;
    vis[w] = true;
    subSize[w] = 1;
    int ss = 0;
    for (int u : V[w]) {
        if (!vis[u]) {
            ss++;
            DFS(u);
            subSize[w] += subSize[u];
            ans = (long long)ans * dp2[u] % M;
        }
    }
    dp[w] = (long long)ans * fact[ss] % M;
    dp2[w] = (long long)dp[w] * (ss + 1) % M;
    dp[w] = (long long)dp[w] * subSize[w] % M;
//     debug(w, dp[w]);
}

int main() {
    scanf("%d", &n);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (long long)fact[i - 1] * i % M;
    }
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    DFS(1);
    printf("%d\n", dp[1]);
    return 0;
}