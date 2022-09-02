#include<stdio.h>
#include<algorithm>
using namespace std;
int n,t,x,i;
long long s;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&t);
        x=max(x,t);
        s+=t;
    }
    printf("%lld",max(1ll*x,(s-1)/(n-1)+1));
}