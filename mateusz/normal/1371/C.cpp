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

long long a, b, n, m;
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld %lld %lld", &a, &b, &n, &m);
        if (n + m > a + b) {
            printf("No\n");
            continue;
        }
        printf(n > a + b || m > min(a, b) ? "No\n" : "Yes\n");
        continue;
        int diff = max(a, b) - min(a, b);
        n -= diff;
        if (n < 0) {
            printf("No\n");
            continue;
        }
        if (a > b) a -= diff;
        else b -= diff;
        if (min(n, m) > a) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
        
    }
    
    return 0;
}