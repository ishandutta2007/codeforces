#include <stdio.h>

int N,M,ans,cnt;
short yn[5002][5002],yp[5002][5002],xn[5002][5002],xp[5002][5002];
char map[5002][5002];

void del(int y,int x)
{
    yn[y][yp[y][x]] = yn[y][x];
    yp[y][yn[y][x]] = yp[y][x];
    xn[xp[y][x]][x] = xn[y][x];
    xp[xn[y][x]][x] = xp[y][x];
}

void add(int y,int x)
{
    yn[y][yp[y][x]] = x;
    yp[y][yn[y][x]] = x;
    xn[xp[y][x]][x] = y;
    xp[xn[y][x]][x] = y;
}

int dfs(int y,int x)
{
    if (y < 1 || x < 1 || y > N || x > M) return 0;
    int k;
    del(y,x);
    if (map[y][x] == 'U') k = dfs(xp[y][x],x);
    if (map[y][x] == 'R') k = dfs(y,yn[y][x]);
    if (map[y][x] == 'D') k = dfs(xn[y][x],x);
    if (map[y][x] == 'L') k = dfs(y,yp[y][x]);
    add(y,x);
    return k+1;
}

int main()
{
    int i,j,k;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) scanf("%s",map[i]+1);
    for (i=1;i<=N;i++){
        for (k=0,j=1;j<=M+1;j++) if (map[i][j] != '.'){
            yn[i][k] = j;
            yp[i][j] = k;
            k = j;
        }
    }
    for (i=1;i<=M;i++){
        for (k=0,j=1;j<=N+1;j++) if (map[j][i] != '.'){
            xn[k][i] = j;
            xp[j][i] = k;
            k = j;
        }
    }
    for (i=1;i<=N;i++) for (j=1;j<=M;j++) if (map[i][j] != '.'){
        k = dfs(i,j);
        if (ans < k) ans = k, cnt = 1;
        else if (ans == k) cnt++;
    }
    printf("%d %d",ans,cnt);
}