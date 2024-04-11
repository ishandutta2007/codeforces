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

#define LL long long
const int N = 100005;
int n;
LL k;
LL a[N];

LL mini[N];
LL maxi[N];
LL value[N];

void findValue(LL A, LL limit, int w) {
    LL low = 1;
    LL high = A;
    LL res = 0;
    while (low <= high) {
        LL mid = (low + high) / 2;
        LL val = mid * (A - mid * mid);
        LL lower = (mid - 1) * (A - (mid - 1) * (mid - 1));
        if (val - lower >= limit) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    maxi[w] = res;
    low = 1;
    high = A;
    res = 0;
    while (low <= high) {
        LL mid = (low + high) / 2;
        LL val = mid * (A - mid * mid);
        LL lower = (mid - 1) * (A - (mid - 1) * (mid - 1));
        if (val - lower >= limit + 1) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    debug(res);
    mini[w] = min(maxi[w], res);
    debug(mini[w], maxi[w]);
}

int main() {
    
    scanf("%d %lld", &n, &k);
    
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    
    LL low = -(3e18);
    LL high = 1e10;
    LL res = high;
    while (low <= high) {
        LL mid = ((__int128)low + high) / 2;
        LL cntMini = 0, cntMaxi = 0;
        for (int i = 1; i <= n; i++) {
            findValue(a[i], mid, i);
            cntMini += mini[i];
            cntMaxi += maxi[i];
        }
        debug(mid, cntMini, cntMaxi, k);
        if (cntMini <= k && k <= cntMaxi) {
            res = mid;
            break;
        }
        if (cntMini > k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
//     debug(res);
    for (int i = 1; i <= n; i++) {
        findValue(a[i], res, i);
        value[i] = mini[i];
        k -= mini[i];
    }
    
    for (int i = 1; i <= n; i++) {
        if (k == 0) break;
        if (maxi[i] - mini[i] <= k) {
            value[i] = maxi[i];
            k -= maxi[i] - mini[i];
        } else {
            value[i] = mini[i] + k;
            k = 0;
            break;
        }
    }
    
    long long f = 0;
    for (int i = 1; i <= n; i++) {
        printf("%lld ", value[i]);
        f += value[i] * (a[i] - value[i] * value[i]);
    }
    printf("\n");
    
    debug(f);
    
    return 0;
}