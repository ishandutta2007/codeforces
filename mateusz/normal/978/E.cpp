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

const int N = 1005;

int n, m, diff[N];

int getMini() {
    int low = 0;
    int high = m;
    int res = m + 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        long long cur = mid;
        bool good = true;
        for (int i = 1; i <= n; i++) {
            cur += diff[i];
            if (cur < 0) {
                good = false;
                break;
            }
        }
        if (!good) {
            low = mid + 1;
        } else {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}

int getMaxi() {
    int low = 0;
    int high = m;
    int res = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        long long cur = mid;
        bool good = true;
        for (int i = 1; i <= n; i++) {
            cur += diff[i];
            if (cur > m) {
                good = false;
                break;
            }
        }
        if (!good) {
            high = mid - 1;
        } else {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}

int main() {
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &diff[i]);
    }
    
    int mini = getMini();
    
    int maxi = getMaxi();
    if (maxi < mini) {
        printf("0\n");
        return 0;
    }
    
    printf("%d\n", maxi - mini + 1);
    return 0;
}