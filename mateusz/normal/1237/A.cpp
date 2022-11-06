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

int n, tab[N];

int main() {
    
    scanf("%d", &n);
    
    int dir = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        if (tab[i] % 2 == 0) {
            printf("%d\n", tab[i] / 2);
            continue;
        }
        if (dir == 1 && tab[i] >= 0) {
            printf("%d\n", tab[i] / 2 + 1);
        } else if (dir == 0 && tab[i] >= 0) {
            printf("%d\n", tab[i] / 2);
        } else if (dir == 1 && tab[i] < 0) {
            printf("%d\n", tab[i] / 2);
        } else {
            printf("%d\n", tab[i] / 2 - 1);
        }
        
        dir = 1 - dir;
    }
    
    return 0;
}