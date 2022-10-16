#include<stdio.h>
int main(void)
{
    long int n,i,ans=0,pol=0;
    int e[100005];
    scanf("%ld",&n);
    for(i=1;i<=n;i++) {
        scanf("%d",&e[i]);
        if(e[i]>0) pol+=e[i];
        else if(pol==0) ans++;
        else pol--;
    }
    printf("%ld",ans);
}