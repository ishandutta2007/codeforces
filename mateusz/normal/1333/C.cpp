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

int n, a[N];

int main() {
    
    scanf("%d", &n);
    long long prefSum = 0;
    map<long long, int> begs;
    begs[0] = 0;
    int lastBeg = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        prefSum += a[i];
        if (begs.count(prefSum)) {
            lastBeg = max(lastBeg, begs[prefSum] + 2);
        }
        begs[prefSum] = i;
        ans += max(0, (i - lastBeg + 1));
    }
    
    printf("%lld\n", ans);
    
    return 0;
}