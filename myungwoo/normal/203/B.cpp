#include <stdio.h>

int N,M,ans;
int A[1001][1001];

int main()
{
    int i,j,y,x,yy,xx,k;
    for (scanf("%d%d",&N,&M);M--;ans++){
        scanf("%d%d",&y,&x);
        A[y][x] = 1;
        for (yy=y;yy<y+3&&yy<=N;yy++) for (xx=x;xx<x+3&&xx<=N;xx++){
            if (yy < 3 || xx < 3) continue;
            k = 0;
            for (i=yy-3;i++<yy;) for (j=xx-3;j++<xx;) k += A[i][j];
            if (k == 9){ printf("%d\n",++ans); return 0; }
        }
    }
    puts("-1");
}