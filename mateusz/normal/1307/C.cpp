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
  return os <<"("<<P.st <<","<<P.nd <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 100005;

char word[N];
int cnt[1005];
long long dp[505][505];

int main() {
    
    scanf("%s", &word[1]);
    
    int n = strlen(word + 1);
    
    for (int i = n; i >= 1; i--) {
        for (int j = 'a'; j <= 'z'; j++) {
            dp[word[i]][j] += cnt[j];
        }
        cnt[word[i]]++;
    }
    
    long long ans = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            ans = max(ans, dp[i][j]);
        }
        ans = max(ans, (long long)cnt[i]);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}