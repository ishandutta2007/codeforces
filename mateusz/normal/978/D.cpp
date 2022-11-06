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

const int N = 100005, INF = 1e9;

int n, a[N], b[N];

int check(int x, int y) {
    for (int i = 1; i <= n; i++) {
        b[i] = a[i];
    }
    
    b[1] += x;
    b[2] += y;
    int r = b[2] - b[1];
    int ret = abs(x) + abs(y);
    for (int i = 3; i <= n; i++) {
        int needed = b[i - 1] + r;
        if (abs(needed - a[i]) > 1) {
            return INF;
        }
        ret += abs(a[i] - needed);
        b[i] = needed;
    }
    return ret;
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    int ans = INF;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            ans = min(ans, check(x, y));
        }
    }
    
    if (ans == INF) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", ans);
    
    return 0;
}