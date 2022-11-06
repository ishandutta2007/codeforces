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

const int N = 200005;

int n;
long long a[N], b[N];

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
    }
    
    a[1] = b[1];
    long long mx = a[1];
    for (int i = 2; i <= n; i++) {
        a[i] = b[i] + mx;
        mx = max(mx, a[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%lld ", a[i]);
    }
    printf("\n");
    return 0;
}