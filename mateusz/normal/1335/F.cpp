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

const int N = 1000005;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int n, m;
char row[N];
map<char, int> dir;
vector<pair<pair<int, int>, int> > cycles;

bool isBlack[N];
vector<vector<int>> dep;
vector<vector<char>> vis, board, dirs;

void DFS(int x, int y, int depth = 0) {
    dep[x][y] = depth;
    vis[x][y] = 1;
    int xx = x + dx[dir[dirs[x][y]]];
    int yy = y + dy[dir[dirs[x][y]]];
    if (vis[xx][yy] == 1) {
        cycles.push_back({{xx, yy}, dep[x][y] - dep[xx][yy] + 1});
    }
    if (vis[xx][yy] == 0) {
        DFS(xx, yy, depth + 1);
    }
    vis[x][y] = 2;
}

void DFS2(int x, int y, int len, int d = 0) {
    vis[x][y] = 1;
    debug(x, y, len, d);
    if (board[x][y] == '0') {
        isBlack[d] = true;
    }
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        debug(xx, yy);
        if (min(xx, yy) <= 0 || min(n - xx, m - yy) < 0) {
            continue;
        }
        if (vis[xx][yy]) continue;
        debug(xx, yy);
        int xxx = xx + dx[dir[dirs[xx][yy]]];
        int yyy = yy + dy[dir[dirs[xx][yy]]];
        debug(xxx, yyy);
        if (xxx != x || yyy != y) {
            continue;
        }
        DFS2(xx, yy, len, (d + 1) % len);
    }
}

int main() {
    dir['U'] = 0;
    dir['D'] = 3;
    dir['L'] = 1;
    dir['R'] = 2;
    int t;
    scanf("%d", &t);
    while (t--) {
        cycles.clear();
        scanf("%d %d", &n, &m);
        dep = vector<vector<int>>(n + 1);
        vis = vector<vector<char>>(n + 1);
        for (int i = 0; i < n + 1; i++) {
            vis[i] = vector<char>(m + 1);
            dep[i] = vector<int>(m + 1);
        }
        board = vector<vector<char>>(n + 1);
        dirs = vector<vector<char>>(n + 1);
        for (int i = 0; i < n + 1; i++) {
            board[i] = vector<char>(m + 1);
            dirs[i] = vector<char>(m + 1);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%s", &row[1]);
            for (int j = 1; j <= m; j++) {
                board[i][j] = row[j];
            }
        }
        for (int i = 1; i <= n; i++) {
            scanf("%s", &row[1]);
            for (int j = 1; j <= m; j++) {
                dirs[i][j] = row[j];
            }
        }
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= m; j++) {
//                 vis[i][j] = false;
//                 dep[i][j] = 0;
//             }
//         }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!vis[i][j]) {
                    DFS(i, j);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                vis[i][j] = false;
            }
        }
        int a1 = 0;
        int ans = 0;
        for (auto p : cycles) {
            int x = p.first.first;
            int y = p.first.second;
            int len = p.second;
            debug(x, y, len);
            a1 += len;
            DFS2(x, y, len);
            for (int i = 0; i < len; i++) {
                ans += isBlack[i];
                isBlack[i] = 0;
            }
        }
        printf("%d %d\n", a1, ans);
    }
    
    return 0;
}