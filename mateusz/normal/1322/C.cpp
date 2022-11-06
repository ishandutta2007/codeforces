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

const int N = 500005, P = 1314143, M = 1e9 + 7;

int n, m, a, b;
long long val[N];
int pot[N];
int H[N];

long long NWD(long long a, long long b) {
    return b == 0 ? a : NWD(b, a % b);
}

int main() {
    srand(time(NULL) * 123);
    int t;
    scanf("%d", &t);
    pot[0] = 1;
    for (int i = 1; i < N; i++) {
        pot[i] = (long long)pot[i - 1] * P % M;
    }
    
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            H[i] = 0;
        }
    
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &val[i]); 
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &a, &b);
            H[b] = (H[b] + (long long)P * pot[a]) % M;
        }
        
        map<int, long long> mapa;
        for (int i = 1; i <= n; i++) {
            if (H[i] == 0) continue;
            mapa[H[i]] += val[i];
        }
        
        long long gcd = 0;
        for (auto p : mapa) {
            gcd = NWD(p.second, gcd);
        }

        printf("%lld\n", gcd);
    }
    
    return 0;
}