#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
int n,a[MAXN],b,d;
int main()
{
    scanf("%d%d%d",&n,&b,&d);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int now=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>b) continue;
        now+=a[i];
        if(now>d) ans++,now=0;
    }
    printf("%d\n",ans);
    return 0;
}