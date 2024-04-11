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

const int N = 105;

int n, m, from[N], to[N], required[N];

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &from[i], &to[i], &required[i]);
    }
    
    
    vector<int> ans;
    for (int day = 1; day <= n; day++) {
        int best = 0;
        
        bool passes = false;
        for (int i = 1; i <= m; i++) {
            if (to[i] == day) {
                if (required[i] > 0) {
                    printf("-1\n");
                    return 0;
                }
                ans.push_back(m + 1);
                debug("passing ", i);
                passes = true;
                break;
            }
        }
        if (passes) continue;
        
        for (int i = 1; i <= m; i++) {
            if (day > to[i] || required[i] == 0 || day < from[i]) continue;
            if (best == 0 || to[i] - day - required[i] < to[best] - day - required[best]) {
                best = i;
            }
        }
        ans.push_back(best);
        required[best]--;
        debug(best);
    }
    
    for (int x : ans) {
        printf("%d ", x);
    }
    printf("\n");
    
    return 0;
}