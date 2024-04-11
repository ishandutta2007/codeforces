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

int n, m, a[N], p[N];
bool canSwap[N];

void test() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        canSwap[i] = false;
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d", &p[i]);
        canSwap[p[i]] = true;
    }
    
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i < n; i++) {
            if (canSwap[i] && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (a[i] < a[i - 1]) {
            printf("NO\n");
            return;
        }
    }
    
    printf("YES\n");
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        test();
    }
    
    return 0;
}