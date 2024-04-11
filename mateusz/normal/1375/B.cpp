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
const int N = 305;
const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int n, m;
int A[N][N];
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        bool bad = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &A[i][j]);
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    if (min(xx, yy) >= 1 && min(n - xx, m - yy) >= 0) {
                        cnt++;
                    }
                }
                if (A[i][j] > cnt) {
                    bad = true;
                } else {
                    A[i][j] = cnt;
                }
            }
        }
        if (bad) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%d ", A[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}