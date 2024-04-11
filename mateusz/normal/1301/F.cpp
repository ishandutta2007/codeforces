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

const int N = 1005, K = 45;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, k, q, r1, c1, r2, c2;

int color[N][N];
bool vis[K][N][N];
int dist[K][N][N];
bool done[K];
vector<pair<int, int> > cells[K];

void BFS(int c) {
    queue<pair<int, int> > Q;
    for (auto p : cells[c]) {
        Q.push({p.first, p.second});
        vis[c][p.first][p.second] = 1;
        dist[c][p.first][p.second] = 0;
    }
    for (int col = 1; col <= k; col++) {
        done[col] = false;
    }
    done[c] = true;
    
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        if (!done[color[x][y]]) {
            done[color[x][y]] = true;
            for (auto p : cells[color[x][y]]) {
                int xx = p.first;
                int yy = p.second;
                if (!vis[c][xx][yy]) {
                    vis[c][xx][yy] = true;
                    dist[c][xx][yy] = dist[c][x][y] + 1;
                    Q.push({xx, yy});
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (min(xx, yy) < 1 || xx > n || yy > m) continue;
            if (!vis[c][xx][yy]) {
                vis[c][xx][yy] = true;
                dist[c][xx][yy] = dist[c][x][y] + 1;
                Q.push({xx, yy});
            }
        }
    }
}

int main() {
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &color[i][j]);
            cells[color[i][j]].push_back({i, j});
        }
    }
    
    for (int c = 1; c <= k; c++) {
        BFS(c);
    }
    
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        int ans = abs(r1 - r2) + abs(c1 - c2);
        for (int c = 1; c <= k; c++) {
            ans = min(ans, dist[c][r1][c1] + dist[c][r2][c2] + 1);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}