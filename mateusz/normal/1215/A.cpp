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
    
    int a1, a2, k1, k2, n;
    
    scanf("%d %d", &a1, &a2);
    scanf("%d %d", &k1, &k2);
    if (k1 > k2) {
        swap(a1, a2);
        swap(k1, k2);
    }
    scanf("%d", &n);
    
    int ileSmall = min(a1, n / k1);
    int rest = n - ileSmall * k1;
    
    int ileLarge = min(a2, rest / k2);
    
    int maxi = ileSmall + ileLarge;
    
    int mini = min(a1 + a2, max(0, n - a1 * (k1 - 1) - a2 * (k2 - 1)));
    
    printf("%d %d\n", mini, maxi);
    
    
    return 0;
}