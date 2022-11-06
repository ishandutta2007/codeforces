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

int main() {
    
    long long n, p, w, d;
    scanf("%lld %lld %lld %lld", &n, &p, &w, &d);
    if (p / w > n) {
        printf("-1\n");
        return 0;
    }
    if (p % w == 0) {
        printf("%lld 0 %lld\n", p / w, n - (p / w));
        return 0;
    }
    
    long long ileW = p / w;
    set<long long> reszty;
    while ((p - ileW * w) % d != 0) {
        ileW--;
        if (reszty.count((p - ileW * w) % d)) {
            printf("-1\n");
            return 0;
        }
        reszty.insert((p - ileW * w) % d);
    }
    
    long long ileD = (p - ileW * w) / d;
    if (ileW < 0 || ileD < 0) {
        printf("-1\n");
        return 0;
    }
    if (ileW + ileD > n) {
        printf("-1\n");
        return 0;
    }
    
    printf("%lld %lld %lld\n", ileW, ileD, n - ileW - ileD);

    return 0;
}