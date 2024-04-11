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
        int n, k;
        scanf("%d %d", &n, &k);
        set<int> values;
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            values.insert(x);
        }
        if (values.size() > k) {
            printf("-1\n");
            continue;
        }
        
        vector<int> toAdd;
        for (auto x : values) {
            toAdd.push_back(x);
        }
        while (toAdd.size() < k) toAdd.push_back(*values.begin());
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            for (int x : toAdd) {
                ans.push_back(x);
            }
        }
        printf("%d\n", ans.size());
        for (int x : ans) {
            printf("%d ", x);
        }
        printf("\n");
        
    }
    
    return 0;
}