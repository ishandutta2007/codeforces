#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,c1[6],c2[6],x,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&x),c1[x]++;
    for(int i=1;i<=n;i++) scanf("%d",&x),c2[x]++;
    for(int i=1;i<=5;i++)
    {
        if((c1[i]+c2[i])%2!=0) {puts("-1");return 0;}
        else ans+=abs((c1[i]+c2[i])/2-c1[i]);
    }
    printf("%d\n",ans/2);
    return 0;
}