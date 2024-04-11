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

int n, m, k;
int audience[N];
int cost[N][10];
long long dp[150][N], pref[150][N];
int t[N], per[N];

int main() {
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &audience[i]);
        t[i] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    
    sort(t + 1, t + n + 1, [&](int a, int b) { return audience[a] > audience[b]; });
    
    long long firstK = 0;
    for (int i = 1; i <= k; i++) {
        firstK += audience[t[i]];
    }
    
    long long ans = 0;
    pref[0][0] = firstK;
    for (int i = 1; i <= n; i++) {
        pref[0][i] = firstK;
    }
    for (int mask = 1; mask < (1 << m); mask++) {
        for (int j = 0; j < m; j++) {
            if (((1 << j) & mask) == 0) continue;
            int ile = __builtin_popcount(mask);
            for (int i = 1; i <= n; i++) {
                int w = t[i];
                dp[mask][i] = max(dp[mask][i], pref[mask ^ (1 << j)][i - 1] + cost[w][j] + (i <= k + ile - 1 ? -audience[w] + audience[t[k + ile]] : 0));
                pref[mask][i] = max(pref[mask][i - 1], dp[mask][i]);
            }
        }
    }
    ans = pref[(1 << m) - 1][n];
    
    printf("%lld\n", ans);
    return 0;
}