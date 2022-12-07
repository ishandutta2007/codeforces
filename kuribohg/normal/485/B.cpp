#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
int n,minx=2e9,maxx=-2e9,miny=2e9,maxy=-2e9;
LL ans;
int main()
{
    scanf("%d",&n);
    for(int i=1,x,y;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        minx=min(minx,x),miny=min(miny,y);
        maxx=max(maxx,x),maxy=max(maxy,y);
    }
    ans=max(maxx-minx,maxy-miny);
    ans=ans*ans;
    printf("%I64d\n",ans);
    return 0;
}