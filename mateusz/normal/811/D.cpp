#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};


int n, m;
char board[N][N];
queue<pair<int, int> > Q;
bool vis[N][N];
pair<int, int> par[N][N];

pair<int, int> move(char dir) {
    printf("%c\n", dir);
    fflush(stdout);
    pair<int, int> ret;
    scanf("%d %d", &ret.first, &ret.second);
    return ret;
}

char getDir(int x, int y, int destX, int destY) {
    if (destX - x == 1) {
        return 'D';
    }
    if (destX - x == -1) {
        return 'U';
    }
    if (destY - y == 1) {
        return 'R';
    }
    if (destY - y == -1) {
        return 'L';
    }
    exit(-1);
}

char swap(char x) {
    if (x == 'R') return 'L';
    if (x == 'L') return 'R';
    if (x == 'D') return 'U';
    if (x == 'U') return 'D';
}

void printPath(vector<pair<int, int> > path) {
    for (int i = 0; i < path.size(); i++) {
        cerr << path[i].first << " " << path[i].second << endl;
    }
    bool knowX = false, knowY = false;
    bool xSwapped = false, ySwapped = false;
    
    pair<int, int> curPos = make_pair(1, 1);
    for (int i = 0; i < path.size() - 1; i++) {
        int x = path[i].first;
        int y = path[i].second;
        int destX = path[i + 1].first;
        int destY = path[i + 1].second;
        if (x == destX) {
            if (knowY == false) {
                knowY = true;
                pair<int, int> newPos = move('R');
                if (newPos == curPos) {
                    ySwapped = true;
                    curPos = move('L');
                } else {
                    curPos = newPos;
                }
            } else {
                char dir = getDir(x, y, destX, destY);
                if (ySwapped) {
                    dir = swap(dir);
                }
                curPos = move(dir);
            }
        } else {
            if (knowX == false) {
                knowX = true;
                pair<int, int> newPos = move('D');
                if (newPos == curPos) {
                    xSwapped = true;
                    curPos = move('U');
                } else {
                    curPos = newPos;
                }
            } else {
                char dir = getDir(x, y, destX, destY);
                if (xSwapped) {
                    dir = swap(dir);
                }
                curPos = move(dir);
            }
        }
    }
}

vector<pair<int, int> > getPath() {
    int startx = 1;
    int starty = 1;
    
    Q.push({startx, starty});
    vis[startx][starty] = true;
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !vis[xx][yy] && board[xx][yy] != '*') {
                vis[xx][yy] = true;
                par[xx][yy] = {x, y};
                Q.push({xx, yy});
            }
        }
    }
    
    vector<pair<int, int> > ret;
    int endx = -1, endy = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == 'F') {
                endx = i;
                endy = j;
                break;
            }
        }
    }
    
    while (endx != startx || endy != starty) {
        ret.push_back({endx, endy});
        int tmpx = par[endx][endy].first;
        int tmpy = par[endx][endy].second;
        endx = tmpx;
        endy = tmpy;
    }
    ret.push_back({startx, starty});
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        scanf("%s", &board[i][1]);
    }
    
    vector<pair<int, int> > path = getPath();
    
    printPath(path);
    
    return 0;
}