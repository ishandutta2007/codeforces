#include<bits/stdc++.h>
using namespace std;
struct node
{
    int from;
    int to;
    int next;
}edge[500005];
int head[500005],n,tot,size[55];
long double f[55][55],tmp[55],fac[55],g[55];
void add(int u,int v)
{
    edge[tot].from=u;
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
long double calc(int n,int m)
{
    return fac[n]/(fac[m]*fac[n-m]);
}
void dfs(int x,int fa)
{
    f[x][0]=1;size[x]=1;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==fa) continue;
        dfs(edge[i].to,x);
        for(int ii=0;ii<=size[edge[i].to];ii++)
        {
            g[ii]=0;
            for(int j=1;j<=size[edge[i].to];j++)
            {
                if(j<=ii)
                g[ii]+=(long double)0.5*f[edge[i].to][j-1];
                else g[ii]+=f[edge[i].to][ii];
            }
            //cout<<g[ii]<<" ";
        }
        for(int ii=0;ii<=size[x]+size[edge[i].to];ii++) tmp[ii]=0;
        for(int ii=0;ii<size[x];ii++)
        {
            for(int j=0;j<=size[edge[i].to];j++)
            {
                tmp[ii+j]+=f[x][ii]*g[j]*calc(ii+j,ii)*calc(size[x]+size[edge[i].to]-ii-j-1,size[x]-ii-1);
            }
        }
        size[x]+=size[edge[i].to];
        for(int ii=0;ii<size[x];ii++) f[x][ii]=tmp[ii];
    }
}
int main()
{
    memset(head,-1,sizeof(head));
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    fac[0]=1;
    for(int i=1;i<=n;i++)
    {
        fac[i]=fac[i-1]*i;
    }
    for(int i=1;i<=n;i++)
    {
        dfs(i,0);
        printf("%.9Lf\n",(long double)(f[i][n-1]/fac[n-1]));
    }
    
}