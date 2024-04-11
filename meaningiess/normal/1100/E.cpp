#include<bits/stdc++.h>
#define N 100010
using namespace std;
struct edg
{
	int u,v,w,id1,id2;
	bool operator<(const edg&a) const{return w<a.w;}
}e[N];
int fir[N],nxt[N<<1],to[N<<1],w[N<<1],cnt;
void mem(){memset(fir,0,sizeof(fir));memset(nxt,0,sizeof(nxt));cnt=0;}
void add(int u,int v,int x){nxt[++cnt]=fir[u];fir[u]=cnt;to[cnt]=v;w[cnt]=x;}
int n,m,flg,low[N],dfn[N],d[N],vis[N],us[N];
queue<int> q;
int chek(int x)
{
	mem();flg=1;int i;memset(d,0,sizeof(d));memset(vis,0,sizeof(vis));
	for (i=x;i<=m;i++) add(e[i].u,e[i].v,0),d[e[i].v]++;
    for (i=1;i<=n;i++) if (d[i]==0) q.push(i);int ans=0;
    while(!q.empty())
    {
        int p=q.front();q.pop();ans++;if (vis[p]) continue;vis[p]=1;
        for (i=fir[p];i;i=nxt[i])
        {
            int y=to[i];d[y]--;
            if (d[y]==0) q.push(y);  
        }
    }
    if(ans==n)return 1;return 0;
}
int main()
{
	int i,l,r,mid,as=0,res=0;cin>>n>>m;
	for (i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w),e[i].id1=i;
	sort(e+1,e+m+1);l=1;r=m;
	while (l<=r)
	{
		mid=(l+r)>>1;if (chek(mid)) r=mid-1,as=mid;else l=mid+1;
	}
	cout<<e[as-1].w<<' ';mem();memset(d,0,sizeof(d));memset(vis,0,sizeof(vis));
	for (i=as;i<=m;i++) add(e[i].u,e[i].v,0),d[e[i].v]++;
	for (i=1;i<as;i++) add(e[i].u,e[i].v,-1),add(e[i].v,e[i].u,i);
	for (i=1;i<=n;i++) if (d[i]==0) q.push(i);
    while(!q.empty())
    {
        int p=q.front();q.pop();if (vis[p]) continue;vis[p]=1;
        for (i=fir[p];i;i=nxt[i]) if (w[i]==0)
        {
            int y=to[i];d[y]--;
            if (d[y]==0) q.push(y);  
        }
        else
		{
		//	cout<<w[i]<<' '<<p<<' '<<to[i]<<endl;
			if ((w[i]>0 && !vis[to[i]])) us[w[i]]=1,res++;
		}
    }
    cout<<res<<endl;
    for (i=1;i<=m;i++) if (us[i]) cout<<e[i].id1<<' ';
}