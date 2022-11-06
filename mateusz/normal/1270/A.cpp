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

int main() {
    
    int t, n, k1, k2;
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d %d", &n, &k1, &k2);
        int mxA = 0, mxB = 0;
        for (int i = 1; i <= k1; i++) {
            int x;
            scanf("%d", &x);
            mxA = max(mxA, x);
        }
        
        for (int i = 1; i <= k2; i++) {
            int x;
            scanf("%d", &x);
            mxB = max(mxB, x);
        }
        printf(mxA > mxB ? "YES\n" : "NO\n");
    }
    
    return 0;
}