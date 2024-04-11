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
const int N = 100005;
int n, k;
int A[N], B[N];
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
 
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            B[i] = A[i];
        }
        sort(B + 1, B + 1 + n);
        map<int, int> prev, dp;
        int last = -1;
        dp[-1] = 0;
        for (int i = 1; i <= n; i++) {
            prev[B[i]] = last;
            last = B[i];
        }
        
        set<int> occ;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (occ.count(prev[A[i]])) {
                dp[A[i]] = dp[prev[A[i]]] + 1;
            } else {
                dp[A[i]] = 1;
            }
            ans = max(ans, dp[A[i]]);
            occ.insert(A[i]);
        }
        
        printf("%d\n", n - ans);
        
    }
    
    return 0;
}