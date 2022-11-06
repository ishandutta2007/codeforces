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
    
    int n, m, k;
    
    scanf("%d %d %d", &n, &m, &k);
    
    string ans;
    for (int i = 1; i < n; i++) {
        ans += 'U';
    }
    for (int i = 1; i < m; i++) {
        ans += 'L';
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            if (i % 2 == 1) {
                ans += 'R';
            } else {
                ans += 'L';
            }
        }
        if (i < n) {
            ans += 'D';
        }
    }
    
    cout << ans.size() << endl;
    cout << ans << endl;
    
    return 0;
}