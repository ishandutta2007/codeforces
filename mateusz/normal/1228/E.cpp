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

const int N = 255, M = 1e9 + 7;

int fact[N], factInv[N], pot[N], pot2[N];

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

int inverse(int w) {
    return power(w, M - 2);
}

int newton(int n, int k) {
    return mul(fact[n], mul(factInv[k], factInv[n - k]));
}

int n, K;
int dp[N][N];

int main() {
    
    scanf("%d %d", &n, &K);
    
    pot[0] = 1;
    for (int i = 1; i <= n; i++) {
        pot[i] = mul(pot[i - 1], K);
    }
    
    pot2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pot2[i] = mul(pot2[i - 1], K - 1);
    }
    
    dp[0][0] = 1;
//     for (int i = 0; i <= n; i++) {
//         dp[0][i] = 1;
//     }
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    factInv[n] = inverse(fact[n]);
    for (int i = n - 1; i >= 0; i--) {
        factInv[i] = mul(factInv[i + 1], i + 1);
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= i; k++) {
                if (k == 0) {
                    add(dp[i][j], mul((pot[n-i]-pot2[n-i]+M)%M, mul(pot2[i], dp[i][j - 1])));
                } else {
                    add(dp[i][j], mul(newton(i, k), mul(dp[i - k][j - 1], mul(pot2[i - k], pot[n - i]))));
//                 add(dp[i][j], mul(mul(newton(i, k), pot[k * (j - 1)]), mul(pot2[i - k], dp[i - k][j - 1])));
                }
//                 debug(i, j, k, dp[i][j]);
            }
        }
    }
    
    printf("%d\n", dp[n][n]);
    
    return 0;
}