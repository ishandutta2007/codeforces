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

const int N = 100005, M = 1e9 + 7;

long long mul(long long a, long long b) {
    return a * b % M;
}

int power(long long a, long long k) {
    if (k == 0) return 1;
    return mul(power(mul(a, a), k / 2), k % 2 ? a : 1);
}

int x;
long long n;

int main() {
    
    scanf("%d %lld", &x, &n);
    
    vector<pair<int, int > > primes;
    for (int i = 2; i * i <= x; i++) {
        int cnt = 0;
        while (x % i == 0) {
            x /= i;
            cnt++;
        }
        if (cnt > 0) {
            debug(i, cnt);
            primes.push_back({i, cnt});
        }
    }
    
    if (x > 1) {
        debug(x, 1);
        primes.push_back({x, 1});
    }
    
    int ans = 1;
    for (auto p : primes) {
        int prime = p.first;
        int cnt = p.second;
        long long P = prime;
        for (int i = 1; i <= 100; i++) {
            ans = mul(ans, power(prime, n / P));
            debug(P);
            if (P > n / prime) break;
            P *= prime;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}