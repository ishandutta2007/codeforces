#include <stdio.h>

int N,M;
char map[505][505];
int a[505][505],b[505][505];

int suma(int x, int y, int z, int w)
{
    z--; w--;
    return a[x][y] - a[z][y] - a[x][w] + a[z][w];
}

int sumb(int x, int y, int z, int w)
{
    z--; w--;
    return b[x][y] - b[z][y] - b[x][w] + b[z][w];
}

int main()
{
    scanf ("%d %d",&N,&M);
    for (int i=1;i<=N;i++) scanf ("%s",map[i]+1);
    for (int i=1;i<N;i++) for (int j=1;j<=M;j++){
        if (map[i][j] == '.' && map[i][j] == map[i+1][j]) a[i][j] = 1;
        a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    }
    for (int i=1;i<=N;i++) for (int j=1;j<M;j++){
        if (map[i][j] == '.' && map[i][j] == map[i][j+1]) b[i][j] = 1;
        b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
    }

    int Q; scanf ("%d",&Q); while (Q--){
        int p,q,r,s;
        scanf ("%d %d %d %d",&p,&q,&r,&s);
        int ans = suma(r-1,s,p,q) + sumb(r,s-1,p,q);
        printf ("%d\n",ans);
    }
    return 0;
}