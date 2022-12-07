#include<bits/stdc++.h>
using namespace std;

int vis[105],n,m,cnt;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        vis[x]++;
    }
    for(int i=0;i<m;i++)
        if(vis[i]==0)cnt++;
    cnt+=vis[m];
    printf("%d\n",cnt);
    return 0;
}