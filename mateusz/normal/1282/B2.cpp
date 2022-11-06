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

// #ifdef DEBUG
// #define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
// #else
// #define debug(...) (__VA_ARGS__)
// #define cerr if(0)cout
// #endif

const int N = 200005;

int n, p, k;
int a[N];
long long pref[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &p, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        
        for (int i = 1; i <= n; i++) {
            pref[i] = a[i] + (i - k >= 0 ? pref[i - k] : 0);
        }
        long long sumPref = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int low = 1;
            int high = n;
            int res = 0;
            while (low <= high) {
                int mid = (low + high) / 2;
                long long pos = i + (long long)mid * k - 1;
                if (pos > n) {
                    high = mid - 1;
                    continue;
                }
                if (pref[pos] - pref[i - 1] <= p) {
                    res = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (res > 0) {
                ans = max(ans, i - 1 + res * k);
            }
            
             
            p -= a[i];
            if (p < 0) {
                break;
            }
            ans = max(ans, i);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}