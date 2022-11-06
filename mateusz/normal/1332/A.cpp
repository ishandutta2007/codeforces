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
        int a, b,c ,d;
        int x, y, xFrom, xTo, yFrom, yTo;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        scanf("%d %d %d %d %d %d", &x, &y, &xFrom, &yFrom, &xTo, &yTo);
        x -= xFrom;
        y -= yFrom;
        xTo -= xFrom;
        yTo -= yFrom;
        int xDelta = b - a;
        int yDelta = d - c;
        if (xTo == 0 && max(a, b) > 0) {
            printf("No\n");
            continue;
        }
        if (yTo == 0 && max(c, d) > 0) {
            printf("No\n");
            continue;
        }
        if (x + xDelta <= xTo && x + xDelta >= 0 && 
            y + yDelta <= yTo && y + yDelta >= 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
    }
    
    return 0;
}