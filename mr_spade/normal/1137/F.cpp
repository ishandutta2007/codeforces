#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using std::max;
using std::min;
using std::swap;
using std::vector;
typedef long long ll;
const int N=2e5+5;
namespace sgt
{
	int root,tot;
	int sum[N*140],lazy[N*140],ch[N*140][2];
	inline void push_up(int x,ll lp,ll rp)
	{
		sum[x]=sum[ch[x][0]]+sum[ch[x][1]]+lazy[x]*(rp-lp+1);
		return;
	}
	void modify(int &x,ll lp,ll rp,ll l,ll r,int k)
	{
		if(!x)
			x=++tot;
//		if(x==sgt::root)
//			fprintf(stderr,"%lld %lld %d\n",l,r,k);
		if(lp==l&&rp==r)
		{
			sum[x]+=(rp-lp+1)*k;
			lazy[x]+=k;
			return;
		}
		ll mid=(lp+rp)>>1;
		if(r<=mid)
			modify(ch[x][0],lp,mid,l,r,k);
		else if(l>=mid+1)
			modify(ch[x][1],mid+1,rp,l,r,k);
		else
			modify(ch[x][0],lp,mid,l,mid,k),modify(ch[x][1],mid+1,rp,mid+1,r,k);
		push_up(x,lp,rp);
		return;
	}
	int query(int x,ll lp,ll rp,ll l,ll r)
	{
		if(!x)
			return 0;
		if(lp==l&&rp==r)
			return sum[x];
		ll mid=(lp+rp)>>1;
		if(r<=mid)
			return query(ch[x][0],lp,mid,l,r)+lazy[x]*(r-l+1);
		else if(l>=mid+1)
			return query(ch[x][1],mid+1,rp,l,r)+lazy[x]*(r-l+1);
		else
			return query(ch[x][0],lp,mid,l,mid)+query(ch[x][1],mid+1,rp,mid+1,r)+lazy[x]*(r-l+1);
	}
}
namespace lct
{
	ll key[N],Min[N],Max[N],lazy[N],size[N];
	int tag[N];
	bool rev[N];
	int p[N],ch[N][2];
	inline bool isroot(int x)
	{
		return ch[p[x]][0]!=x&&ch[p[x]][1]!=x;
	}
	inline bool which(int x)
	{
		return ch[p[x]][1]==x;
	}
	inline void push_down(int x)
	{
//		ll l,r;
		if(!x)
			return;
		if(tag[x])
		{
			key[x]=lazy[x]+tag[x]*size[ch[x][0]];
			Min[x]=min(lazy[x],lazy[x]+tag[x]*(size[x]-1));
			Max[x]=max(lazy[x],lazy[x]+tag[x]*(size[x]-1));
			if(ch[x][0])
			{
				if(rev[ch[x][0]])
				{
					lazy[ch[x][0]]=lazy[x]+tag[x]*(size[ch[x][0]]-1);
					tag[ch[x][0]]=-tag[x];
				}
				else
				{
					lazy[ch[x][0]]=lazy[x];
					tag[ch[x][0]]=tag[x];
				}
			}
			if(ch[x][1])
			{
				if(rev[ch[x][1]])
				{
					lazy[ch[x][1]]=lazy[x]+tag[x]*(size[x]-1);
					tag[ch[x][1]]=-tag[x];
				}
				else
				{
					lazy[ch[x][1]]=lazy[x]+tag[x]*(size[ch[x][0]]+1);
					tag[ch[x][1]]=tag[x];
				}
			}
//			if(ch[x][0])
//			{
//				l=lazy[x];r=lazy[x]+tag[x]*(size[ch[x][0]]-1);
//				if(rev[ch[x][0]])
//				{
//					key[ch[x][0]]=r-tag[x]*(size[ch[ch[x][0]][0]]);
//					Min[ch[x][0]]=min(l,r);Max[ch[x][0]]=max(l,r);
//					lazy[ch[x][0]]=r;tag[ch[x][0]]=-tag[x];
//				}
//				else
//				{
//					key[ch[x][0]]=l+tag[x]*(size[ch[ch[x][0]][0]]);
//					Min[ch[x][0]]=min(l,r);Max[ch[x][0]]=max(l,r);
//					lazy[ch[x][0]]=l;tag[ch[x][0]]=tag[x];
//				}
//			}
//			if(ch[x][1])
//			{
//				l=lazy[x]+tag[x]*(size[ch[x][0]]+1);r=lazy[x]+tag[x]*(size[x]-1);
//				if(rev[ch[x][1]])
//				{
//					key[ch[x][1]]=r-tag[x]*(size[ch[ch[x][1]][0]]);
//					Min[ch[x][1]]=min(l,r);Max[ch[x][1]]=max(l,r);
//					lazy[ch[x][1]]=r;tag[ch[x][1]]=-tag[x];
//				}
//				else
//				{
//					key[ch[x][1]]=l+tag[x]*(size[ch[ch[x][1]][0]]);
//					Min[ch[x][1]]=min(l,r);Max[ch[x][1]]=max(l,r);
//					lazy[ch[x][1]]=l;tag[ch[x][1]]=tag[x];
//				}
//			}
			tag[x]=0;
		}
		if(rev[x])
		{
			swap(ch[x][0],ch[x][1]);
			if(ch[x][0])
				rev[ch[x][0]]^=1;
			if(ch[x][1])
				rev[ch[x][1]]^=1;
			rev[x]=0;
		}
		return;
	}
	inline void push_up(int x)
	{
		push_down(ch[x][0]);push_down(ch[x][1]);
		size[x]=size[ch[x][0]]+1+size[ch[x][1]];
		Min[x]=Max[x]=key[x];
		if(ch[x][0])
			Min[x]=min(Min[x],Min[ch[x][0]]),Max[x]=max(Max[x],Max[ch[x][0]]);
		if(ch[x][1])
			Min[x]=min(Min[x],Min[ch[x][1]]),Max[x]=max(Max[x],Max[ch[x][1]]);
		return;
	}
	void maintain(int x)
	{
		if(!isroot(x))
			maintain(p[x]);
		push_down(x);
		return;
	}
	inline void rotate(int x)
	{
		int y=p[x],f=which(x);
		ch[x][f^1]?p[ch[x][f^1]]=y:0;ch[y][f]=ch[x][f^1];
		p[x]=p[y];isroot(y)?0:ch[p[y]][which(y)]=x;
		p[y]=x;ch[x][f^1]=y;push_up(y);push_up(x);
		return;
	}
	inline void splay(int x)
	{
		maintain(x);
		while(!isroot(x))
			if(isroot(p[x]))
				rotate(x);
			else if(which(x)^which(p[x]))
				rotate(x),rotate(x);
			else
				rotate(p[x]),rotate(x);
		return;
	}
	inline void access(int x,ll r)
	{
		int y=0;
		while(x)
		{
			splay(x);
			push_down(x);ch[x][1]=0;push_up(x);
			sgt::modify(sgt::root,1,80000000000ll,Min[x],Max[x],-1);
//			lazy[x]=r-size[x]+1;tag[x]=1;r-=size[x];
//			push_down(x);
//			sgt::modify(sgt::root,1,80000000000ll,Min[x],Max[x],1);
			ch[x][1]=y;push_up(x);
			y=x;x=p[x];
		}
		push_down(y);lazy[y]=r-size[y]+1;tag[y]=1;
		sgt::modify(sgt::root,1,80000000000ll,r-size[y]+1,r,1);
		return;
	}
	inline void makeroot(int x,ll r)
	{
		access(x,r);splay(x);push_down(x);
		rev[x]^=1;
		return;
	}
	inline ll query(int x)
	{
		splay(x);
		return key[x];
	}
}
int n,q;
ll last;
vector<int> e[N];
int pre[N];
char s[100];
void dfs(int x)
{
	for(auto y:e[x])
		if(y!=pre[x])
			pre[y]=x,dfs(y);
	return;
}
inline void debug()
{
	register int i;
	fputs("================================\n",stderr);
	for(i=1;i<=n;i++)
		printf("%lld ",lct::query(i));
	putchar('\n');
	fputs("================================\n",stderr);
	return;
}
signed main()
{
	int x,y;
	register int i;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n-1;i++)
		scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	dfs(1);
	sgt::modify(sgt::root,1,80000000000ll,1,n,1);
	// return 0;
	for(i=1;i<=n;i++)
	{
		lct::key[i]=lct::Min[i]=lct::Max[i]=i;lct::size[i]=1;
		lct::p[i]=pre[i];
	}
	last=2;
	for(i=1;i<=n;i++)
	{
		lct::makeroot(i,last*200000),last++;
//		debug();
	}
	while(q--)
	{
		scanf("%s",s);
		if(s[0]=='u')
		{
			scanf("%d",&x);
			lct::makeroot(x,last*200000),last++;
		}
		else if(s[0]=='w')
		{
			scanf("%d",&x);
			printf("%d\n",sgt::query(sgt::root,1,80000000000ll,1,lct::query(x)));
		}
		else
		{
			scanf("%d%d",&x,&y);
			if(sgt::query(sgt::root,1,80000000000ll,1,lct::query(x))<sgt::query(sgt::root,1,80000000000ll,1,lct::query(y)))
				printf("%d\n",x);
			else
				printf("%d\n",y);
		}
	}
	return 0;
}