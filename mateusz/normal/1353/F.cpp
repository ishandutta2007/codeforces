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

const int N = 105;
const long long INF = 1e18;

int n, m;
long long h[N][N];
long long dp[N][N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        vector<long long> heights;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%lld", &h[i][j]);
                heights.push_back(h[i][j] - i + 1 - j + 1);
            }
        }
        long long ans = 1e18;
        for (auto hInit : heights) {
            if (hInit > h[1][1]) continue;
            dp[1][1] = h[1][1] - hInit;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (i == 1 && j == 1) continue;
                    if (h[i][j] < hInit + i - 1 + j - 1) {
                        dp[i][j] = INF;
                    } else {
                        dp[i][j] = h[i][j] - (hInit + i - 1 + j - 1) + min(i > 1 ? dp[i - 1][j] : INF, j > 1 ? dp[i][j - 1] : INF);
                    }
                }
            }
            ans = min(ans, dp[n][m]);
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}