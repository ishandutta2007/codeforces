#include<bits/stdc++.h>
#define midin treein[k].l+(treein[k].r-treein[k].l)/2
#define midout treeout[k].l+(treeout[k].r-treeout[k].l)/2
using namespace std;
struct 
{
	int l,r,bh;
}treein[500000],treeout[500000];
priority_queue<pair<long long,long long> >q;
int n,q1,s,k,v,u,w,l,r,from[100005<<5],to[100005<<5],val[100005<<5],nxt[100005<<5],tot,head[500000],cnt;
long long dist[500000];
void ad(int v,int l,int w)
{
	cnt++;
	to[cnt]=l,val[cnt]=w;from[cnt]=v;
	nxt[cnt]=head[v];
	head[v]=cnt;
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		treein[k].l=treein[k].r=treeout[k].l=treeout[k].r=treein[k].bh=treeout[k].bh=l;
    } else
    {
    	treein[k].l=treeout[k].l=l;treein[k].r=treeout[k].r=r;
    	build(k*2,l,l+(r-l)/2);
    	build(k*2+1,l+(r-l)/2+1,r);
    	tot++;
    	treein[k].bh=tot;
		//cout<<treein[k].l<<" "<<treein[k].r<<" "<<k<<" "<<tot<<endl;
    	tot++;
    	treeout[k].bh=tot;
		//cout<<treeout[k].l<<" "<<treeout[k].r<<" "<<k<<" "<<tot<<endl;
    	ad(treein[k*2].bh,treein[k].bh,0);
    	ad(treein[k*2+1].bh,treein[k].bh,0);
    	ad(treeout[k].bh,treeout[k*2].bh,0);
    	ad(treeout[k].bh,treeout[k*2+1].bh,0);
    }
}
void xg(int k,int v,int l,int r,int w)
{
	if(treein[k].l==l&&treein[k].r==r)
	{
		ad(v,treeout[k].bh,w);
		return;
    }
    if (l<=midin) xg(k*2,v,l,min(midin,r),w);
    if (r>midin) xg(k*2+1,v,max(l,midin+1),r,w);
}
void xg1(int k,int v,int l,int r,int w)
{
	if(treein[k].l==l&&treein[k].r==r)
	{
		ad(treein[k].bh,v,w);
		return;
    }
    if (l<=midin) xg1(k*2,v,l,min(midin,r),w);
    if (r>midin) xg1(k*2+1,v,max(l,midin+1),r,w);
}
void dijkstra(int start)
{
    memset(dist,0x3f,sizeof(dist));
    dist[start]=0;
    q.push(make_pair(0,start));
    while(!q.empty())
    {
        int x=q.top().second;
        q.pop();
        for(int i=head[x];i;i=nxt[i])
        {
            int y=to[i];
            if(dist[y]>dist[x]+val[i])
            {
                dist[y]=dist[x]+val[i];
                q.push(make_pair(-dist[y],y));
            }
        }
    }
}
int main()
{
	cin>>n>>q1>>s;tot=n;
	build(1,1,n);
	for (int i=1;i<=q1;i++)
	{
		cin>>k;
		if (k==1) 
		{
			cin>>v>>u>>w;
			ad(v,u,w);
	    } else
	    if (k==2)
	    {
	    	cin>>v>>l>>r>>w;
	    	xg(1,v,l,r,w);
	    } else
	    if (k==3)
	    {
	    	cin>>v>>l>>r>>w;
	    	xg1(1,v,l,r,w);
	    }
    }
    dijkstra(s);//for (int i=1;i<=cnt;i++) cout<<from[i]<<" "<<to[i]<<" "<<val[i]<<endl;
    for (int i=1;i<=n;i++)
      if (s!=i&&dist[i]==0x3f3f3f3f3f3f3f3f) cout<<-1<<" "; else cout<<dist[i]<<" ";
}