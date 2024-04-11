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

const int N = 200005;

int n;
long long k;
int A[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %lld", &n, &k);
        int mx = -1e9;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            mx = max(mx, A[i]);
        }
        int newMx = -1e9;
        for (int i = 1; i <= n; i++) {
            A[i] = mx - A[i];
            newMx = max(newMx, A[i]);
        }
        k--;
        if (k % 2 == 1) {
            for (int i = 1; i <= n; i++) {
                A[i] = newMx - A[i];
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    
    return 0;
}