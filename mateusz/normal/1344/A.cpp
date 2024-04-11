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

const int N = 200005;

int n, cnt[N], a[N];

int mod(int w) {
    int x = w % n;
    if (x < 0) {
        return n + x;
    }
    return x;
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        
        for (int i = 0; i < n; i++) {
            cnt[i] = 0;
        }
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            cnt[mod(i + a[i])]++;
        }
        
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) {
                found = true;
                break;
            }
        }
        
        printf(found ? "NO\n" : "YES\n");
    }
    
    return 0;
}