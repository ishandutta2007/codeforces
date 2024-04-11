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

const int M = 1005;

int n, m;
int cnt[M];
long long newCnt[M];

int main() {
    
    scanf("%d %d", &n, &m);
    int full = n / m;
    int rem = n % m;
    for (int i = 0; i < m; i++) {
        cnt[i] += full;
    }
    for (int i = 1; i <= rem; i++) {
        cnt[i]++;
    }
    
    for (int i = 0; i < m; i++) {
        newCnt[i * i % m] += cnt[i];
    }
    
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans += (long long)newCnt[i] * newCnt[(m - i) % m];
    }
    
    printf("%lld\n", ans);
    
    return 0;
}