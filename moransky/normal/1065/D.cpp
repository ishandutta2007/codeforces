#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;
const int N = 15;
int n, a[N][N];
PII num[N * N];
//0: 1:  2
int dx[3][8] = {
    {1, -1, 0, 0},
    {1, 1, -1, -1, -2, -2, 2, 2},
    {1, 1, -1, -1},
};
int dy[3][8] = {
    {0, 0, 1, -1},
    {2, -2, 2, -2, 1, -1, 1, -1},
    {1, -1, 1, -1},
};
int size[3] = {4, 8, 4};
int ne[3] = {N, 1, N};
PII step[N][N][N * N][3];
struct Node{
    int x, y, k, m, t, c;
};
bool operator < (const Node &x, const Node &y){
    return x.t == y.t ? x.c > y.c : x.t > y.t;
}
bool inline check(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= n;
}
PII bfs(){
    priority_queue<Node> q;
    for(int i = 0; i < 3; i++){
        q.push((Node){ num[1].first, num[1].second, 1, i, 0, 0});
        step[num[1].first][num[1].second][0][i] = make_pair(0, 0);
    }
        
    while(!q.empty()){
        Node u = q.top(); q.pop();
        //printf("%d %d %d %d %d %d\n", u.x, u.y, u.k, u.m, u.t, u.c);
        if(u.k >= n * n){
            return make_pair(u.t, u.c);
        }
        for(int i = 0; i < size[u.m]; i++){
            for(int j = 1; j <= ne[u.m]; j++){
                int nx = u.x + dx[u.m][i] * j, ny = u.y + dy[u.m][i] * j;
                int nm = u.m, nt = u.t + 1, nc = u.c;
                int nk = (num[u.k + 1] == make_pair(nx, ny)) ? u.k + 1 : u.k;
                PII now = make_pair(nt, nc);
                if(!check(nx, ny)) break;
                if(now < step[nx][ny][nk][nm]){
                    step[nx][ny][nk][nm] = now;
                    q.push((Node){nx, ny, nk, nm, nt, nc});
                }
            }
        }
        for(int i = 0; i < 3; i++){
            if(i == u.m) continue;
            int nx = u.x, ny = u.y;
            int nm = i, nt = u.t + 1, nc = u.c + 1;
            int nk = u.k;
            PII now = make_pair(nt, nc);
            if(!check(nx, ny)) break;
            if(now < step[nx][ny][nk][nm]){
                step[nx][ny][nk][nm] = now;
                q.push((Node){nx, ny, nk, nm, nt, nc});
            }
        }
    }
    return make_pair(-1, -1);
}
int main(){
    memset(step, 0x3f, sizeof step);
    scanf("%d", &n);
    ne[0] = ne[2] = n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]), num[a[i][j]] = make_pair(i, j);
    PII res = bfs();
    printf("%d %d\n", res.first, res.second);
    return 0;
}