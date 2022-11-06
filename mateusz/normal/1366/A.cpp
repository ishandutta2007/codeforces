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

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int ileA = max(0, min(b - a, a));
        a -= ileA;
        b -= ileA * 2;
        
        int ileB = max(0, min(a - b, b));
        a -= 2 * ileB;
        b -= ileB;
        if (a > b) swap(a, b);
        int ileC = a / 3;
        a -= 3 * ileC;
        b -= 3 * ileC;
        if (a >= 2 && b >= 1) ileA++;
        else if (a >= 1 && b >= 2) ileA++;
        printf("%d\n", ileA + ileB + 2 * ileC);
    }
    
    return 0;
}