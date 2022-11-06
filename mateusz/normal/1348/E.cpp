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

const int N = 505;
const long long INF = 1e18;

int n, k, a[N], b[N];
pair<long long, int> dp[N];
pair<long long, int> dp2[N];
int fullA[N], remA[N], fullB[N], remB[N];

int main() {
    
    scanf("%d %d", &n, &k);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        fullA[i] = a[i] / k;
        remA[i] = a[i] % k;
        fullB[i] = b[i] / k;
        remB[i] = b[i] % k;
    }
    
    for (int i = 1; i < k; i++) {
        dp[i] = {-INF, 0};
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            dp2[j] = dp[j];
        }
        for (int m = 0; m < k; m++) {
            {
            int ileA = 0;
            int ileB = 0;
            if (ileA > a[i]) {
                continue;
            }
            if (ileB > b[i]) {
                continue;
            }
            auto wynik = dp[m].first;
            long long newA = m + (a[i] - ileA);
            long long newB = dp[m].second + (b[i] - ileB);
            wynik += newA / k;
            wynik += newB / k;
            newA %= k;
            newB %= k;
            dp2[newA] = max(dp2[newA], make_pair(wynik, (int)newB));
            }
            int ileA = 0;;
            int ileB = k;
//             if (ileA > a[i]) {
//                 continue;
//             }
//             if (ileB > b[i]) {
//                 continue;
//             }
            auto wynik = dp[m].first;
            long long newA = m + (a[i] - ileA);
            long long newB = dp[m].second + (b[i] - ileB);
            wynik += newA / k;
            wynik += newB / k;
            newA %= k;
            newB %= k;
            if (ileA <= a[i] && ileB <= b[i]) {
                dp2[newA] = max(dp2[newA], make_pair(wynik + 1, (int)newB));
            }
            for (int j = min(0, b[i]) + 1; j < k; j++) {
                int ileA = j;
                int ileB = k - j;
              
//                 auto wynik = dp[m].first;
                newA--;
                newB++;
                if (newB >= k) {
                    wynik++;
                    newB = 0;
                }
                if (newA < 0) {
                    wynik--;
                    newA = k - 1;
                }
                if (ileA <= a[i] && ileB <= b[i])
                dp2[newA] = max(dp2[newA], make_pair(wynik + 1, (int)newB));
            }

        }
        
        for (int j = 0; j < k; j++) {
            dp[j] = dp2[j];
        }
    }
    
    long long ans = 0;
    for (int j = 0; j < k; j++) {
        ans = max(ans, dp[j].first);
    }
    printf("%lld\n", ans);
    
    return 0;
}