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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 105, M = 10000;

int n;
int dp[N * N][N];
int newDp[N * N][N];
int sumDp[N * N][N];
int cnt[N];

int main() {
    scanf("%d", &n);
    int diffValues = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 1; i <= 100; i++) if (cnt[i] > 0) diffValues++;
    sumDp[0][0] = 1;
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j <= M; j++) {
            for (int l = 0; l <= n; l++) {
                dp[j][l] = sumDp[j][l];
            }
        }
        for (int k = 1; k <= cnt[i]; k++) {
            for (int j = M - i; j >= 0; j--) {
                for (int l = n - 1; l >= 0; l--) {
                    newDp[j + i][l + 1] = dp[j][l];
                }
            }
            
            for (int j = 0; j <= M; j++) {
                for (int l = 0; l <= n; l++) {
                    sumDp[j][l] = min(2, sumDp[j][l] + newDp[j][l]);
                    dp[j][l] = newDp[j][l];
                    newDp[j][l] = 0;
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        int sum = 0;
        for (int j = 1; j <= cnt[i]; j++) {
            sum += i;
            debug(i, j, sum, sumDp[sum][j]);
            if (sumDp[sum][j] > 1) {
                continue;
            }
            if (j == cnt[i] && diffValues <= 2) {
                ans = n;
                break;
            } else {
                ans = max(ans, j);
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}