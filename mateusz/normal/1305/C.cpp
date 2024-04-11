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

int n, m;

int tab[N];
int cnt[N];
int orig[N];

int main() {
    
    scanf("%d %d", &n, &m);
    
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        orig[i] = tab[i];
        tab[i] %= m;
        if (cnt[tab[i]] > 0) {
            printf("0\n");
            return 0;
        }
        for (int j = 1; j < i; j++) {
            int a = orig[j];
            int b = orig[i];
            if (a > b) swap(a, b);
            ans = (ans * (long long)(b - a)) % m;
        }
        cnt[tab[i]]++;
    }
    
    printf("%d\n", ans);
   
    return 0;
}