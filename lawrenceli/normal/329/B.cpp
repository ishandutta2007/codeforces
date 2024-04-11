#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1005;

int R, C;
int mat[MAXN][MAXN];
int dist[MAXN][MAXN];
bool vis[MAXN][MAXN];
pii start, end;
queue<pii> q;

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            char c;
            cin >> c;
            if (c=='T') mat[i][j]=-1;
            else if (c=='S') start=pii(i, j);
            else if (c=='E') end=pii(i, j);
            else mat[i][j]=c-'0';
            dist[i][j]=1e9;
        }
    }
    q.push(end);
    int t=0;
    while (!q.empty()) {
        int size=q.size();
        for (int i=0; i<size; i++) {
            pii p=q.front();
            q.pop();
            if (vis[p.first][p.second]) continue;
            vis[p.first][p.second]=true;
            dist[p.first][p.second]=t;
            for (int dr=-1; dr<=1; dr++) {
                for (int dc=-1; dc<=1; dc++) {
                    if ((dr==0)^(dc==0)) {
                        int nr=p.first+dr, nc=p.second+dc;
                        if (nr<0 || nr>=R || nc<0 || nc>=C || mat[nr][nc]==-1) continue;
                        q.push(pii(nr, nc));
                    }
                }
            }
        }
        t++;
    }
    int tot=0;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (mat[i][j]!=-1 && dist[i][j]<=dist[start.first][start.second]) {
                tot+=mat[i][j];
            }
        }
    }
    cout << tot << endl;
}