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

int n, d, pile[N];

void test() {
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &pile[i]);
    }
    
    for (int i = 2; i <= n; i++) {
        int fullMoves = min(pile[i], d / (i - 1));
        pile[1] += fullMoves;
        pile[i] -= fullMoves;
        d -= fullMoves * (i - 1);
    }
    printf("%d\n", pile[1]);
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) test();
    
    return 0;
}