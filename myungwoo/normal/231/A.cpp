#include <stdio.h>

int N;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i,j,k,s,c=0;
    scanf("%d",&N);
    for (i=1;i<=N;i++){
        s = 0;
        for (j=0;j<3;j++) scanf("%d",&k), s += k;
        if (s > 1) c++;
    }
    printf("%d",c);
}