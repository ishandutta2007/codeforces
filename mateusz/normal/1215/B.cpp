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

int n;
int cnt[2];

int main() {
    
    scanf("%d", &n);
    
    long long ans1 = 0;
    long long ans2 = 0;
    int pref = 0;
    cnt[0]++;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (x < 0) {
            pref ^= 1;
        }
        ans1 += cnt[1 - pref];
        ans2 += cnt[pref];
        cnt[pref]++;
    }
    
    printf("%lld %lld\n", ans1, ans2);
    
    return 0;
}