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

int n, m, x, y;
char board[N][N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &n, &m, &x, &y);
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%s", &board[i][1]);
            int cnt = 0;
            for (int j = 1; j <= m; j++) {
                if (board[i][j] == '.') {
                    cnt++;
                } else {
                    ans += min(cnt * x, cnt / 2 * y + (cnt % 2) * x);
                    cnt = 0;
                }
            }
            if (cnt > 0) {
                ans += min(cnt * x, cnt / 2 * y + (cnt % 2) * x);
            }
        }
        printf("%lld\n", ans);
        
    }
    
    return 0;
}