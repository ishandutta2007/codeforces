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

int n;
int height[N], cost[N], t[N], myRange[N];

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &height[i], &cost[i]);
        t[i] = i;
    }
    
    sort(t + 1, t + 1 + n, [&](int a, int b) { return height[a] < height[b]; });
    
    for (int i = 1; i <= n; i++) {
        myRange[i] = height[i] + cost[i];
    }
    
    long long ans = 0;
    
    int maxRange = myRange[t[1]];
    
    maxRange = myRange[t[1]];
    for (int i = 1; i <= n; i++) {
        int w = t[i];
        if (height[w] > maxRange) {
            ans += height[w] - maxRange;
        }
        maxRange = max(maxRange, myRange[w]);
        ans += cost[w];
    }
    
    printf("%lld\n", ans);
    
    return 0;
}