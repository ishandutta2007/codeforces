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

int n, m, a, b, q;
vector<int> bigger[N];
int smaller[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        bigger[a].push_back(b);
        smaller[b]++;
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int u : bigger[i]) {
            ans += bigger[u].size();
        }
    }
    
    printf("%lld\n", ans);
    scanf("%d", &q);
    while (q--) {
        int w;
        scanf("%d", &w);
        for (int u : bigger[w]) {
            ans -= bigger[u].size();
            ans -= smaller[w];
            ans += smaller[u] - 1;
            smaller[u]--;
            bigger[u].push_back(w);
        }
        smaller[w] += bigger[w].size();
        bigger[w].clear();
        printf("%lld\n", ans);
    }
    
    return 0;
}