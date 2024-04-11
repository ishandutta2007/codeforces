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

int n, px[N], py[N];

int main() {
    
    scanf("%d", &n);
    if (n % 2 == 1) {
        printf("NO\n");
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &px[i], &py[i]);
    }
    
    for (int i = 0; i < n / 2; i++) {
        int dxA = px[i + 1] - px[i];
        int dyA = py[i + 1] - py[i];
        int dxB = px[(i + n / 2 + 1) % n] - px[i + n / 2];
        int dyB = py[(i + n / 2 + 1) % n] - py[i + n / 2];
        debug(i, i + n / 2, dxA, dyA, dxB, dyB);
        if (dxA != -dxB || dyA != -dyB) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    
    return 0;
}