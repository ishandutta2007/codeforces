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

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        if (n < 4) {
            printf("-1\n");
            continue;
        }
        if (n == 4) {
            printf("3 1 4 2\n");
            continue;
        }
        if (n % 2 == 1) {
            for (int i = 1; i <= n; i += 2) {
                printf("%d ", i);
            }
            printf("%d %d ", n - 3, n - 1);
            for (int i = n - 5; i >= 1; i -= 2) {
                printf("%d ", i);
            }
            printf("\n");
        } else {
            for (int i = 1; i <= n - 3; i += 2) {
                printf("%d ", i);
            }
            printf("%d %d %d %d ", n - 1, n - 4, n, n - 2);
            for (int i = n - 6; i >= 1; i -= 2) {
                printf("%d ", i);
            }
            printf("\n");
        }
    }
    
    return 0;
}