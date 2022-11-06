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
        int a, b, q;
    
        scanf("%d %d %d", &a, &b, &q);
        int total = 0;
        for (int i = 0; i < a * b; i++) {
            if ((i % a) % b != (i % b) % a) {
                total++;
            }
        }
        while (q--) {
            long long l, r;
            scanf("%lld %lld", &l, &r);
            long long len = r - l + 1;
            long long ans = len / (a * b) * total;
            long long rem = len % (a * b);
            long long x = (r - rem + 1) % a;
            long long xx = x % b;
            long long y = (r - rem + 1) % b;
            long long yy = y % a;
            for (long long i = r - rem + 1; i <= r; i++) {
                if (xx != yy) {
                    ans++;
                }
                x++;
                y++;
                xx++;
                yy++;
                if (x >= a) {
                    x = 0;
                    xx = 0;
                }
                if (xx >= b) {
                    xx = 0;
                }
                if (y >= b) {
                    y = 0;
                    yy = 0;
                }
                if (yy >= a) {
                    yy = 0;
                }
            }
            printf("%lld ", ans);
        } 
        printf("\n");
    }
    
    return 0;
}