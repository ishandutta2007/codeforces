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

const int M = 998244353;

int fact[500005], factInv[500005];

int n, k;

void add(int &w, int u) {
    w += u;
    if (w >= M) w -= M;
}

int mul(int w, int u) {
    return (long long)w * u % M;
}

int power(int a, int k) {
    if (k == 0) return 1;
    return mul(power(mul(a, a), k / 2), k % 2 ? a : 1);
}

int inv(int w) { return power(w, M - 2); }

int newton(int n, int k) {
    if (n < 0 || k > n) {
        return 0;
    }
    return mul(fact[n], mul(factInv[k], factInv[n - k]));
}

int main() {
    
    scanf("%d %d", &k, &n);
    
    fact[0] = 1;
    for (int i = 1; i <= 500000; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    factInv[500000] = inv(fact[500000]);
    for (int i = 500000 - 1; i >= 0; i--) {
        factInv[i] = mul(factInv[i + 1], i + 1);
    }
    
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        add(ans, newton(k / i - 1, n - 1));
    }
    
    printf("%d\n", ans);
    
    return 0;
}