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
    
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n;
        scanf("%lld", &n);
        
        long long cur = 1;
        long long sum = 1;
        vector<long long> ans;
        while (sum < n) {
            debug(sum, cur);
            if (sum + cur * 2 == n || n - (sum + cur * 2) >= cur * 2) {
                debug("TAK\n");
                ans.push_back(cur);
                cur *= 2;
            } else {
                debug("NIE\n");
                if (n - sum - cur <= cur) {
                    ans.push_back(n - sum - cur);
                    cur += n - sum - cur;
                    break;
                } else {
                    ans.push_back((n - sum) / 2 - cur);
                    cur = (n - sum) / 2;
                }
            }
            sum += cur;
        }
        printf("%d\n", ans.size());
        for (auto x : ans) {
            printf("%lld ", x);
        }
        printf("\n");
    }
    
    return 0;
}