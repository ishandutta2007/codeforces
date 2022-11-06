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

const int N = 105;

int n;
int A[N], B[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int minA = 1e9;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            minA = min(minA, A[i]);
        }
        int minB = 1e9;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &B[i]);
            minB = min(minB, B[i]);
        }
        
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            int diffA = A[i] - minA;
            int diffB = B[i] - minB;
            ans += max(diffA, diffB);
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}