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

int n, T, cost[3], diff[N], total[3], t[N], tim[N];

int main() {
    
    int tests;
    scanf("%d", &tests);
    while (tests--) {
        scanf("%d %d %d %d", &n, &T, &cost[0], &cost[1]);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &diff[i]);
            total[diff[i]]++;
            t[i] = i;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &tim[i]);
        }
        sort(t + 1, t + 1 + n, [&](int a, int b) { return tim[a] < tim[b]; });
        tim[n + 1] = T;
        t[n + 1] = n + 1;
        long long totalTime = 0;
        int ans = 0;
        diff[0] = 2;
        for (int i = 0; i <= n; i++) {
            totalTime += cost[diff[t[i]]];
            total[diff[t[i]]]--;
            if (tim[t[i]] == tim[t[i + 1]]) {
                continue;
            }
            
            if (totalTime >= tim[t[i + 1]]) continue;
            int remainingTime = max(0LL, tim[t[i + 1]] - 1 - totalTime);
            debug(remainingTime);
            int easyTasks = min(total[0], remainingTime / cost[0]);
            debug(easyTasks);
            remainingTime -= (long long)easyTasks * cost[0];
            debug(remainingTime);
            int hardTasks = min(total[1], remainingTime / cost[1]);
            debug(hardTasks);
            ans = max(ans, i + easyTasks + hardTasks);
        }
        if (totalTime <= T) {
            ans = max(ans, n);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}