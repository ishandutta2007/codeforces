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

const int N = 200005, M = 998244353;

int sum(int w, int u) {
    int ret = w + u;
    if (ret >= M) return ret - M;
    return ret;
}

int mul(int w, int u) {
    return (long long)w * u % M;
}

int pot[N];

int main() {
    int n;
    
    scanf("%d", &n);
    
    pot[0] = 1;
    for (int i = 1; i <= n; i++) {
        pot[i] = (long long)10 * pot[i - 1] % M;
    }
    
    for (int k = 1; k <= n; k++) {
        if (k == n) {
            printf("10\n");
        } else {
            printf("%d ", sum(mul(90, mul(9, mul(pot[n - 2 - k], n - k - 1))), mul(180, pot[n - 1 - k])));
        }
    }
    
    return 0;
}