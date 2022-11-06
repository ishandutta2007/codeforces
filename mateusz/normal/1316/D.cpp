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

const int N = 1005;

int n;
int stopx[N][N], stopy[N][N];
bool vis[N][N];
pair<int, int> par[N][N];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};

void DFS(int x, int y) {
    vis[x][y] = true;
    for (int k = 0; k < 4; k++) {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (min(xx, yy) < 1 || max(xx, yy) > n || vis[xx][yy] || stopx[xx][yy] != stopx[x][y] || stopy[xx][yy] != stopy[x][y]) continue;
        par[xx][yy] = {x, y};
        DFS(xx, yy);
    }
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d %d", &stopx[i][j], &stopy[i][j]);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[i][j]) {
                continue;
            }
            if (stopx[i][j] == -1) {
                bool good = false;
                for (int k = 0; k < 4; k++) {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    if (min(xx, yy) < 1 || max(xx, yy) > n) continue;
                    if (stopx[xx][yy] == -1) {
                        vis[i][j] = true;
                        par[i][j] = {xx, yy};
                        vis[xx][yy] = true;
                        par[xx][yy] = {i, j};
                        DFS(i, j);
                        DFS(xx, yy);
                        good = true;
                        break;
                    }
                }
                if (!good) {
                    printf("INVALID\n");
                    return 0;
                }
            } else {
                if (stopx[i][j] == i && stopy[i][j] == j) {
                    par[i][j] = {i, j};
                    DFS(i, j);
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!vis[i][j] && stopx[i][j] != -1 && (stopx[i][j] != i || stopy[i][j] != j)) {
                printf("INVALID\n");
                return 0;
            }
        }
    }
    
    printf("VALID\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            debug(i, j, par[i][j]);
            if (par[i][j] == make_pair(i, j)) {
                printf("X");
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int xx = i + dx[k];
                int yy = j + dy[k];
                if (par[i][j] == make_pair(xx, yy)) {
                    printf("%c", dir[k]);
                    break;
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}