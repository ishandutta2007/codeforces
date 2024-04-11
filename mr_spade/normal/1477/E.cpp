#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
using std::min;
using std::max;
using std::queue;
typedef long long ll;
const int ninf=0xc0c0c0c0,inf=0x3f3f3f3f;
const ll ninfll=0xc0c0c0c0c0c0c0c0,infll=0x3f3f3f3f3f3f3f3f;
inline int Rand(int l,int r)
{
	return (rand()<<16|rand()<<1|rand()>>14)%(r-l+1)+l;
}
struct phs
{
	static const int N=1e6+5;
	inline int Rand()
	{
		return rand()<<13^rand()>>2^rand();
	}
	int rt,tot;
	int key[N],prio[N],size[N];
	ll sum[N];
	int ch[N][2];
	queue<int> Q;
	inline int new_node(int k)
	{
		int x;
		if(!Q.empty())
			x=Q.front(),Q.pop();
		else
			x=++tot;
		key[x]=sum[x]=k;prio[x]=Rand();size[x]=1;
		ch[x][0]=ch[x][1]=0;return x;
	}
	inline void push_up(int x)
	{
		sum[x]=sum[ch[x][0]]+key[x]+sum[ch[x][1]];
		size[x]=size[ch[x][0]]+1+size[ch[x][1]];
		return;
	}
	void split(int z,int &x,int &y,int k)
	{
		if(!z)
			return x=y=0,void();
		if(key[z]<=k)
			x=z,split(ch[z][1],ch[z][1],y,k);
		else
			y=z,split(ch[z][0],x,ch[z][0],k);
		push_up(z);
		return;
	}
	void split_size(int z,int &x,int &y,int k)
	{
		if(!z)
			return x=y=0,void();
		if(size[ch[z][0]]+1<=k)
			x=z,split_size(ch[z][1],ch[z][1],y,k-size[ch[z][0]]-1);
		else
			y=z,split_size(ch[z][0],x,ch[z][0],k);
		push_up(z);
		return;
	}
	int merge(int x,int y)
	{
		if(!x||!y)
			return x+y;
		if(prio[x]<prio[y])
			return ch[x][1]=merge(ch[x][1],y),push_up(x),x;
		else
			return ch[y][0]=merge(x,ch[y][0]),push_up(y),y;
	}
	inline void insert(int k)
	{
		int x,y;
		split(rt,x,y,k);
		rt=merge(merge(x,new_node(k)),y);
		return;
	}
	inline void erase(int k)
	{
		int x,y,z,w;
		split(rt,x,y,k);
		split(x,z,w,k-1);
		Q.push(w);
		w=merge(ch[w][0],ch[w][1]);
		rt=merge(merge(z,w),y);
		return;
	}
	inline int pre(int k)
	{
		int res=ninf,x=rt;
		while(x)
			if(key[x]<k)
				res=max(res,key[x]),x=ch[x][1];
			else
				x=ch[x][0];
		return res;
	}
	inline int suc(int k)
	{
		int res=inf,x=rt;
		while(x)
			if(key[x]>k)
				res=min(res,key[x]),x=ch[x][0];
			else
				x=ch[x][1];
		return res;
	}
	inline int select(int k)
	{
		if(k<1||k>size[rt])
			return inf;
		int x=rt;
		while(x)
			if(size[ch[x][0]]+1<k)
				k-=size[ch[x][0]]+1,x=ch[x][1];
			else if(size[ch[x][0]]+1==k)
				return key[x];
			else
				x=ch[x][0];
	}
}A,B;
const int N=1e6+5;
int n,m,q;
int a[N],b[N];
inline ll runa(int k,int x)
{
	if(x==ninf||x==inf)
		return ninfll;
	int minv,r1,r2;
	ll res;
//	A.erase(x);
	minv=min(min(A.suc(ninf),B.suc(ninf)),x-k);
	B.split(B.rt,r1,r2,x-k);
	res=k+(A.sum[A.rt]-x)-(ll)(n-1)*minv-(B.sum[r2]-(ll)B.size[r2]*(x-k));
	B.rt=B.merge(r1,r2);
//	A.insert(x);
	return res;
}
inline ll epca(int k,int x)
{
	return max(runa(k,A.pre(x)),runa(k,A.suc(x-1)));
}
inline ll runb(int k,int x)
{
	if(x==ninf||x==inf)
		return ninfll;
	int minv,r1,r2;
	ll res;
//	B.erase(x);
	minv=min(min(A.suc(ninf),B.suc(ninf)),x-k);
	B.split(B.rt,r1,r2,x-k);
	res=A.sum[A.rt]-(ll)n*minv-((B.sum[r2]-x)-(ll)(B.size[r2]-1)*(x-k))-k;
	B.rt=B.merge(r1,r2);
//	B.insert(x);
	return res;
}
inline ll epcb(int k,int x)
{
	return max(runb(k,B.pre(x)),runb(k,B.suc(x-1)));
}
inline ll solve(int k)
{
	if(k==0)
		return epcb(k,inf);
	ll ans=ninfll;
	register int i;
	ans=max(ans,epca(k,ninf));
//	ans=max(ans,epca(k,B.select(m-n)+k));
	ans=max(ans,epca(k,B.select(m-n+1)+k));
//	ans=max(ans,epca(k,B.select(m-n+2)+k));
//	ans=max(ans,epca(k,B.select(m-1)+k));
	ans=max(ans,epca(k,B.select(m)+k));
	ans=max(ans,epca(k,inf));
	ans=max(ans,epcb(k,ninf));
//	ans=max(ans,epcb(k,B.select(m-n-1)+k));
	ans=max(ans,epcb(k,B.select(m-n)+k));
//	ans=max(ans,epcb(k,B.select(m-n+1)+k));
//	ans=max(ans,epcb(k,B.select(m-1)+k));
	ans=max(ans,epcb(k,B.select(m)+k));
	ans=max(ans,epcb(k,inf));
	return ans;
}
signed main()
{
//	freopen("test.out","w",stdout);
	int opt,pos,x;
	register int i;
	scanf("%d%d%d",&n,&m,&q);
//	n=200000;m=200000;q=500000;
	for(i=1;i<=n;i++)
	{
//		a[i]=Rand(0,1000000);
		scanf("%d",&a[i]);
		A.insert(a[i]);
	}
	for(i=1;i<=m;i++)
	{
//		b[i]=Rand(0,1000000);
		scanf("%d",&b[i]);
		B.insert(b[i]);
	}
	//scanf("%lld",&opt)
	//opt=Rand(1,3)
	while(q--)
		switch(scanf("%d",&opt),opt)
		{
			case 1:
//			pos=Rand(1,n);x=Rand(1,1000000);
			scanf("%d%d",&pos,&x);
			A.erase(a[pos]);A.insert(x);
			a[pos]=x;break;
			case 2:
//			pos=Rand(1,n);x=Rand(1,1000000);
			scanf("%d%d",&pos,&x);
			B.erase(b[pos]);B.insert(x);
			b[pos]=x;break;
			case 3:
			scanf("%d",&x);
//			x=Rand(1,1000000);
			printf("%lld\n",solve(x));
			break;
		}
	return 0;
}