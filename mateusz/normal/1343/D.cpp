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

const int N = 400005;

int a[N];
int tab[N];

void insert(int from, int to, int val) {
    if (to < from) return;
    tab[from] += val;
    tab[to + 1] -= val;
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        
        map<int, int> cntSums;
        for (int i = 1; i <= n / 2; i++) {
            int w = a[i];
            int u = a[n - i + 1];
            int sum = w + u;
            int mini = min(w, u) + 1;
            int maxi = k + max(w, u);
            insert(2, mini - 1, 2);
            insert(mini, sum - 1, 1);
            insert(sum + 1, maxi, 1);
            insert(maxi + 1, 2 * k, 2);
        }
        
        int ans = 1e9;
        int sum = 0;
        for (int i = 2; i <= 2 * k; i++) {
            sum += tab[i];
            tab[i] = 0;
            ans = min(ans, sum);
        }
        tab[2 * k + 1] = tab[2 * k + 2] = 0;
        printf("%d\n", ans);
    }
    
    return 0;
}