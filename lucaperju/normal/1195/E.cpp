#include <bits/stdc++.h>

using namespace std;
long long v[3001][3001],rmup[2][3001][3001],lg[3003];
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,i,j,cnt=0,k=0,mn=2,n,m,is,js,ib,jb,s=0,a,b;
    cin>>n>>m>>a>>b;
    long long x,y,z,pr;
    for(i=2;i<=3000;++i)
        lg[i]=lg[i/2]+1;
    cin>>pr>>x>>y>>z;
    v[1][1]=pr;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            if(i==1 && j==1)
                continue;
            v[i][j]=(pr*1LL*x+y)%z,pr=v[i][j];
        }
    for(int pz=0;pz<=lg[a];++pz)
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                int ic=pz&1;
                int ip=1-ic;
                if(pz==0)
                    rmup[ic][i][j]=v[i][j];
                else
                if(i<(1<<pz))
                    continue;
                else
                    rmup[ic][i][j]=min(rmup[ip][i][j],rmup[ip][i-(1<<(pz-1))][j]);
            }
    for(i=a;i<=n;++i)
        for(j=1;j<=m;++j)
            v[i-a+1][j]=min(rmup[lg[a]&1][i][j],rmup[lg[a]&1][i-a+(1<<lg[a])][j]);
    n=n-a+1;
    for(int pz=0;pz<=lg[b];++pz)
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                int ic=pz&1;
                int ip=1-ic;
                if(pz==0)
                    rmup[ic][i][j]=v[i][j];
                else
                if(j<(1<<pz))
                    continue;
                else
                    rmup[ic][i][j]=min(rmup[ip][i][j],rmup[ip][i][j-(1<<(pz-1))]);
            }
    for(i=1;i<=n;++i)
        for(j=b;j<=m;++j)
            s+=(long long)min(rmup[lg[b]&1][i][j],rmup[lg[b]&1][i][j-b+(1<<lg[b])]);
   /** for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            for(int pz=0;pz<=lg[b];++pz)
            {
                if(pz==0)
                    rmup[i][j][pz]=rzup[i][j];
                else
                if(j<(1<<pz))
                    continue;
                else
                    rmup[i][j][pz]=min(rmup[i][j][pz-1],rmup[i][j-(1<<(pz-1))][pz-1]);
            }
    for(i=1;i<=n;++i)
        for(j=b;j<=m;++j)
            s+=(long long)min(rmup[i][j][lg[b]],rmup[i][j-b+(1<<lg[b])][lg[b]]);*/
    cout<<s;
    return 0;
}