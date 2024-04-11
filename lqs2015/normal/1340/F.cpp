#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,maxn=7000000,p=993217;
int tree[7777777],ls[7777777],rs[7777777],sz[7777777],val[7777777],all,q,tp,x,y,mx;
bool used[7777777];
struct treenode
{
	int rt1,rt2;
	bool bad;
	treenode()
	{
		rt1=rt2=bad=0;
	}
}t[444444];
int pw[111111],n,k,a[111111];
int Get(int x)
{
	return ((rand()<<13)+rand())%x+1;
}
int getnext()
{
	while(used[all]) all++;
	used[all]=1;
	return all;
}
void pushup(int node)
{
	sz[node]=sz[ls[node]]+sz[rs[node]]+1;
	tree[node]=(1ll*tree[ls[node]]*pw[sz[rs[node]]+1]+1ll*val[node]*pw[sz[rs[node]]]+tree[rs[node]])%mod;
}
int merge(int x,int y)
{
	if (!x || !y) return x^y;
	int pos=getnext();
	if (1ll*Get(1000000)*(sz[x]+sz[y])<1000000ll*sz[x])
	{
		ls[pos]=ls[x];val[pos]=val[x];
		rs[pos]=merge(rs[x],y);
	}
	else
	{
		rs[pos]=rs[y];val[pos]=val[y];
		ls[pos]=merge(x,ls[y]);
	}
	pushup(pos);
	return pos;
}
void split(int x,int &rt1,int &rt2,int y)
{
	if (!x) 
	{
		rt1=rt2=0;
		return;
	}
	if (y<=sz[ls[x]])
	{
		rt2=getnext();rs[rt2]=rs[x];val[rt2]=val[x];
		split(ls[x],rt1,ls[rt2],y);
		pushup(rt2);
	}
	else
	{
		rt1=getnext();ls[rt1]=ls[x];val[rt1]=val[x];
		split(rs[x],rs[rt1],rt2,y-sz[ls[x]]-1);
		pushup(rt1);
	}
}
void pup(treenode &a,treenode b,treenode c)
{
	if (b.bad || c.bad)
	{
		a.bad=1;
		return;
	}
	a.rt1=a.rt2=a.bad=0;
	int rt,rtt;
	if (sz[b.rt2]>sz[c.rt1])
	{
		rt=rtt=0;
		split(b.rt2,rt,rtt,sz[c.rt1]);
		if (tree[rt]!=tree[c.rt1])
		{
			a.bad=1;
			return;
		}
		a.rt2=merge(c.rt2,rtt);a.rt1=b.rt1;
	}
	else
	{
		rt=rtt=0;
		split(c.rt1,rt,rtt,sz[b.rt2]);
		if (tree[rt]!=tree[b.rt2])
		{
			a.bad=1;
			return;
		}
		a.rt1=merge(b.rt1,rtt);a.rt2=c.rt2;
	}
}
void build(int l,int r,int node)
{
	mx=max(mx,node);
	if (l==r)
	{
		if (a[l]<0)
		{
			t[node].rt1=getnext();
			val[t[node].rt1]=tree[t[node].rt1]=-a[l];
			sz[t[node].rt1]=1;
		}
		else
		{
			t[node].rt2=getnext();
			val[t[node].rt2]=tree[t[node].rt2]=a[l];
			sz[t[node].rt2]=1;
		}
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	pup(t[node],t[node<<1],t[(node<<1)|1]);
}
void upd(int x,int l,int r,int node,int y)
{
	if (l==r)
	{
		sz[t[node].rt1]=sz[t[node].rt2]=val[t[node].rt1]=val[t[node].rt2]=tree[t[node].rt1]=tree[t[node].rt2]=0;
		ls[t[node].rt1]=rs[t[node].rt1]=ls[t[node].rt2]=rs[t[node].rt2]=0;
		t[node].rt1=t[node].rt2=t[node].bad=0;
		if (y<0)
		{
			t[node].rt1=getnext();
			val[t[node].rt1]=tree[t[node].rt1]=-y;
			sz[t[node].rt1]=1;
		}
		else
		{
			t[node].rt2=getnext();
			val[t[node].rt2]=tree[t[node].rt2]=y;
			sz[t[node].rt2]=1;
		}
		return;
	}
	int mid=(l+r)>>1;
	if (x>mid) upd(x,mid+1,r,(node<<1)|1,y);
	else upd(x,l,mid,node<<1,y);
	pup(t[node],t[node<<1],t[(node<<1)|1]);
}
treenode query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return treenode();
	if (l>=beg && r<=en) return t[node];
	int mid=(l+r)>>1;treenode res;
	pup(res,query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1));
	return res;
}
void dfs(int x)
{
	if (!x || used[x]) return;
	used[x]=1;
	dfs(ls[x]);dfs(rs[x]);
}
void refresh()
{
	memset(used,0,sizeof(used));
	for (int i=1;i<=mx;i++)
	{
		dfs(t[i].rt1);dfs(t[i].rt2);
	}
	for (int i=1;i<=all;i++)
	{
		if (!used[i])
		{
			tree[i]=val[i]=ls[i]=rs[i]=sz[i]=0;
		}
	}
	all=1;
}
int main()
{
	scanf("%d%d",&n,&k);
	pw[0]=1;
	for (int i=1;i<=n;i++) pw[i]=1ll*pw[i-1]*p%mod;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	all=1;
	build(1,n,1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1)
		{
			upd(x,1,n,1,y);
		}
		else
		{
			treenode nw=query(x,y,1,n,1);
			if (nw.bad || nw.rt1 || nw.rt2) printf("No\n");
			else printf("Yes\n");
		}
		if (all>maxn) 
		{
			refresh();
		}
	}
	return 0;
}