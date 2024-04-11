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

const int N = 200005, M = 998244353;

int n, k;
int p[N];

int main() {
    
    scanf("%d %d", &n, &k);
    
    vector<int> pos;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        if (p[i] + k > n) {
            pos.push_back(i);
            ans += p[i];
        }
    }
    
    long long ways = 1;
    for (int i = 0; i < pos.size(); i++) {
        if (i + 1 < pos.size()) {
            ways *= (pos[i + 1] - pos[i]);
            ways %= M;
        }
    }
    
    printf("%lld %lld\n", ans, ways);
    
    return 0;
}