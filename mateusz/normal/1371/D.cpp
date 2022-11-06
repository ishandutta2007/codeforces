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
int n, k;
int A[N][N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            if (k == 0) break;
            int x = i;
            int y = 0;
            for (int j = 0; j < n; j++) {
                A[x][y] = 1;
                x++;
                y++;
                x %= n;
                y %= n;
                k--;
                if (k == 0) break;
            }
            if (k == 0) break;
        }
        vector<int> rows, cols;
        for (int i = 0; i < n; i++) {
            int sr = 0, sc = 0;
            for (int j = 0; j < n; j++) {
                sr += A[i][j];
                sc += A[j][i];
            }
            rows.push_back(sr);
            cols.push_back(sc);
        }
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        long long ans = (rows.back() - rows[0]) * (rows.back() - rows[0]) + (cols.back() - cols[0]) * (cols.back() - cols[0]);
        printf("%lld\n", ans);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d", A[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}