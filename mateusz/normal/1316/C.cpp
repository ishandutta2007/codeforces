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

const int N = 1000005;

int n, m, p, a[N], b[N];

void add(int &w, int u) {
    w += u;
    if (w >= p) w -= p;
}

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    scanf("%d %d", &n, &m);
    scanf("%d", &p);
    
    int f1 = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] % p != 0 && f1 == -1) {
            f1 = i;
        }
    }
    
    int f2 = -1;
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        if (b[i] % p != 0) {
            f2 = i;
            break;
        }
    }
    
    debug(f1, f2);
    
    printf("%d\n", f1 + f2);
    return 0;
}