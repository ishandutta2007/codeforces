#include <stdio.h>

#define max(a,b) ((a)>(b)?(a):(b))

int N,M,H,W,X,Y,ans;
int A[51][51],B[51][51];

int main()
{
    int i,j,x,y,sum=0;
    char ch;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) for (j=1;j<=M;j++) scanf(" %c",&ch), A[i][j] = ch-'0';
    scanf("%d%d",&H,&W);
    for (i=1;i<=H;i++) for (j=1;j<=W;j++) scanf(" %c",&ch), B[i][j] = ch-'0';
    for (x=-max(N,H);x<=max(N,H);x++) for (y=-max(M,W);y<=max(M,W);y++){
        if (x == 0 && y == 1)
            x=x;
        sum = 0;
        for (i=1;i<=N;i++) for (j=1;j<=M;j++){
            if (i+x > 0 && i+x <= H && j+y > 0 && j+y <= W) sum += A[i][j]*B[i+x][j+y];
        }
        if (ans < sum) ans = sum, X = x, Y = y;
    }
    printf("%d %d",X,Y);
}