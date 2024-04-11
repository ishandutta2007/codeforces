#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200005;
const int maxm=200005;
int n,he[maxn],ne[maxm<<1],to[maxm<<1],dis[maxn];
int k,a[maxn];
bool twi[maxn];
queue<int> q;
int main()
{
    int i,m,u,v,maxx=0,minn=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) he[i]=-1,dis[i]=0x7fffffff,twi[i]=0;
    for(i=0;i<m;i++)
        scanf("%d%d",&u,&v),to[i]=u,ne[i]=he[v],he[v]=i;
    scanf("%d",&k);
    for(i=1;i<=k;i++) scanf("%d",&a[i]);
    while(!q.empty()) q.pop();
    q.push(a[k]),dis[a[k]]=0;
    while(!q.empty())
    {
        u=q.front(),q.pop();
        for(i=he[u];~i;i=ne[i])
            if(dis[to[i]]==0x7fffffff)
                q.push(to[i]),dis[to[i]]=dis[u]+1;
            else if(dis[to[i]]==dis[u]+1)
                twi[to[i]]=1;
    }
    for(i=1;i<k;i++)
        if(dis[a[i+1]]+1!=dis[a[i]])
            minn++,maxx++;
        else if(twi[a[i]])
            maxx++;
    printf("%d %d\n",minn,maxx);
    return 0;
}