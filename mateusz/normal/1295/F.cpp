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

const int N = 155, M = 998244353;

int n;
int dp[N][N];
int l[N], r[N];

void add(int &w, int u) {
    w += u;
    if (w >= M) {
        w -= M;
    }
}

int mul(int w, int u) {
    return (long long)w * u % M;
}

int powaer(int a, int k) {
    if (k == 0) return 1;
    return mul(powaer(mul(a, a), k / 2), k % 2 ? a : 1);
}

int inv(int w) {
    return powaer(w, M - 2);
}

int newton(int n, int k) {
    if (n < 0) return 0;
    if (k > n) return 0;
    int nom = 1, denom = 1;
    for (int i = 1; i <= k; i++) {
        nom = mul(nom, n - i + 1);
        denom = mul(denom, i);
    }
    return mul(nom, inv(denom));
}

int main() {
    
    scanf("%d", &n);
    
    vector<int> moments;
    int total = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &l[i], &r[i]);
        moments.push_back(l[i]);
        moments.push_back(r[i] + 1);
        total = mul(total, r[i] - l[i] + 1);
    }
    reverse(l + 1, l + 1 + n);
    reverse(r + 1, r + 1 + n);
    
    sort(moments.begin(), moments.end());
    moments.resize(unique(moments.begin(), moments.end()) - moments.begin());
    for (int i = 0; i < moments.size(); i++) {
        dp[n + 1][i] = 1;
    }
//     moments.push_back(moments.back());
//     moments.back()++;
    for (int i = n; i >= 1; i--) {
        for (int block = (int)moments.size() - 2; block >= 0; block--) {
            dp[i][block] = 0;
            for (int j = i; j <= n; j++) {
//                 debug(i, j, block, l[j], r[j], moments[block], moments[block + 1]);
                if (!(l[j] <= moments[block] && r[j] >= moments[block + 1] - 1)) {
                    break;
                }
                add(dp[i][block], mul(newton(moments[block + 1] - moments[block] + (j - i + 1) - 1, j - i + 1), dp[j + 1][block + 1]));
            }
            debug(i, block, dp[i][block]);
            add(dp[i][block], dp[i][block + 1]);
        }
    }
    
    int ans = dp[1][0];
//     for (int i = 0; i < moments.size(); i++) {
//         add(ans, dp[1][i]);
//     }
    debug(ans);
    debug(total);
    printf("%d\n", mul(ans, inv(total)));
    
    return 0;
}