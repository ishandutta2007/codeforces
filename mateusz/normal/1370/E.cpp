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
int n, x;
char s[N], t[N];
int main() {
    
    scanf("%d", &n);
    
    scanf("%s", &s[1]);
    scanf("%s", &t[1]);
    
    int bal = 0;
    int maxBal = 0;
    int minBal = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == t[i]) continue;
        if (s[i] == '0') {
            bal--;
            minBal = min(minBal, bal);
        } else {
            bal++;
            maxBal = max(maxBal, bal);
        }
    }
    if (bal != 0) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", maxBal - minBal);
    
    return 0;
}