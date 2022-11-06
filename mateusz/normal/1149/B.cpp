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

const int N = 100005, M = 255, A = 30;

int n, m;
int dp[M][M][M];
int firstRight[A][N];
string first, second, third;
char word[N];

void computeDp(int i, int j, int k) {
    if (i > 0) {
        dp[i][j][k] = min(dp[i][j][k], firstRight[first[i - 1]][min(n + 1, dp[i - 1][j][k] + 1)]);
    }
    if (j > 0) {
        dp[i][j][k] = min(dp[i][j][k], firstRight[second[j - 1]][min(n + 1, dp[i][j - 1][k] + 1)]);
    }
    if (k > 0) {
        dp[i][j][k] = min(dp[i][j][k], firstRight[third[k - 1]][min(n + 1, dp[i][j][k - 1] + 1)]);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int INF = n + 1;
    scanf("%s", &word[1]);
    for (int i = 1; i <= n; i++) {
        word[i] -= 'a';
    }
    for (int i = 0; i < A; i++) {
        firstRight[i][n + 1] = n + 1;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < A; j++) {
            firstRight[j][i] = firstRight[j][i + 1];
        }
        firstRight[word[i]][i] = i;
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    
    while (m--) {
        char type, c;
        int id;
        scanf(" %c %d", &type, &id);
        if (type == '+') {
            scanf(" %c", &c);
            c -= 'a';
            if (id == 1) {
                first += c;
                for (int j = 0; j < M; j++) {
                    for (int k = 0; k < M; k++) {
                        dp[first.size()][j][k] = INF;
                    }
                }
                for (int j = 0; j <= second.size(); j++) {
                    for (int k = 0; k <= third.size(); k++) {
                        int i = first.size();
                        computeDp(i, j, k);
                    }
                }
            } else if (id == 2) {
                second += c;
                for (int i = 0; i < M; i++) {
                    for (int k = 0; k < M; k++) {
                        dp[i][second.size()][k] = INF;
                    }
                }
                for (int i = 0; i <= first.size(); i++) {
                    for (int k = 0; k <= third.size(); k++) {
                        int j = second.size();
                        computeDp(i, j, k);
                    }
                }
            } else {
                third += c;
                for (int i = 0; i < M; i++) {
                    for (int j = 0; j < M; j++) {
                        dp[i][j][third.size()] = INF;
                    }
                }
                for (int i = 0; i <= first.size(); i++) {
                    for (int j = 0; j <= second.size(); j++) {
                        int k = third.size();
                        computeDp(i, j, k);
                    }
                }
            }
        } else {
            if (id == 1) {
                 for (int j = 0; j < M; j++) {
                    for (int k = 0; k < M; k++) {
                        dp[first.size()][j][k] = INF;
                    }
                }
                first.pop_back();
            }
            else if (id == 2) {
                for (int i = 0; i < M; i++) {
                    for (int k = 0; k < M; k++) {
                        dp[i][second.size()][k] = INF;
                    }
                }
                second.pop_back();
            }
            else {
                for (int i = 0; i < M; i++) {
                    for (int j = 0; j < M; j++) {
                        dp[i][j][third.size()] = INF;
                    }
                }
                third.pop_back();
            }
        }
        printf(dp[first.size()][second.size()][third.size()] <= n ? "YES\n" : "NO\n");
    }
    
    return 0;
}