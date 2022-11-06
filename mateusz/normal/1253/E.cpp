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

const int N = 100005;

int n, m, x[N], s[N], dp[N][2];

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &s[i]);
    }
    
    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i][1] = 1e9;
        for (int j = 1; j <= n; j++) {
            if (x[j] - s[j] <= i && x[j] + s[j] >= i) {
                dp[i][0] = min(dp[i][0], dp[max(0, x[j] - s[j] - 1)][1]);
            } else if (x[j] - s[j] > i) {
                dp[i][0] = min(dp[i][0], dp[i - 1][1] + x[j] - s[j] - i);
            } else if (x[j] + s[j] < i) {
                int newS = i - x[j];
                dp[i][0] = min(dp[i][0], dp[max(0, x[j] - newS - 1)][1] + i - x[j] - s[j]);
            }
            dp[i][1] = min(dp[i][1], min(dp[i][0], dp[i - 1][1] + 1));
        }
    }
    
    printf("%d\n", min(dp[m][0], dp[m][1]));
    
    return 0;
}