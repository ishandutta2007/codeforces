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
    
int n;
int tab[N], t[N];
    
int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }
    
    int ans = 0;
    for (int k = 0; k < 30; k++) {
        for (int i = 1; i <= n; i++) {
            t[i] = tab[i] % (1 << (k + 1));
        }
        sort(t + 1, t + 1 + n);
        int low = 0;
        int high = 0;
        int res = 0;
        int low2 = 0;
        for (int i = 1; i <= n; i++) {
            low++;
            high++;
            low2++;
            high = min(high, i - 1);
//             low2 = min(low2, i);
            while (low >= 2 && t[low - 1] + t[i] >= (1 << k)) low--;
            while (high >= low && (t[high] + t[i] >= (1 << (k + 1)))) high--;
            while (low2 - 1 >= high && t[low2 - 1] + t[i] >= (1 << (k + 1)) + (1 << k)) low2--;
            res ^= ((high % 2) ^ (low % 2) ^ 1) ^ ((i - 1 - low2 + 1) % 2);
            debug(k, i, t[i], low, high, res);
        }
        if (res % 2) {
            ans ^= (1 << k);
        }
    }
    printf("%d\n", ans);
    return 0;
}