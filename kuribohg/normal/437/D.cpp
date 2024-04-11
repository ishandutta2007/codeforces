#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,m,wp[100010],f[100010],t[100010],w[100010],fa[100010],rank[100010];
long long sz[100010];
double ans;
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void uni(int i,int j)
{
    sz[find(j)]+=sz[find(i)];
    fa[find(i)]=find(j);
}
bool cmp(int i,int j)
{
    return w[i]>w[j];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&wp[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&f[i],&t[i]);
        w[i]=min(wp[f[i]],wp[t[i]]);
    }
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++) rank[i]=i;
    sort(rank+1,rank+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(find(f[rank[i]])!=find(t[rank[i]]))
        {
            ans+=((double)sz[find(f[rank[i]])]*(double)sz[find(t[rank[i]])]*(double)w[rank[i]]);
            uni(f[rank[i]],t[rank[i]]);
        }
        //if(m==99999&&i>=99990) cout<<ans<<endl;
    }
    cout<<ans*2.0/((long long)n*(n-1))<<endl;
    return 0;
}