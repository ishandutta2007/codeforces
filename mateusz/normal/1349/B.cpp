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

int n, k, a[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        bool isK = false;
        bool allK = true;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] == k) isK = true;
            else allK = false;
        }
        if (!isK) {
            printf("no\n");
            continue;
        }
        if (allK) {
            printf("yes\n");
            continue;
        }
        
        bool good = false;
        for (int i = 1; i < n; i++) {
            if (a[i] >= k && a[i + 1] >= k) {
                good = true;
                break;
            }
        }
        if (good) {
            printf("yes\n");
            continue;
        }
        
        for (int i = 1; i + 2 <= n; i++) {
            if (a[i] >= k && a[i + 2] >= k) {
                good = true;
                break;
            }
        }
        
        if (good) {
            printf("yes\n");
            continue;
        } else {
            printf("no\n");
        }
    }
    
    return 0;
}