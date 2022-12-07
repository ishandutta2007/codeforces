#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,Q,a[510][510],ans[510];
void getans(int x)
{
    int cur=0;
    ans[x]=0;
    for(int i=1;i<=m;i++)
    {
        if(a[x][i]) cur++;
        else cur=0;
        ans[x]=max(ans[x],cur);
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++) getans(i);
    while(Q--)
    {
        int x,y,res=0;
        scanf("%d%d",&x,&y);
        a[x][y]^=1;
        getans(x);
        for(int i=1;i<=n;i++) res=max(res,ans[i]);
        printf("%d\n",res);
    }
    return 0;
}