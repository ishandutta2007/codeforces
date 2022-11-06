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

const int N = 300005;

int n;
int dp[N][4];
long long a[N];

int firstMoment = -1;
int cycleLen = -1;

int ruch(int w, int d, int type) {
    int val = max(0, w - d);
    return dp[val][type];
}

int mex(vector<int> v) {
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != i) {
            return i;
        }
    }
    return v.size();
}

int solve(long long w, int d) {
    if (w <= firstMoment + cycleLen) {
        return dp[w][d];
    }
    debug(w, d, dp[w][d]);
    w -= firstMoment;
    w %= cycleLen;
    w += firstMoment;
    debug(w, d, dp[w][d]);
    return dp[w][d];
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        firstMoment = -1;
        cycleLen = -1;
        for (int i = 1;; i++) {
            dp[i][0] = mex({ruch(i, x, 0), ruch(i, y, 1), ruch(i, z, 2)});
            dp[i][1] = mex({ruch(i, x, 0), ruch(i, z, 2)});
            dp[i][2] = mex({ruch(i, x, 0), ruch(i, y, 1)});
            
//             if (cycleLen != -1) continue;
            for (int j = i - 1; j >= 5; j--) {
                bool good = true;
                for (int k = 0; k < 6; k++) {
                    if (dp[i - k][0] == dp[j - k][0] && dp[i - k][1] == dp[j - k][1] && dp[i - k][2] == dp[j - k][2]) continue;
                    good = false;
                    break;
                }
                if (good) {
                    debug(i);
                    firstMoment = j;
                    cycleLen = i - j;
                    break;
                }
            }
            if (cycleLen != -1) break;
        }
        debug(firstMoment, cycleLen);
//         firstMoment = 1000;
        
        int xo = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            xo ^= solve(a[i], 0);
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if ((xo ^ solve(a[i], 0) ^ solve(max(0LL, a[i] - x), 0)) == 0) ans++;
            if ((xo ^ solve(a[i], 0) ^ solve(max(0LL, a[i] - y), 1)) == 0) ans++;
            if ((xo ^ solve(a[i], 0) ^ solve(max(0LL, a[i] - z), 2)) == 0) ans++;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}