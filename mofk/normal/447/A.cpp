#include<stdio.h>
#include<conio.h>
int main(void)
{
    int p,n,a[305],i,j,k,conflict;
    scanf("%d%d",&p,&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(k=2;k<=n;k++)
    {
        conflict=0;
        for(j=1;j<k;j++)
        {
            if((a[k]-a[j])%p==0) conflict=1;
        }
        if(conflict==1) break;
    }
    if(conflict==0) printf("-1");
    else printf("%d", k);
}