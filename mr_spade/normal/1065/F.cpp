#pragma GCC optimize("Ofast","inline")
#include<cstdio>
#include<algorithm>
using std::min;
using std::max;
const int N=1e6+5;
int n,k,idx;
int first[N],next[N];
int h[N],father[N],hson[N];
int id[N];
int Max[N<<2],lazy[N<<2];
void modify(int x,int lp,int rp,int l,int r,int k)
{
	if(lp==l&&rp==r)
	{
		Max[x]+=k;lazy[x]+=k;
		return;
	}
	int mid=(lp+rp)>>1;
	if(r<=mid)
		modify(x<<1,lp,mid,l,r,k);
	else if(l>=mid+1)
		modify(x<<1|1,mid+1,rp,l,r,k);
	else
		modify(x<<1,lp,mid,l,mid,k),modify(x<<1|1,mid+1,rp,mid+1,r,k);
	Max[x]=max(Max[x<<1],Max[x<<1|1])+lazy[x];
	return;
}
int query(int x,int lp,int rp,int l,int r)
{
	if(lp==l&&rp==r)
		return Max[x];
	int mid=(lp+rp)>>1;
	if(r<=mid)
		return query(x<<1,lp,mid,l,r)+lazy[x];
	else if(l>=mid+1)
		return query(x<<1|1,mid+1,rp,l,r)+lazy[x];
	else
		return max(query(x<<1,lp,mid,l,mid),query(x<<1|1,mid+1,rp,mid+1,r))+lazy[x];
}
void dfs1(int now)
{
	register int go;
	for(go=first[now];go;go=next[go])
	{
		dfs1(go);
		if(h[now]<h[go]+1)
			h[now]=h[go]+1;
		if(!hson[now]||h[go]>h[hson[now]])
			hson[now]=go;
	}
	return;
}
void dfs2(int now)
{
	register int go;
	id[now]=++idx;
	if(hson[now])
		dfs2(hson[now]);
	for(go=first[now];go;go=next[go])
		if(go!=hson[now])
			dfs2(go);
	return;
}
void dfs(int now)
{
	int c,d;
	register int i,go;
	if(!hson[now])
	{
		modify(1,1,n,id[now],id[now],100000001);
		return;
	}
	dfs(hson[now]);
	for(go=first[now];go;go=next[go])
		if(go!=hson[now])
		{
			dfs(go);
			c=query(1,1,n,id[now],id[now]+min(h[now],k));
			d=query(1,1,n,id[go],id[go]+min(h[go],k-1));
			if(c>0)
				modify(1,1,n,id[go],id[go]+h[go],c);
			if(d>0)
				modify(1,1,n,id[now],id[now]+h[now],d);
			for(i=0;i<=h[go];i++)
			{
				c=query(1,1,n,id[now]+i+1,id[now]+i+1);
				d=query(1,1,n,id[go]+i,id[go]+i);
				if(d>c)
					modify(1,1,n,id[now]+i+1,id[now]+i+1,d-c);
			}
		}
	return;
}
signed main()
{
	int x;
	register int i;
	scanf("%d%d",&n,&k);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&x);
		father[i]=x;next[i]=first[x];first[x]=i;
	}
	dfs1(1);dfs2(1);
	modify(1,1,n,1,n,-100000000);
	dfs(1);
	printf("%d\n",query(1,1,n,id[1],id[1]+h[1]));
	return 0;
}