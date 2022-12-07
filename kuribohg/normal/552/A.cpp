#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a,b,c,d,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d%d",&a,&b,&c,&d),ans+=(c-a+1)*(d-b+1);
    printf("%d\n",ans);
    return 0;
}