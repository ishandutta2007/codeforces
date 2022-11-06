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

const int N = 505;

int K = 18;

int n, m, q;
char board[N][N];
int red[N][N], blue[N][N], green[N][N], yellow[N][N];
int redUp[N][N], redLeft[N][N], greenUp[N][N], greenRight[N][N], yellowLeft[N][N], yellowDown[N][N], blueRight[N][N], blueDown[N][N];
int corners[21][N][N];

int xFrom, xTo, yFrom, yTo;

int main() {
    
    scanf("%d %d %d", &n, &m, &q);
    K = min(K, min(n, m));
    for (int i = 1; i <= n; i++) {
        scanf("%s", &board[i][1]);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            redLeft[i][j] = board[i][j] == 'R' ? redLeft[i][j - 1] + 1 : 0;
            redUp[i][j] = board[i][j] == 'R' ? redUp[i - 1][j] + 1 : 0;
            red[i][j] = board[i][j] == 'R' ? min(1 + red[i - 1][j - 1], min(redLeft[i][j], redUp[i][j])) : 0;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            greenRight[i][j] = board[i][j] == 'G' ? greenRight[i][j + 1] + 1 : 0;
            greenUp[i][j] = board[i][j] == 'G' ? greenUp[i - 1][j] + 1 : 0;
            green[i][j] = board[i][j] == 'G' ? min(min(greenUp[i][j], greenRight[i][j]), 1 + green[i - 1][j + 1]) : 0;
        }
    }
    
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            yellowLeft[i][j] = board[i][j] == 'Y' ? 1 + yellowLeft[i][j - 1] : 0;
            yellowDown[i][j] = board[i][j] == 'Y' ? 1 + yellowDown[i + 1][j] : 0;
            yellow[i][j] = board[i][j] == 'Y' ? min(yellowLeft[i][j], min(yellowDown[i][j], 1 + yellow[i + 1][j - 1])) : 0;
        }
    }
    
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            blueRight[i][j] = board[i][j] == 'B' ? 1 + blueRight[i][j + 1] : 0;
            blueDown[i][j] = board[i][j] == 'B' ? 1 + blueDown[i + 1][j] : 0;
            blue[i][j] = board[i][j] == 'B' ? min(blueRight[i][j], min(blueDown[i][j], 1 + blue[i + 1][j + 1])) : 0;
        }
    }

    vector<pair<pair<int, int>, int> > bigSquares;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int len = min(min(red[i][j], green[i][j + 1]), min(yellow[i + 1][j], blue[i + 1][j + 1]));
            if (len > K) {
                bigSquares.push_back({{i, j}, len});
            } else {
                for (int k = len; k >= 1; k--) {
                    corners[k][i - k + 1][j - k + 1] = 1;
                }
            }
        }
    }
    
    for (int k = 1; k <= K; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                corners[k][i][j] += corners[k][i - 1][j] + corners[k][i][j - 1] - corners[k][i - 1][j - 1];
            }
        }
    }
    
    while (q--) {
        scanf("%d %d %d %d", &xFrom, &yFrom, &xTo, &yTo);
        
        int best = 0;
        for (auto p : bigSquares) {
            int x = p.first.first;
            int y = p.first.second;
            int r = p.second;
            r = min(r, 
                min(min(x - xFrom + 1,
                        xTo - x),
                    min(y - yFrom + 1,
                        yTo - y))
            );
            best = max(best, 2 * r);
        }
        
        for (int k = min(K, min(yTo - yFrom + 1, xTo - xFrom + 1) / 2); k >= 1; k--) {
            if (corners[k][xTo - 2 * k + 1][yTo - 2 * k + 1] - corners[k][xFrom - 1][yTo - 2 * k + 1] - corners[k][xTo - 2 * k + 1][yFrom - 1] + corners[k][xFrom - 1][yFrom - 1] > 0) {
                best = max(best, 2 * k);
                break;
            }
        }
        
        printf("%d\n", best * best);
        
    }
    return 0;
}