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

int n, m, q;
char board[N][N];
bool good[N][N];
int firstGood[N][N];
bool vis[N][N];
int dist[N][N];

int main() {
    
    scanf("%d %d %d", &n, &m, &q);
    
    for (int i = 1; i <= n; i++) {
        scanf("%s", &board[i][1]);
        for (int j = 1; j <= m; j++) board[i][j] -= '0';
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            bool exists = false;
            for (int k = 0; k < 4; k++) {
                int xx = i + dx[k];
                int yy = j + dy[k];
                if (min(xx, yy) <= 0 || min(n - xx, m - yy) < 0) {
                    continue;
                }
                if (board[xx][yy] == board[i][j]) {
                    exists = true;
                }
            }
            if (exists) good[i][j] = true;
        }
    }
    
    queue<pair<int, int> > Q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (good[i][j]) {
                debug("good " , i, j);
                Q.push({i, j});
                vis[i][j] = true;
                dist[i][j] = 0;
            } else {
                dist[i][j] = -1;
            }
        }
    }
    
    while (!Q.empty()) {
        int x = Q.front().first;;
        int y = Q.front().second;
//         debug(x, y);
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if (min(xx, yy) <= 0 || min(n - xx, m - yy) < 0 || vis[xx][yy]) {
                continue;
            }
            vis[xx][yy] = true;
            dist[xx][yy] = dist[x][y] + 1;
            Q.push({xx, yy});
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            firstGood[i][j] = dist[i][j];
        }
    }
    
    while (q--) {
        int x, y;
        long long p;
        scanf("%d %d %lld", &x, &y, &p);
        if (good[x][y]) {
            printf("%d\n", board[x][y] ^ (p % 2));
        } else {
            debug(x, y, p, dist[x][y], firstGood[x][y]);
            if (firstGood[x][y] == -1) {
                printf("%d\n", board[x][y]);
                continue;
            }
            if (p <= firstGood[x][y]) {
                printf("%d\n", board[x][y]);
            } else {
                p -= firstGood[x][y];
                debug(p);
                printf("%d\n", board[x][y] ^ (p % 2));
            }
        }
    }
    
    return 0;
}