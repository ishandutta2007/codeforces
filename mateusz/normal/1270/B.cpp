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

const int N = 200005;

int n, tab[N];

void test() {
    scanf("%d", &n);
    
    int bestMax = -1, bestMaxPos = -1, bestMin = 1e9 + 1, bestMinPos = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        if (bestMax >= tab[i] + i + 1) {
            printf("YES\n%d %d\n", bestMaxPos, i);
            return;
        }
        if (tab[i] - i >= bestMin + 1) {
            printf("YES\n%d %d\n", bestMinPos, i);
            return;
        }
        if (tab[i] + i >= bestMax) {
            bestMax = tab[i] + i;
            bestMaxPos = i;
        }
        if (tab[i] - i <= bestMin) {
            bestMin = tab[i] - i;
            bestMinPos = i;
        }
    }
    printf("NO\n");
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        test();
    }
    return 0;
}