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
long long k, A[N];

long long GCD(long long a, long long b) {
    return b == 0 ? a : GCD(b, a % b);
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %lld", &n, &k);
        long long gcd = -1;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &A[i]);
        }
        gcd = abs(A[2] - A[1]);
        for (int i = 3; i <= n; i++) {
            gcd = GCD(gcd, abs(A[i] - A[1]));
        }
        
        printf(abs(k - A[1]) % gcd == 0 ? "YES\n" : "NO\n");
    }
    
    return 0;
}