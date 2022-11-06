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

const int N = 50005;

int n;
char word[N];
int A[N], B[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s", &word[1]);
        for (int i = 1; i <= n; i++) {
            word[i] -= '0';
        }
        
        bool greater = false;
        for (int i = 1; i <= n; i++) {
            if (!greater) {
                if (word[i] == 0) {
                    A[i] = B[i] = 0;
                } else if (word[i] == 1) {
                    A[i] = 0;
                    B[i] = 1;
                    greater = true;
                } else if (word[i] == 2) {
                    A[i] = B[i] = 1;
                }
            } else {
                if (word[i] == 0) {
                    A[i] = B[i] = 0;
                } else if (word[i] == 1) {
                    A[i] = 1;
                    B[i] = 0;
                    greater = true;
                } else if (word[i] == 2) {
                    A[i] = 2;
                    B[i] = 0;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d", A[i]);
        }
        printf("\n");
        
        for (int i = 1; i <= n; i++) {
            printf("%d", B[i]);
        }
        printf("\n");
    }
    
    return 0;
}