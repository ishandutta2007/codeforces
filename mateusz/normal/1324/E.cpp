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

int n, h, l, r, a[N];

int main() {
    
    scanf("%d %d %d %d", &n, &h, &l, &r);
    
    vector<int> dp(h, -1e9);
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        int w = a[i];
        vector<int> dp2(h, -1e9);
        for (int j = 0; j < h; j++) {
            int nt = (j + a[i]) % h;
            dp2[nt] = max(dp2[nt], dp[j] + (l <= nt && nt <= r));
            
            nt = (j + a[i] - 1) % h;
            dp2[nt] = max(dp2[nt], dp[j] + (l <= nt && nt <= r));
        }
        dp = dp2;
    }
    
    int ans = *(max_element(dp.begin(), dp.end()));
    printf("%d\n", ans);
    
    return 0;
}