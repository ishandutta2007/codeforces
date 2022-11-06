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
// pref[b] - pref[a] == b - a
// pref[b] - b = pref[a] - a
int n;
char word[N];
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s", &word[1]);
        map<int, int> cnt;
        int sum = 0;
        cnt[0]++;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            sum += word[i] - '0';
            ans += cnt[sum - i];
            cnt[sum - i]++;
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}