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
int n, ans[N];
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int x;
        vector<int> cnt(n + 1, 0);
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            cnt[x]++;
        }
        
        int low = 1;
        int high = n;
        int res = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            auto cnt2 = cnt;
            priority_queue<pair<int, int>> Q;
            for (int i = 1; i <= n; i++) {
                if (cnt2[i] > 0) Q.push({cnt2[i], i});
            }
            
            bool good = true;
            for (int i = 1; i <= n; i++) {
                if (Q.empty()) {
                    good = false;
                    break;
                }
                int w = Q.top().second;
                Q.pop();
                cnt2[w]--;
                ans[i] = w;
                if (i - mid >= 1 && cnt2[ans[i - mid]] > 0) {
                    Q.push({cnt2[ans[i - mid]], ans[i - mid]});
                }
            }
            if (good) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        printf("%d\n", res);
    }
    
    return 0;
}