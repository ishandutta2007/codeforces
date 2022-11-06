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

int n, p[N], whereIs[N], value[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            value[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            whereIs[p[i]]= i ;
        }
        
        bool bad = false;
        for (int i = 1; i <= n; i++) {
            if (value[whereIs[i]] == 0) {
                int w = i;
                for (int j = whereIs[i]; j <= n && value[j] == 0; j++) {
                    value[j] = w++;
                }
            } else {
                if (value[whereIs[i]] != i) {
                    bad = true;
                    break;
                }
            }
        }
        printf(bad ? "No\n" : "Yes\n");
    }
    
    return 0;
}