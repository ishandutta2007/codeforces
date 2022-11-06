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
        long long n, g, b;
        scanf("%lld %lld %lld", &n, &g, &b);
        long long low = 1;
        long long high = 2e18;
        long long res = high;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long fullCycles = mid / (g + b);
            long long rest = mid % (g + b);
            long long totalGood = fullCycles * g + min(g, rest);
            if (mid >= n && totalGood * 2 >= n) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        printf("%lld\n", res);
    }
    
    return 0;
}