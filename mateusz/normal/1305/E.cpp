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

const int N = 100005;

int n, m, a[N];

int main() {
    
    scanf("%d %d", &n, &m);
    
    
    bool zero = false;
    a[1] = 1;
    a[2] = 2;
    int maxi = 2;
    for (int i = 3; i <= n; i++) {
        if (zero) {
            a[i] = 1000000000 - (n - i) * (a[maxi] + a[maxi - 1] + 1);
            continue;
        }
        if ((i - 1) / 2 <= m) {
            m -= (i - 1) / 2;
            a[i] = i;
            continue;
        } else {
            a[i] = i + ((i - 1) / 2 - m) * 2;
            zero = true;
            maxi = i;
            m = 0;
        }
    }
    if (m > 0) {
        printf("-1\n");
        return 0;
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}