#include<cstdio>
#include<algorithm>
using std::min;
using std::swap;
namespace lct
{
	const int N=2e5+5;
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
		if(rev[x])
		{
			if(ch[x][0])
				swap(ch[ch[x][0]][0],ch[ch[x][0]][1]),rev[ch[x][0]]^=1;
			if(ch[x][1])
				swap(ch[ch[x][1]][0],ch[ch[x][1]][1]),rev[ch[x][1]]^=1;
			rev[x]=0;
		}
		return;
	}
	inline void push_up(int x)
	{
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
	inline void access(int x)
	{
		int y=0;
		while(x)
		{
			splay(x);
			ch[x][1]=y;push_up(x);
			y=x;x=p[x];
		}
		return;
	}
	inline void makeroot(int x)
	{
		access(x);splay(x);
		swap(ch[x][0],ch[x][1]);rev[x]^=1;
		return;
	}
	inline bool link(int x,int y)
	{
		makeroot(x);makeroot(y);
		if(isroot(x))
			return p[x]=y,1;
		return 0;
	}
	inline bool cut(int x,int y)
	{
		makeroot(x);access(y);splay(y);
		if(ch[y][0]==x&&ch[x][1]==0)
			return ch[y][0]=0,p[x]=0,push_up(y),1;
		return 0;
	}
}
const int N=1005,M=2e5+5;
int Min[M<<2],lazy[M<<2],cnt[M<<2];
inline void push_down(int x)
{
	if(lazy[x])
	{
		Min[x<<1]+=lazy[x];
		lazy[x<<1]+=lazy[x];
		Min[x<<1|1]+=lazy[x];
		lazy[x<<1|1]+=lazy[x];
		lazy[x]=0;
	}
	return;
}
inline void push_up(int x)
{
	Min[x]=min(Min[x<<1],Min[x<<1|1]);
	cnt[x]=cnt[x<<1]*(Min[x<<1]==Min[x])+cnt[x<<1|1]*(Min[x<<1|1]==Min[x]);
	return;
}
void modify(int x,int lp,int rp,int l,int r,int k)
{
	if(lp==l&&rp==r)
	{
		Min[x]+=k;lazy[x]+=k;
		return;
	}
	push_down(x);
	int mid=(lp+rp)>>1;
	if(r<=mid)
		modify(x<<1,lp,mid,l,r,k);
	else if(l>=mid+1)
		modify(x<<1|1,mid+1,rp,l,r,k);
	else
		modify(x<<1,lp,mid,l,mid,k),modify(x<<1|1,mid+1,rp,mid+1,r,k);
	push_up(x);
	return;
}
int query(int x,int lp,int rp,int l,int r)
{
	if(lp==l&&rp==r)
		return cnt[x]*(Min[x]==1);
	push_down(x);
	int mid=(lp+rp)>>1;
	if(r<=mid)
		return query(x<<1,lp,mid,l,r);
	else if(l>=mid+1)
		return query(x<<1|1,mid+1,rp,l,r);
	else
		return query(x<<1,lp,mid,l,mid)+query(x<<1|1,mid+1,rp,mid+1,r);
}
void build(int x,int lp,int rp)
{
	if(lp==rp)
		return Min[x]=0,lazy[x]=0,cnt[x]=1,void();
	int mid=(lp+rp)>>1;
	build(x<<1,lp,mid);
	build(x<<1|1,mid+1,rp);
	push_up(x);
	return;
}
int n,m;
long long ans;
int a[N][N];
int fi[M],se[M];
signed main()
{
	int x,y,xx,yy=0;
	register int i,j;
	scanf("%d%d",&n,&m);
	build(1,1,n*m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]),fi[a[i][j]]=i,se[a[i][j]]=j;
	int pos=1,f;
	for(i=1;i<=n*m;i++)
	{
		x=fi[i];y=se[i];
		modify(1,1,n*m,1,i,1);
		if(a[x-1][y]>0&&a[x-1][y]<i)
			modify(1,1,n*m,1,a[x-1][y],-1);
		if(a[x][y-1]>0&&a[x][y-1]<i)
			modify(1,1,n*m,1,a[x][y-1],-1);
		if(a[x][y+1]>0&&a[x][y+1]<i)
			modify(1,1,n*m,1,a[x][y+1],-1);
		if(a[x+1][y]>0&&a[x+1][y]<i)
			modify(1,1,n*m,1,a[x+1][y],-1);
		while(pos<i)
		{
			f=0;
			if(a[x-1][y]>=pos&&a[x-1][y]<i&&!lct::link(i,a[x-1][y]))
				f=1;
			if(a[x][y-1]>=pos&&a[x][y-1]<i&&!lct::link(i,a[x][y-1]))
				f=1;
			if(a[x][y+1]>=pos&&a[x][y+1]<i&&!lct::link(i,a[x][y+1]))
				f=1;
			if(a[x+1][y]>=pos&&a[x+1][y]<i&&!lct::link(i,a[x+1][y]))
				f=1;
			if(!f)
				break;
			if(a[x-1][y]>=pos&&a[x-1][y]<i)
				lct::cut(i,a[x-1][y]);
			if(a[x][y-1]>=pos&&a[x][y-1]<i)
				lct::cut(i,a[x][y-1]);
			if(a[x][y+1]>=pos&&a[x][y+1]<i)
				lct::cut(i,a[x][y+1]);
			if(a[x+1][y]>=pos&&a[x+1][y]<i)
				lct::cut(i,a[x+1][y]);
			xx=fi[pos];yy=se[pos];
			if(a[xx-1][yy]>pos&&a[xx-1][yy]<i)
				lct::cut(pos,a[xx-1][yy]);
			if(a[xx][yy-1]>pos&&a[xx][yy-1]<i)
				lct::cut(pos,a[xx][yy-1]);
			if(a[xx][yy+1]>pos&&a[xx][yy+1]<i)
				lct::cut(pos,a[xx][yy+1]);
			if(a[xx+1][yy]>pos&&a[xx+1][yy]<i)
				lct::cut(pos,a[xx+1][yy]);
			pos++;
		}
		ans+=query(1,1,n*m,pos,i);
	}
	printf("%lld\n",ans);
	return 0;
}