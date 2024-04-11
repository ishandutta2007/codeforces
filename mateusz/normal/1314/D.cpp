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

const int N = 85;

int n, k;
int edge[N][N];

int dp[15][85];
int color[N];

int solve() {
    for (int j = 0; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            dp[j][i] = 2e9;
        }
    }
    dp[0][1] = 0;
    
    for (int l = 0; l < k; l++) {
        for (int i = 1; i <= n; i++) {
            if (color[i] != l % 2) {
                continue;
            }
            for (int j = 1; j <= n; j++) {
                if (j == i || color[j] % 2 != (l + 1) % 2) continue;
//                 debug(i, j, dp[l][i], edge[i][j]);
                dp[l + 1][j] = min(dp[l + 1][j], dp[l][i] + edge[i][j]);
            }
        }
    }
    return dp[k][1];
}

int main() {
    
    srand(time(0));
    
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &edge[i][j]);
        }
    }
    
    int reps = 10000;
    
    int ans = 2e9;
    for (int r = 1; r <= reps; r++) {
        for (int i = 2; i <= n; i++) {
            color[i] = rand() % 2;
        }
        
        ans = min(ans, solve());
    }
    
    printf("%d\n", ans);
    
    return 0;
}