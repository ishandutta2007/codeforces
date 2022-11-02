#include <stdio.h>

int X,Y,N,D,xx[21],yy[21];
bool dy[400][400][2][2],v[400][400][2][2];

bool dfs(int x,int y,bool u1,bool u2)
{
    if ((x-200)*(x-200)+(y-200)*(y-200) > D*D) return 1;
    if (v[x][y][u1][u2]) return dy[x][y][u1][u2];
    v[x][y][u1][u2] = 1;
    int i;
    bool &d=dy[x][y][u1][u2];
    if (!u1 && !dfs(y,x,u2,1)) return d=1;
    for (i=1;i<=N;i++){
        if (!dfs(x+xx[i],y+yy[i],u2,u1)) return d=1;
    }
    return d;
}

int main()
{
    int i;
    scanf("%d%d%d%d",&X,&Y,&N,&D);
    for (i=1;i<=N;i++) scanf("%d%d",xx+i,yy+i);
    puts(dfs(X+200,Y+200,0,0)?"Anton":"Dasha");
}