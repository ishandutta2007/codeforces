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

const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0}, INF = 1e9;

int n, m, k;
char row[1000005];
int startX, startY, stopX, stopY;
vector<vector<char>> board;
vector<vector<int>> dist;

void BFS(int startX, int startY) {
    dist[startX][startY] = 0;
    queue<pair<int, int> > Q;
    Q.push({startX, startY});
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= k; j++) {
                int xx = x + dx[i] * j;
                int yy = y + dy[i] * j;
                if (board[xx][yy] == '#' || dist[xx][yy] <= dist[x][y]) {
                    break;
                }
                if (dist[xx][yy] == dist[x][y] + 1) {
                    continue;
                }
                dist[xx][yy] = dist[x][y] + 1;
                Q.push({xx, yy});
            }
        }
    }
}

int main() {
    
    scanf("%d %d %d", &n, &m, &k);
    
    
    board = vector<vector<char>>(n + 2, vector<char>(m + 2, '#'));
    dist = vector<vector<int>>(n + 2, vector<int>(m + 2, INF));
    for (int i = 1; i <= n; i++) {
        scanf("%s", &row[1]);
        for (int j = 1; j <= m; j++) {
            board[i][j] = row[j];
        }
    }
    
    scanf("%d %d %d %d", &startX, &startY, &stopX, &stopY);
    BFS(startX, startY);
    
    if (dist[stopX][stopY] == INF) {
        printf("-1\n");
        return 0;
    }
    
    printf("%d\n", dist[stopX][stopY]);
    
    return 0;
}