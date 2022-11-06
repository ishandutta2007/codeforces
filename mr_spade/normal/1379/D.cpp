#include<cstdio>
#include<utility>
#define mp make_pair
#define fi first
#define se second
using std::pair;
using std::mp;
namespace sgt
{
	const int N=2e7+5;
	int n,tot,rt;
	int Min[N],pos[N],tag[N],ch[N][2];
	inline void push_up(int x,int lp,int rp)
	{
		if(!ch[x][0])
			Min[x]=0,pos[x]=lp;
		else if(!ch[x][1])
			Min[x]=0,pos[x]=rp;
		else if(Min[ch[x][0]]<Min[ch[x][1]])
			Min[x]=Min[ch[x][0]],pos[x]=pos[ch[x][0]];
		else
			Min[x]=Min[ch[x][1]],pos[x]=pos[ch[x][1]];
		return;
	}
	inline void new_node(int &x,int lp,int rp)
	{
		if(!x)
			x=++tot,pos[x]=lp;
	}
	inline void push_down(int x,int lp,int rp)
	{
		if(!tag[x])
			return;
		int mid=(lp+rp)>>1;
		new_node(ch[x][0],lp,mid);
		new_node(ch[x][1],mid+1,rp);
		Min[ch[x][0]]+=tag[x];tag[ch[x][0]]+=tag[x];
		Min[ch[x][1]]+=tag[x];tag[ch[x][1]]+=tag[x];
		tag[x]=0;
		return;
	}
	inline void modify(int &x,int lp,int rp,int l,int r)
	{
		if(l>r)
			return;
		new_node(x,lp,rp);
		if(lp==l&&rp==r)
			return Min[x]++,tag[x]++,void();
		int mid=(lp+rp)>>1;
		push_down(x,lp,rp);
		if(r<=mid)
			modify(ch[x][0],lp,mid,l,r);
		else if(l>=mid+1)
			modify(ch[x][1],mid+1,rp,l,r);
		else
			modify(ch[x][0],lp,mid,l,mid),modify(ch[x][1],mid+1,rp,mid+1,r);
		push_up(x,lp,rp);
		return;
	}
	inline pair<int,int> query(int x,int lp,int rp,int l,int r)
	{
		if(!x)
			return mp(0,lp);
		if(lp==l&&rp==r)
			return mp(Min[x],pos[x]);
		int mid=(lp+rp)>>1;
		push_down(x,lp,rp);
		if(r<=mid)
			return query(ch[x][0],lp,mid,l,r);
		else if(l>=mid+1)
			return query(ch[x][1],mid+1,rp,l,r);
		else
		{
			pair<int,int> res1=query(ch[x][0],lp,mid,l,mid);
			pair<int,int> res2=query(ch[x][1],mid+1,rp,mid+1,r);
			if(res1.fi<res2.fi)
				return res1;
			else
				return res2;
		}
	}
	inline void epc(int l,int r)
	{
		l%=n;r%=n;
		if(l<=r)
			modify(rt,0,n-1,l,r);
		else
			modify(rt,0,n-1,l,n-1),modify(rt,0,n-1,0,r);
		return;
	}
	inline pair<int,int> ask()
	{
		return query(rt,0,n-1,0,n-1);
	}
}
const int N=1e5+5;
int n,H,M,k;
int h[N],m[N];
signed main()
{
	int t,lp,rp;
	register int i;
	scanf("%d%d%d%d",&n,&H,&M,&k);
	sgt::n=M/2;
	if(k==1)
	{
		puts("0 0");
		puts("");
		return 0;
	}
	for(i=1;i<=n;i++)
		scanf("%d%d",&h[i],&m[i]);
	for(i=1;i<=n;i++)
	{
		t=m[i]%(M/2);
		lp=t+1;rp=t+k-1;
		sgt::epc(lp,rp);
	}
	pair<int,int> p=sgt::ask();
	printf("%d %d\n",p.fi,p.se);
	for(i=1;i<=n;i++)
	{
		t=m[i]%(M/2);
		lp=t+1;rp=t+k-1;
		if((lp<=p.se&&p.se<=rp)||(lp<=p.se+M/2&&p.se+M/2<=rp))
			printf("%d ",i);
	}
	putchar('\n');
	return 0;
}