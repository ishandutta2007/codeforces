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
  return os <<"("<<P.st <<","<<P.nd <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 1005, M = 1e9 + 7;

int n, m, color[N][N], row[N], col[N];

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &row[i]);
        for (int j = 1; j <= row[i]; j++) {
            color[i][j] = 1;
        }
        color[i][row[i] + 1] = 2;
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d", &col[i]);
        for (int j = 1; j <= col[i]; j++) {
            if (color[j][i] == 2) {
                printf("0\n");
                return 0;
            }
            color[j][i] = 1;
        }
        if (color[col[i] + 1][i] == 1) {
            printf("0\n");
            return 0;
        }
        color[col[i] + 1][i] = 2;
    }
    
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (color[i][j] == 0) {
                ans += ans;
                if (ans >= M) ans -= M;
            }
        }
    } 
    
    printf("%d\n", ans);
    
    return 0;
}