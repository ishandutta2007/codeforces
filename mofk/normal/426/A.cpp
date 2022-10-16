#include<stdio.h>
int main(void)
{
    int n,s,a[105],total=0,ok=0;
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        total+=a[i];
    }
    for(int j=1;j<=n;j++) if(total-a[j]<=s) ok=1;
    if(ok==1) printf("YES");
    else printf("NO");
}