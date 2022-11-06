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
int n, x;
int A[N];
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &x);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            sum += A[i];
            sum %= x;
        }
        if (sum != 0) {
            printf("%d\n", n);
            continue;
        }
        
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (A[i] % x != 0) {
                ans = max({ans, i, n - i});
                break;
            }
        }
        for (int i = n; i >= 1; i--) {
            if (A[i] % x != 0) {
                ans = max({ans, i - 1, n - i + 1});
                break;
            }
        }
        printf("%d\n", ans);
        
    }
    
    return 0;
}