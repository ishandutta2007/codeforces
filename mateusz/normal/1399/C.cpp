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

const int N = 105;

int n;
int A[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        int ans = 0;
        for (int s = 2; s <= 2 * n; s++) {
            vector<int>cnt(2 * n + 10, 0);
            for (int i = 1; i <= n; i++) {
                cnt[A[i]]++;
            }
            int res = 0;
            for (int w = 1; w <= s - w; w++) {
                if (w == s - w) {
                    res += cnt[w] / 2;
                } else {
                    res += min(cnt[w], cnt[s - w]);
                }
            }
            ans = max(ans, res);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}