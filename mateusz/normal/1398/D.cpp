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

const int N = 205;

int R, G, B;
int red[N], green[N], blue[N];
long long dp[N][N][N];

int main() {
    
        scanf("%d %d %d", &R, &G, &B);
        for (int i = 1; i <= R; i++) {
            scanf("%d", &red[i]);
        }
        for (int i = 1; i <= G; i++) {
            scanf("%d", &green[i]);
        }
        for (int i = 1; i <= B; i++) {
            scanf("%d", &blue[i]);
        }
        for (int i = 0; i <= R; i++) {
            for (int j = 0; j <= G; j++) {
                for (int k = 0; k <= B; k++) {
                    dp[i][j][k] = 0;
                }
            }
        }
        sort(red + 1, red + 1 + R);
        sort(green + 1, green + 1 + G);
        sort(blue + 1, blue + 1 + B);
        for (int i = 0; i <= R; i++) {
            for (int j = 0; j <= G; j++) {
                for (int k = 0; k <= B; k++) {
                    if (i > 0 && j > 0) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + red[i] * green[j]);
                    }
                    if (i > 0 && k > 0) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + red[i] * blue[k]);
                    }
                    if (j > 0 && k > 0) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + green[j] * blue[k]);
                    }
                }
            }
        }
        printf("%lld\n", dp[R][G][B]);
    
    return 0;
}