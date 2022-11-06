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

const int N = 2005;

int n, m;
char board[N][N];
int dp[N][N];

int main() {
    
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", &board[i][1]);
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i < 3 || board[i][j] != board[i - 1][j] || board[i][j] != board[i - 1][j - 1] || board[i][j] != board[i - 1][j + 1] || board[i][j] != board[i - 2][j]) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] += min(dp[i - 1][j - 1], min(dp[i - 2][j], dp[i - 1][j + 1])) + 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ans += dp[i][j];
            }
        }
        printf("%lld\n", ans);
    
    
    return 0;
}