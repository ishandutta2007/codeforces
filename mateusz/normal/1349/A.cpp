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

const int M = 200000;

int n;
int sieve[2 * M];
int a[M], total[2 * M], mini[2 * M], mini2[2 * M];

int main() {
    
    
    for (int i = 2; i <= M; i++) {
        if (sieve[i]) continue;
        for (int j = i; j <= M; j += i) {
            sieve[j] = i;
        }
    }
    
    for (int i = 2; i <= M; i++) {
        mini[i] = mini2[i] = 1e9;
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        int w = a[i];
        vector<int> factors;
        while (w > 1) {
            factors.push_back(sieve[w]);
            w /= sieve[w];
        }
        sort(factors.begin(), factors.end());
        int cnt = 0;
        for (int j = 0; j < factors.size(); j++) {
            cnt++;
            if (j + 1 == factors.size() || factors[j + 1] != factors[j]) {
                int p = factors[j];
                if (cnt < mini[p]) {
                    mini2[p] = mini[p];
                    mini[p] = cnt;
                } else if (cnt < mini2[p]) {
                    mini2[p] = cnt;
                }
                total[p]++;
                cnt = 0;
            }
        }
    }
    long long ans = 1;
    for (int i = 2; i <= M; i++) {
        if (sieve[i] != i) continue;
        if (total[i] <= n - 2) {
            continue;
        }
        if (total[i] == n - 1) {
            for (int j = 1; j <= mini[i]; j++) {
                ans *= i;
            }
        } else {
            for (int j = 1; j <= mini2[i]; j++) {
                ans *= i;
            }
        }
    }
    
    printf("%lld\n", ans);
    return 0;
}