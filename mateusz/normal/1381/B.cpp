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

const int N = 4005;

int n;
int p[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int mx = 0;
        int cur = 0;
        vector<int> elems;
        for (int i = 1; i <= 2 * n; i++) {
            scanf("%d", &p[i]);
            if (p[i] > mx) {
                if (cur > 0) {
                    elems.push_back(cur);
                }
                mx = p[i];
                cur = 0;
            }
            cur++;
        }
        if (cur > 0) {
            elems.push_back(cur);
        }
        
        vector<int> dp(n + 1, false);
        dp[0] = true;
        for (int x : elems) {
            for (int i = n - x; i >= 0; i--) {
                dp[i + x] |= dp[i];
            }
        }
        printf(dp[n] ? "YES\n" : "NO\n");
    }
    
    return 0;
}