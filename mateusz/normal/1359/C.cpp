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
    
    int tes;
    scanf("%d", &tes);
    while (tes--) {
        long long h, c, t;
        scanf("%lld %lld %lld", &h, &c, &t);
        if (2 * t <= h + c) {
            printf("2\n");
            continue;
        }
        long long low = 1;
        long long high = 1e11;
        long long res = high;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long sumTemp = mid * h + (mid - 1) * c;
            if (sumTemp <= t * (2 * mid - 1)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (res > 1) {
            long long res2 = res - 1;
            if (fabs((long double)(res2 * h + (res2 - 1) * c) / (2 * res2 - 1) - t) - 1e-14 < fabs((long double)(res * h + (res - 1) * c) / (2 * res - 1) - t)) {
                printf("%lld\n", 2 * res2 - 1);
                continue;
            }
        }
        printf("%lld\n", 2 * res - 1);
    }
    
    return 0;
}