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

int intersection(int l1, int r1, int l2, int r2) {
    return max(0, min(r1, r2) - max(l1, l2));
}

bool notintersect(int l1, int r1, int l2, int r2) {
    return r1 < l2 || r2 < l1;
}


int n, k;
int l1, r1, l2, r2;
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        long long sum = 0;
        long long ans = 1e18;
        long long totalLen = (long long)n * intersection(l1, r1, l2, r2);
        debug(totalLen);
        if (totalLen >= k) {
            printf("0\n");
            continue;
        }
        for (int i = 1; i <= n; i++) {
            int la = l1, lb = l2, ra = r1, rb = r2;
            if (notintersect(la, ra, lb, rb)) {
                sum += max(lb - ra, la - rb);
                if (rb <= la) {
                    rb = la;
                } else if (ra <= lb) {
                    ra = lb;
                }
            }
            debug(sum, totalLen);
            sum += abs(ra - rb);
            totalLen += abs(ra - rb);
            if (totalLen >= k) {
                sum -= totalLen - k;
                ans = min(ans, sum);
                break;
            }
            debug(sum, totalLen);
            sum += abs(la - lb);
            totalLen += abs(la - lb);
            if (totalLen >= k) {
                sum -= totalLen - k;
                ans = min(ans, sum);
                break;
            }
            debug(sum, totalLen);
            ans = min(ans, sum + (k - totalLen) * 2);
            debug(ans);
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}