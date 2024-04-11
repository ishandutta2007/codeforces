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
int n, k;
char table[N];
int pref[N];
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        scanf("%s", &table[1]);
        for (int i = 1; i <= n; i++) {
            table[i] -= '0';
            pref[i] = pref[i - 1] + table[i]; 
        }
        for (int i = n + 1; i <= n + k + 1; i++) {
            pref[i] = pref[i - 1];
        }
        int sumLeft = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (table[i] == 0 && sumLeft + pref[i + k] - pref[i] == 0) {
                table[i] = 1;
                ans++;
            }
                
            sumLeft += table[i];
            sumLeft -= i - k >= 1 ? table[i - k] : 0;
        }
        printf("%d\n", ans);
        
    }
    
    return 0;
}