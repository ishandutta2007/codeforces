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

void test() {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    
    if (x > y) swap(x, y);
    
    if (x == y && x == n) {
        printf("%d %d\n", n, n);
        return;
    }
    
    int k = x + y;
    int minPlace = max(1, k + 1 - n);
    int ans1 = n - minPlace;

    
    int maxPlace = min(n, k - 1);
    int ans2 = maxPlace;
    
    printf("%d %d\n", n - ans1, ans2);
    
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) test();
    
    return 0;
}