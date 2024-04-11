#include<stdio.h>
#include<math.h>
int main(void)
{
    double ans,m,n,i;
    scanf("%lf%lf",&m,&n);
    ans=m;
    for(i=1;i<m;i++) ans-=pow((i/m),n);
    printf("%lf",ans);
}