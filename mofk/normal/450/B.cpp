#include<stdio.h>
int main(void)
{
    long int x,y,n,ans=0;
    scanf("%ld%ld",&x,&y);
    scanf("%ld",&n);
    if(n%6==1) ans=x;
    else if(n%6==2) ans=y;
    else if(n%6==3) ans=y-x;
    else if(n%6==4) ans=-x;
    else if(n%6==5) ans=-y;
    else ans=x-y;
    while(ans<0) ans+=1000000007;
    while(ans>=1000000007) ans-=1000000007;
    printf("%ld",ans);
}