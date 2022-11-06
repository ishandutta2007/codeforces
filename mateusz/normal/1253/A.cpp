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

const int N = 100005;

int t, n, A[N], B[N];

int main() {
    
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        
        for (int i = 1; i <= n; i++) {
            scanf("%d", &B[i]);
        }
        
        int diff = -1;
        bool ended = false;
        bool bad = false;
        for (int i = 1; i <= n; i++) {
            if (A[i] != B[i]) {
                if (A[i] > B[i]) {
                    bad = true;
                    break;
                }
                if (diff == -1) {
                    diff = B[i] - A[i];
                } else if (ended || diff != B[i] - A[i]) {
                    bad = true;
                    break;
                }
            } else {
                if (diff != -1) {
                    ended = true;
                }
            }
        }
        
        printf(bad ? "NO\n" : "YES\n");
    }
    
    return 0;
}