//Author:Luogu@N_z_(320087)
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[401][401],s[401][401];
int bk[401];
int sum(int a,int b,int c,int d)
{
    return s[d][b]-s[d][a-1]-s[c-1][b]+s[c-1][a-1];
}
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        memset(bk,0,sizeof(bk));
        for(int x=1;x<=n;x++)
        for(int y=1;y<=m;y++)
        {
            char ch;
            cin>>ch;
            if(ch=='1')a[x][y]=1;
            else a[x][y]=0;
            s[x][y]=s[x-1][y]+s[x][y-1]-s[x-1][y-1]+a[x][y];
        }
        int ans=16;
        for(int l=1;l<=m;l++)
        for(int r=l+3;r<=m;r++)
        {
            for(int u=n-3;u>=1;u--)
            {
                bk[u]=(r-l-1)-sum(l+1,r-1,u+3,u+3)+sum(l+1,r-1,u,u+2)+3-sum(l,l,u,u+2)+3-sum(r,r,u,u+2);
                if(u<n-3){
                    int nxt=bk[u+1]+(!a[u][l])+(!a[u][r])+sum(l+1,r-1,u,u);
                    bk[u]=min(bk[u],nxt);
                }
                //cout<<u<<':'<<bk[u]<<endl;
            }
            for(int x=1;x<=n-4;x++)
            ans=min(ans,bk[x+1]+(r-l-1)-sum(l+1,r-1,x,x));
        }
        cout<<ans<<endl;
    }
}