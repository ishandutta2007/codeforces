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

int cnt[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        set<int> vals;
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            vals.insert(x);
            cnt[x]++;
        }
        int valsNo = vals.size();
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, min(cnt[i], valsNo - 1));
            ans = max(ans, min(cnt[i] - 1, valsNo));
            cnt[i] = 0;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}