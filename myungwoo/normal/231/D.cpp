#include <stdio.h>

int X,Y,Z;
int P,Q,R;
int A[7],ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i;
    scanf("%d%d%d",&X,&Y,&Z);
    scanf("%d%d%d",&P,&Q,&R);
    for (i=1;i<7;i++) scanf("%d",A+i);
    if (Y < 0) ans += A[1];
    if (Y > Q) ans += A[2];
    if (Z < 0) ans += A[3];
    if (Z > R) ans += A[4];
    if (X < 0) ans += A[5];
    if (X > P) ans += A[6];
    printf("%d",ans);
}