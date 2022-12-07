#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=200010;
int b[MAXN],n;
LL ans,x;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
    {
        if(x>b[i]) ans+=x-b[i];
        else ans+=b[i]-x;
        x=b[i];
    }
    printf("%I64d\n",ans);
    return 0;
}