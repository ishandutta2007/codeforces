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

int a[1005];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        
        int moves = 0;
        int low = 0;
        int sumleft = 0;
        int high = n;
        int sumright = 0;
        int lastLeft = 0, lastRight = 0;
        while (low <= high) {
            moves++;
            if (moves % 2 == 1) {
                int cur = 0;
                while (low <= high && cur <= lastRight) {
                    cur += a[low];
                    low++;
                }
                sumleft += cur;
                lastLeft = cur;
            } else {
                int cur = 0;
                while (low <= high && cur <= lastLeft) {
                    cur += a[high];
                    high--;
                }
                sumright += cur;
                lastRight = cur;
            }
        }
        printf("%d %d %d\n", moves, sumleft, sumright);
    }
    
    return 0;
}