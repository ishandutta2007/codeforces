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

int fact[N], factInv[N];

int add(int w, int u) {
    int x = w + u;
    if (x >= M) {
        x -= M;
    }
    return x;
}

int mul(int w, int u) {
    return (long long)w * u % M;
}

int powaer(int a, int k) {
    if (k == 0) return 1;
    return mul(powaer(mul(a, a), k / 2), k % 2 ? a : 1);
}

int inv(int w) {
    return powaer(w, M - 2);
}

int newton(int n, int k) {
    return mul(fact[n], mul(factInv[k], factInv[n - k]));
}


int main() {
    
    int n, m;
    scanf("%d %d", &n, &m);
    if (n <= 2) {
        printf("0\n");
        return 0;
    }
    
    fact[0] = 1;
    for (int i = 1; i <= m; i++) {
        fact[i] = mul(fact[i - 1], i);
        debug(i, fact[i]);
    }
    
    factInv[m] = inv(fact[m]);
    for (int i = m - 1; i >= 0; i--) {
        factInv[i] = mul(factInv[i + 1], i + 1);
        debug(i, factInv[i]);
    }
    debug(newton(4, 2));
    int ans = mul(newton(m, n - 1), n - 2);
    for (int i = 1; i <= n - 3; i++) {
        ans = mul(ans, 2);
    }
    
    printf("%d\n", ans);
    return 0;
}