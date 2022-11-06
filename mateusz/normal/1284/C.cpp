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

const int N = 250005;

int n, m, fact[N];

int main() {
    
    scanf("%d %d", &n, &m);
    
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (long long)fact[i - 1] * i % m;
    }
    
    int ans = 0;
    for (int k = 1; k <= n; k++) {
        ans = (ans + ((((long long)(n - k + 1) * (n - k + 1) % m) * (long long)fact[k]) % m * (long long)fact[n - k] % m)) % m;
    }
    
    
    printf("%d\n", ans);
    
    return 0;
}