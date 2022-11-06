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

int n, inRow, inCol;
int A[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &inRow, &inCol);
        bool oneCol = true;
        bool allAdj = true;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            if (i > 1) {
                if (A[i] != A[i - 1]) {
                    oneCol = false;
                }
                if (abs(A[i] - A[i - 1]) > 1) {
                    allAdj = false;
                }
            }
        }
        if (!allAdj) {
            printf("0\n");
            continue;
        }
        int ans = oneCol ? inCol : 0;
        ans += min(inCol, inRow);
        printf("%d\n", ans);
    }
    
    return 0;
}