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
const int N = 505;
int k, arr[N][N];

int main() {
    
        scanf("%d", &k);
        int n = 10, m = 10;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                arr[i][j] = 0;
            }
        }
        for (int i = 1; i <= m; i++) {
            arr[1][i] = k;
        }
        for (int i = 1; i <= n; i++) {
            arr[i][m] = k;
        }
        for (int i = 1; i <= m; i++) {
            arr[2][i] += (1 << 17);
        }
        arr[1][1] += (1 << 17);
        printf("%d %d\n", n, n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    
    return 0;
}