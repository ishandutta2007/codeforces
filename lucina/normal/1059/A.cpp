#include<stdio.h>
const int maxn=2e6+10;
int n,l,a,ans,x,y,t;
int main(){
    scanf("%d%d%d",&n,&l,&a);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        ans+=(x-t)/a;
        t=x+y;
        }
    ans+=(l-t)/a;
    printf("%d\n",ans);
    }