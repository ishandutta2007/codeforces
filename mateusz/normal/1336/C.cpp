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

const int N = 3005, M = 998244353;

char S[N], T[N];

int n, m;
int dp[N][N];

void add(int &w, int u) {
    w += u;
    if (w >= M) {
        w -= M;
    }
}

int main() {
    
    scanf("%s", &S[1]);
    n = strlen(S + 1);
    scanf("%s", &T[1]);
    m = strlen(T + 1);
    
    
    for (int i = 1; i <= n + 1; i++) {
        dp[i][i - 1] = 1;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j++) {
            int lastLetter = j - i + 1;
            //begin
            if (i > m || T[i] == S[lastLetter]) {
                add(dp[i][j], dp[i + 1][j]);
            }
            //end
            if (j > m || T[j] == S[lastLetter]) {
                add(dp[i][j], dp[i][j - 1]);
            }
        }
    }
    
    int ans = 0;
    for (int i = m; i <= n; i++) {
        add(ans, dp[1][i]);
    }
    
    printf("%d\n", ans);
    
    return 0;
}