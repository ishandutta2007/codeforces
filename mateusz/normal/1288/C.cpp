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

const int M = 1e9 + 7; 

int fact[2005], factInv[2005];

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
    int n, m;
    scanf("%d %d", &n, &m);
    fact[0] = 1;
    for (int i = 1; i <= n + m; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    factInv[n + m] = inv(fact[n + m]);
    for (int i = n - 1 + m; i >= 0; i--) {
        factInv[i] = mul(factInv[i + 1], i + 1);
    }
    int ans = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = a; b <= n; b++) {
            add(ans, mul(newton(a + m - 2, m - 1), newton(n - b + 1 + m - 2, m - 1)));
        }
    }
    printf("%d\n", ans);

    
    return 0;
}