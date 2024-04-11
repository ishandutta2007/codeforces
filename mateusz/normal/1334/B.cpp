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

int n, x;
int a[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &x);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        long long sum = 0;
        int cnt = 0;
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            sum += a[i];
            cnt++;
            if (sum >= (long long)cnt * x) {
                ans = max(ans, cnt);
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}