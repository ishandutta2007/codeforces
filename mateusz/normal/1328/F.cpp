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

int n, k, x;

int main() {
    
    scanf("%d %d", &n, &k);
    map<int, int> cnt, cntSmaller;
    map<int, long long> prefCost;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    long long curPref = 0;
    int cntPref = 0;
    for (auto p : cnt) {
        int val = p.first;
        int ile = p.second;
        if (ile >= k) {
            printf("0\n");
            return 0;
        }
        long long cost = (long long)(val - 1) * (cntPref) - curPref;
        prefCost[val] = cost;
        cntSmaller[val] = cntPref;
        cntPref += ile;
        curPref += (long long)ile * val;
    }
    
    long long ans = 1e18;
    
    curPref = 0;
    cntPref = 0;
    for (auto it = cnt.rbegin(); it != cnt.rend(); ++it) {
        int val = it->first;
        int ile = it->second;
        long long cost = curPref - (long long)(val + 1) * (cntPref);
        long long costsmaller = prefCost[val];
        int cntsmaller = cntSmaller[val];
        if (cntsmaller + ile >= k) {
            ans = min(ans, costsmaller + k - ile);
        }
        if (cntPref + ile >= k) {
            ans = min(ans, cost + k - ile);
        }
        if (cntPref + cntsmaller + ile >= k) {
            ans = min(ans, costsmaller + cost + k - ile);
        }
        cntPref += ile;
        curPref += (long long)ile * val;
    }
    
    printf("%lld\n", ans);
    
    
    return 0;
}