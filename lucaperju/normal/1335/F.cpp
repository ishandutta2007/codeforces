#include <bits/stdc++.h>
using namespace std;
char dir[2000006];
int val[2000006];
int cycc[2000006],viz[2000006];
int n,m;
long long ra,rb;
void nextpoz (int &i, int &j)
{
    if(dir[i*m-m+j]=='U')
        --i;
    else if(dir[i*m-m+j]=='D')
        ++i;
    else if(dir[i*m-m+j]=='L')
        --j;
    else
        ++j;
}
void dfs (int i, int j, long long pzintr, long long k, long long dst)
{
    if(!viz[i*m-m+j])
        viz[i*m-m+j]=-1;
    cycc[(long long)(pzintr-dst-1LL+k*1001101LL)%k+1LL]|=val[i*m-m+j];
    if(i>=1)
        if(dir[(i-1)*m-m+j]=='D' && !viz[(i-1)*m-m+j])
            dfs(i-1,j,pzintr,k,dst+1);
    if(j>=1)
        if(dir[i*m-m+j-1]=='R' && !viz[i*m-m+j-1])
            dfs(i,j-1,pzintr,k,dst+1);
    if(i<=n)
        if(dir[(i+1)*m-m+j]=='U' && !viz[(i+1)*m-m+j])
            dfs(i+1,j,pzintr,k,dst+1);
    if(j<=m)
        if(dir[i*m-m+j+1]=='L' && !viz[i*m-m+j+1])
            dfs(i,j+1,pzintr,k,dst+1);
}
void solvecyc (int i, int j)
{
    int iinit=i,jinit=j;
    int dst=1;
    viz[i*m-m+j]=1;
    nextpoz(i,j);
    while(!viz[i*m-m+j])
    {
        viz[i*m-m+j]=++dst;
        nextpoz(i,j);
    }
 //   int ogi=i,ogj=j;
    int valc=viz[i*m-m+j];
    i=iinit;
    j=jinit;
    while(viz[i*m-m+j]!=valc)
    {
        viz[i*m-m+j]=0;
        nextpoz(i,j);
    }
    int k=1;
    cycc[k++]=val[i*m-m+j];
    nextpoz(i,j);
    while(viz[i*m-m+j]!=valc)
    {
        cycc[k++]=val[i*m-m+j];
        nextpoz(i,j);
    }
    --k;
    ra+=k;
    dfs(i,j,1,k,0);
    dst=1;
    nextpoz(i,j);
    while(viz[i*m-m+j]!=valc)
    {
        ++dst;
        dfs(i,j,dst,k,0);
        nextpoz(i,j);
    }
    for(i=1;i<=k;++i)
        rb+=cycc[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,j=0,t,mx=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ra=rb=0;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                char c;
                cin>>c;
                val[i*m-m+j]=c-'0';
                viz[i*m-m+j]=0;
                val[i*m-m+j]=1-val[i*m-m+j];
            }
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                cin>>dir[i*m-m+j];
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                if(!viz[i*m-m+j])
                {
                    solvecyc(i,j);
                }
        cout<<ra<<' '<<rb<<'\n';
    }
    return 0;
}