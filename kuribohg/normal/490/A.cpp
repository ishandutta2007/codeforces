#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,t[4][100010],tot[4],x,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        t[x][++tot[x]]=i;
    }
    ans=min(tot[1],min(tot[2],tot[3]));
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++)
        printf("%d %d %d\n",t[1][i],t[2][i],t[3][i]);
    return 0;
}