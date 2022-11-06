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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 200005;

int n, val[N];
vector<int> positions[N];
int cnt[N];
int ans;

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        scanf("%d", &n);
        int mx = 0;
        for (int i = 1; i <= 200; i++) {
            positions[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &val[i]);
            positions[val[i]].push_back(i);
            mx = max(mx, val[i]);
            cnt[val[i]]++;
            ans = max(ans, cnt[val[i]]);
        }
        for (int i = 1; i <= mx; i++) {
            cnt[i] = 0;
        }
        for (int i = 1; i <= mx; i++) {
            int low = (positions[i].size() - 1) / 2;
            int high = positions[i].size() - low - 1;
            debug(i, low, high);
            while (low >= high) {
                low--;
                high++;
            }
            if (low < 0 || high >= positions[i].size()) {
                continue;
            }
            int maxi = 0;
            for (int j = positions[i][low] + 1; j < positions[i][high]; j++) {
                cnt[val[j]]++;
                maxi = max(maxi, cnt[val[j]]);
            }
            ans = max(ans, 2 * (low + 1) + maxi);
            low--;
            high++;
            while (low >= 0) {
                for (int j = positions[i][low] + 1; j <= positions[i][low + 1]; j++) {
                    cnt[val[j]]++;
                    maxi = max(maxi, cnt[val[j]]);
                }
                for (int j = positions[i][high - 1]; j < positions[i][high]; j++) {
                    cnt[val[j]]++;
                    maxi = max(maxi, cnt[val[j]]);
                }
                ans = max(ans, 2 * (low + 1) + maxi);
                low--;
                high++;
            }
            for (int i = 1; i <= mx; i++) {
                cnt[i] = 0;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}