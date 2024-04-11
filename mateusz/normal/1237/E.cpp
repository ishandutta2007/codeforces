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

const int N = 1000005, M = 998244353;

int n, P;
int cnt;
bool bad;

int DFS(int w, int level, int myColor, int last = 0) {
    cnt++;
    if (level == P - 1) {
        if (last == myColor) {
            cnt++;
        }
        return myColor;
    }
    
    last = DFS(2 * w, level + 1, 1 - myColor, last);
    if (myColor == last) {
        bad = true;
        return -1;
    }
    return DFS(2 * w + 1, level + 1, myColor, myColor);
}

int main() {
    
    scanf("%d", &n);
    
    P = 1;
    while ((1 << (P + 1)) - 1 <= n) P++;
    
    DFS(1, 0, 0);
    int ans = 0;
    if (bad == false && cnt == n) {
        ans++;
    }
    
    bad = false;
    cnt = 0;
    DFS(1, 0, 1);
    if (bad == false && cnt == n) {
        ans++;
    }
    
    printf("%d\n", ans);
    return 0;
}