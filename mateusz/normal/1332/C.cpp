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

int n, k;
char word[N];
int cnt[N][150];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        scanf("%s", &word[0]);
        for (int i = 0; i < n; i++) {
            for (int j = 'a'; j <= 'z'; j++) {
                cnt[i % k][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            cnt[i % k][word[i]]++;
        }
        
        int ans = 0;
        for (int i = 0; i <= k - 1 - i; i++) {
            if (i == k - 1 - i) {
                int mx = 0;
                int sum = 0;
                for (char j = 'a'; j <= 'z'; j++) {
                    mx = max(mx, cnt[i][j]);
                    sum += cnt[i][j];
                }
                ans += sum - mx;
                break;
            }
            int mx = 0;
            int sum = 0;
            for (int j = 'a'; j <= 'z'; j++) {
                mx = max(mx, cnt[i][j] + cnt[k - 1 - i][j]);
                sum += cnt[i][j] + cnt[k - 1 - i][j];
            }
            ans += sum - mx;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}