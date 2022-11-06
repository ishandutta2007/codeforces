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
    
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n, r;
        scanf("%lld %lld", &n, &r);
        auto oldR = r;
        long long sum = 0;
        r = min(n - 1, r);
        printf("%lld\n", r * (r + 1) / 2 + (oldR >= n ? 1 : 0));
        continue;
        for (int i = 1; i <= min(n + 1, r); i++) {
            sum += max(0LL, (long long)i);
        }
        sum++;
        debug(sum);
        printf("%lld\n", n * r * (r + 1) / 2 - n * r - r * (r + 1) / 2 + r * (r + 1) * (2 * r + 1) / 6);
    }
    
    return 0;
}