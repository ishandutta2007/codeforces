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

const int N = 100005;

int n, deg[N];

int main() {
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &deg[i]);
    }
    
    for (int mask = 1; mask < (1 << n); mask++) {
        int shift = 0;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask) {
                shift += deg[i];
            } else {
                shift -= deg[i];
            }
        }
        if (shift % 360 == 0) {
            printf("YES\n");
            return 0;
        }
    }
    
    printf("NO\n");
    
    return 0;
}