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

const int N = 100005;

int n, a[N];


int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        long long mx = 0;
        vector<long long> diffs;
        a[0] = -1e9;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] < a[i - 1]) {
                mx = max(mx, (long long)a[i - 1] - a[i]);
                a[i] = a[i - 1];
            }
        }
        int ans = -1;
        for (int i = 35; i >= 0; i--) {
            if ((1LL << i) & mx) {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans + 1);
    }
    
    return 0;
}