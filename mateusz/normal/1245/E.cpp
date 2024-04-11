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

int n;
int ladder[15][15];
pair<int, int> nxt[15][15];
long double dp[15][15];

int main() {
    
    n = 10;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &ladder[i][j]);
            if (i % 2 == 0) {
                if (j < n) {
                    nxt[i][j] = {i, j + 1};
                } else {
                    nxt[i][j] = {i - 1, j};
                }
            } else {
                if (j > 1) {
                    nxt[i][j] = {i, j - 1};
                } else {
                    nxt[i][j] = {i - 1, j};
                }
            }
        }
    }
    
    dp[1][1] = 0.0;
    
    dp[1][2] = 6.0 * (1 + dp[1][1] / 6.0);
    dp[1][3] = 6.0 / 2.0 * (1 + dp[1][1] / 6.0 + dp[1][2] / 6.0);
    dp[1][4] = 6.0 / 3.0 * (1 + dp[1][1] / 6.0 + dp[1][2] / 6.0 + dp[1][3] / 6.0);
    dp[1][5] = 6.0 / 4.0 * (1 + dp[1][1] / 6.0 + dp[1][2] / 6.0 + dp[1][3] / 6.0 + dp[1][4] / 6.0);
    dp[1][6] = 6.0 / 5.0 * (1 + dp[1][1] / 6.0 + dp[1][2] / 6.0 + dp[1][3] / 6.0 + dp[1][4] / 6.0 + dp[1][5] / 6.0);
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j <= 6) continue;
                int x = i;
                int y = j;
                for (int k = 1; k <= 6; k++) {
                    int newX = nxt[x][y].first;
                    int newY = nxt[x][y].second;
                    x = newX;
                    y = newY;
                    if (min(x, y) >= 1) {
                        if (ladder[x][y] > 0) {
                            dp[i][j] += min(dp[x][y], dp[x - ladder[x][y]][y]) / 6.0;
                        } else {
                            dp[i][j] += dp[x][y] / 6.0;
                        }
                    } else {
                        break;
                    }
                }
                dp[i][j] += 1;
            }
        } else {
            for (int j = n; j >= 1; j--) {
                int x = i;
                int y = j;
                for (int k = 1; k <= 6; k++) {
                    int newX = nxt[x][y].first;
                    int newY = nxt[x][y].second;
                    x = newX;
                    y = newY;
                    if (min(x, y) >= 1) {
                        if (ladder[x][y] > 0) {
                            dp[i][j] += min(dp[x][y], dp[x - ladder[x][y]][y]) / 6.0;
                        } else {
                            dp[i][j] += dp[x][y] / 6.0;
                        }
                    } else {
                        break;
                    }
                }
                dp[i][j] += 1;
            }
        }
    }
    
    printf("%.10Lf\n", dp[10][1]);
    
    
    return 0;
}