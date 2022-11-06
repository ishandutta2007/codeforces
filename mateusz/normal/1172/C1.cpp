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

const int N = 55, M = 998244353;

int sumLike = 0, sumDontLike = 0;

int n, m, like[N], weight[N];
int dp[N][N][N];

void add(int &w, int u) {
    w += u;
    if (w >= M) {
        w -= M;
    }
}

int mul(int w, int u) {
    return (long long)w * u % M;
}

int power(int a, int k) {
    if (k == 0) {
        return 1;
    }
    return mul(power(mul(a, a), k / 2), k % 2 ? a : 1);
}

int inv(int w) {
    return power(w, M - 2);
}

int solve(int w) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= m; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= (like[w] ? j : i - j); k++) {
                if (like[w]) {
                    // Choosing him
                    int total = sumLike + sumDontLike + j - 1 - (i - 1 - j + 1);
                    dp[i][j][k] = mul(mul(weight[w] + k - 1, inv(total)), dp[i - 1][j - 1][k - 1]);
                    // Choosing liked
                    add(dp[i][j][k], mul(mul(sumLike + j - 1 - (weight[w] + k), inv(total)), dp[i - 1][j - 1][k]));
                    // Choosing not liked
                    total = sumLike + sumDontLike + j - (i - 1 - j);
                    add(dp[i][j][k], mul(mul(total - sumLike - j, inv(total)), dp[i - 1][j][k]));
                } else {
                    // Choosing him
                    int total = sumLike + sumDontLike + j - (i - 1 - j);
                    dp[i][j][k] = mul(mul(weight[w] - k + 1, inv(total)), dp[i - 1][j][k - 1]);
                    // Choosing liked
                    total = sumLike + sumDontLike + j - 1 - (i - 1 - j + 1);
                    add(dp[i][j][k], mul(mul(sumLike + j - 1, inv(total)), dp[i - 1][j - 1][k]));
                    // Choosing not liked
                    total = sumLike + sumDontLike + j - (i - 1 - j);
                    add(dp[i][j][k], mul(mul(total - sumLike - j - (weight[w] - k), inv(total)), dp[i - 1][j][k]));
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            add(ans, mul(dp[m][i][j], weight[w] + (like[w] ? j : -j)));
        }
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &like[i]);
    }
    
    sumLike = 0;
    sumDontLike = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        if (like[i]) sumLike += weight[i];
        else sumDontLike += weight[i];
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d\n", solve(i));
    }
    
    return 0;
}