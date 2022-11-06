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

int n, k, a, b;
int deg[N];

int main() {
    
    scanf("%d %d", &n, &k);
    if (n == 2) {
        printf("%d\n", k);
        return 0;
    }
    
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        deg[a]++;
        deg[b]++;
    }
    
    int leaves = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            leaves++;
        }
    }
    
    long double ans = (long double)2 * k / leaves;
    
    printf("%.10Lf\n", ans);
    
    return 0;
}