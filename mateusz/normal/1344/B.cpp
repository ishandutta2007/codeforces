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

const int N = 1005, dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

int n, m;
char board[N][N];
bool vis[N][N];

void DFS(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (min(xx, yy) < 1 || min(n - xx, m - yy) < 0) {
            continue;
        }
        if (board[xx][yy] != '#' || vis[xx][yy]) continue;
        DFS(xx, yy);
    }
}

int main() {
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &board[i][1]);
    }    
    
    int cntZeroCol = 0, cntZeroRow = 0;
    for (int i = 1; i <= n; i++) {
        int cntBlack = 0;
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == '#' && board[i][j - 1] != '#') {
                cntBlack++;
            }
        }
        if (cntBlack > 1) {
            printf("-1\n");
            return 0;
        }
        if (cntBlack == 0) cntZeroRow++;
    }
    
    
    for (int i = 1; i <= m; i++) {
        int cntBlack = 0;
        for (int j = 1; j <= n; j++) {
            if (board[j][i] == '#' && board[j - 1][i] != '#') {
                cntBlack++;
            }
        }
        if (cntBlack > 1) {
            printf("-1\n");
            return 0;
        }
        if (cntBlack == 0) cntZeroCol++;
    }
    
    if (max(cntZeroCol, cntZeroRow) > 0 && min(cntZeroCol, cntZeroRow) == 0) {
        printf("-1\n");
        return 0;
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == '#' && !vis[i][j]) {
                ans++;
                DFS(i, j);
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}