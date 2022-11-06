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

const int N = 2005;

int n, par;
int size[2];
vector<int> V[2][N];
int dp[N][N][2];
int leaf[2][N];
int lca[2][N][N];
int depth[2][N];

vector<int> stFirst;

vector<int> stSecond;
void DFS2(int t, int w, int d, int v) {
    if (d == stSecond.size() && stFirst.size() > d && w == stFirst[d]) {
        stSecond.push_back(w);
    }
    lca[t][v][w] = lca[t][w][v] = stSecond.back();
    for (int u : V[t][w]) {
        DFS2(t, u, d + 1, v);
    }
    
    if (stSecond.back() == w) {
        stSecond.pop_back();
    }
}

void DFS(int t, int w) {
    stFirst.push_back(w);
    DFS2(t, 1, 0, w);
    for (int u : V[t][w]) {
        depth[t][u] = depth[t][w] + 1;
        DFS(t, u);
    }
    stFirst.pop_back();
}

int main() {
    
    scanf("%d", &n);
    int edgesTotal = 0;
    for (int t = 0; t < 2; t++) {
        scanf("%d", &size[t]);
        edgesTotal += size[t] - 1;
        for (int i = 2; i <= size[t]; i++) {
            scanf("%d", &par);
            V[t][par].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &leaf[t][i]);
        }
        DFS(t, 1);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= i; k++) {
            for (int t = 0; t < 2; t++) {
                dp[i][k][t] = 1e9;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < i; k++) {
            for (int t = 0; t < 2; t++) {
                if (k == i - 1) {
                    dp[i][k][t] = 1e9;
                    for (int kk = 0; kk < max(1, i - 1); kk++) {
                        dp[i][k][t] = min(dp[i][k][t], dp[i - 1][kk][1 - t] + depth[t][leaf[t][i]] - depth[t][lca[t][leaf[t][i]][leaf[t][kk]]]);
                    }
                } else {
                    dp[i][k][t] = dp[i - 1][k][t] + depth[t][leaf[t][i]] - depth[t][lca[t][leaf[t][i]][leaf[t][i - 1]]];
                }
            }
        }
    }
    
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        ans = min(ans, min(dp[n][i][0], dp[n][i][1]));
    }
    printf("%d\n", edgesTotal - ans);
    
    return 0;
}