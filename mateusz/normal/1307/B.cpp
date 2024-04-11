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

void test() {
    int n, x;
    scanf("%d %d", &n, &x);
    
    int best = 1e9;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int dist;
        scanf("%d", &dist);
        if (x % dist == 0) {
            best = min(best, x / dist);
        }
        mx = max(mx, dist);
    }
    printf("%d\n", min(best, max(2, x / mx + 1)));
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) test();
    
    return 0;
}