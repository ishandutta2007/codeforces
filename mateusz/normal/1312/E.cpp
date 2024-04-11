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

const int N = 505;

int a[N], dp[N][N], pref[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i][i] = a[i];
    }
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            dp[i][j] = -1;
            for (int k = i; k < j; k++) {
                int left = dp[i][k];
                int right = dp[k + 1][j];
                if (left == -1 || right == -1) {
                    continue;
                }
                if (left != right) continue;
                dp[i][j] = left + 1;
                break;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        pref[i] = i;
        for (int j = i; j >= 1; j--) {
            if (dp[j][i] != -1) {
                pref[i] = min(pref[i], pref[j - 1] + 1);
            }
        }
    }
    
    printf("%d\n", pref[n]);
    return 0;
}