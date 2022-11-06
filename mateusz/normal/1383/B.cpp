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

const int N = 100005;

int n;
int A[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        bool found = false;
        for (int bit = 30; bit >= 0; bit--) {
            int cntOne = 0, cntZero = 0;
            for (int i = 1; i <= n; i++) {
                if (A[i] & (1 << bit)) {
                    cntOne++;
                } else {
                    cntZero++;
                }
            }
            if (cntOne % 2 == 0) {
                continue;
            }
//             debug(bit, cntOne, cntZero);
            if (cntOne % 4 == 1 || cntZero % 2 == 1) {
                printf("WIN\n");
            } else {
                printf("LOSE\n");
            }
            found = true;
            break;
        }
        if (!found) {
            printf("DRAW\n");
            continue;
        }
    }
    
    
    return 0;
}