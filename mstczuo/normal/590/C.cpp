# include <iostream>
# include <cstdio>
# include <cstring>
# include <queue>

using namespace std;

const int inf = 0x2a2a2a2a;
const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};

int dis12, dis23, dis13, ans;
int n, m;

char a[1200][1200];
int dis1[1200][1200];
int dis2[1200][1200];
int dis3[1200][1200];

queue<int> q;

void BFS(int num,int dis[][1200]) {
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            dis[i][j] = inf;
            if(a[i][j] == '0' + num) {
                dis[i][j] = 0;
                q.push(i*m+j);
            }
        }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        int ci = cur / m, cj = cur % m;
        for(int k = 0; k < 4; ++k) {
            int ni = ci + di[k], nj = cj + dj[k];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] != '#' && dis[ni][nj] == inf) {
                dis[ni][nj] = dis[ci][cj] + 1;
                q.push(ni * m + nj);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) 
        scanf("%s", a[i]);
    BFS(1, dis1);
    BFS(2, dis2);
    BFS(3, dis3);

    dis12 = dis13 = dis23 = ans = inf;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(a[i][j] == '2') dis12 = min(dis12, dis1[i][j]);
            if(a[i][j] == '3') dis13 = min(dis13, dis1[i][j]);
            if(a[i][j] == '3') dis23 = min(dis23, dis2[i][j]);
            if(a[i][j] == '.') ans = min(ans, dis1[i][j] + dis2[i][j] + dis3[i][j]);
        }
    }
    ans = min(ans, dis12 + dis13);
    ans = min(ans, dis12 + dis23);
    ans = min(ans, dis13 + dis23);
    if(ans == inf) cout << -1 << endl;
    else cout << ans - 2 << endl;
}