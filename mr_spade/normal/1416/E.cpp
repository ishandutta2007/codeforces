#include<bits/stdc++.h>
using namespace std;
namespace treap
{
	const int N=5e6+5,inf=0x3f3f3f3f;
	int rt,tot;
	queue<int> tr;//trash
	int len[N],key[N],Min[N],atag[N],tag[N];
	bool rev[N];
	int prio[N],size[N],ch[N][2];
	inline void init()
	{
		key[0]=Min[0]=tag[0]=inf;
		return;
	}
	inline void clear()
	{
		while(!tr.empty())
			tr.pop();
		memset(len+1,0,sizeof(int)*tot);
		memset(key+1,0,sizeof(int)*tot);
		memset(Min+1,0,sizeof(int)*tot);
		memset(atag+1,0,sizeof(int)*tot);
		memset(tag+1,0,sizeof(int)*tot);
		memset(rev+1,0,sizeof(bool)*tot);
		memset(prio+1,0,sizeof(int)*tot);
		memset(size+1,0,sizeof(int)*tot);
		for(int i=1;i<=tot;i++)
			ch[i][0]=ch[i][1]=0;
		rt=tot=0;
		return;
	}
	inline int new_id()
	{
		return ++tot;
		while(!tr.empty()&&tr.front()==0)
			tr.pop();
		if(tr.empty())
			return ++tot;
		int x=tr.front();tr.pop();
		if(ch[x][0])
			tr.push(ch[x][0]);
		if(ch[x][1])
			tr.push(ch[x][1]);
		return x;
	}
	inline void set_rev(int x)
	{
		if(!x)
			return;
		swap(ch[x][0],ch[x][1]),rev[x]^=1;
		return;
	}
	inline void set_atag(int x,int k)
	{
		if(!x)
			return;
		key[x]+=k;Min[x]+=k;atag[x]+=k;tag[x]+=k;
		return;
	}
	inline void set_tag(int x,int k)
	{
		if(!x)
			return;
		key[x]=min(key[x],k),Min[x]=min(Min[x],k),tag[x]=min(tag[x],k);
		return;
	}
	inline void push_down(int x)
	{
		if(rev[x])
			set_rev(ch[x][0]),set_rev(ch[x][1]),rev[x]=0;
		if(atag[x])
			set_atag(ch[x][0],atag[x]),set_atag(ch[x][1],atag[x]),atag[x]=0;
		if(tag[x]<inf)
			set_tag(ch[x][0],tag[x]),set_tag(ch[x][1],tag[x]),tag[x]=inf;
		return;
	}
	inline void push_up(int x)
	{
		size[x]=size[ch[x][0]]+len[x]+size[ch[x][1]];
		Min[x]=min(min(Min[ch[x][0]],key[x]),Min[ch[x][1]]);
		return;
	}
	inline int new_node(int l,int k)
	{
		int x=new_id();
		len[x]=l;key[x]=Min[x]=k;atag[x]=0;tag[x]=inf;rev[x]=0;
		prio[x]=rand();size[x]=l;ch[x][0]=ch[x][1]=0;
		return x;
	}
	void split(int z,int &x,int &y,int k)
	{
		if(!z)
			return x=y=0,void();
		push_down(z);
		if(size[ch[z][0]]+len[z]<=k)
			x=z,split(ch[z][1],ch[z][1],y,k-size[ch[z][0]]-len[z]);
		else
			y=z,split(ch[z][0],x,ch[z][0],k);
		push_up(z);
		return;
	}
	void split2(int z,int &x,int &y,int k)
	{
		if(!z)
			return x=y=0,void();
		push_down(z);
		if(size[ch[z][0]]+1<=k)
			x=z,split2(ch[z][1],ch[z][1],y,k-size[ch[z][0]]-len[z]);
		else
			y=z,split2(ch[z][0],x,ch[z][0],k);
		push_up(z);
		return;
	}
	int merge(int x,int y)
	{
		if(!x||!y)
			return x+y;
		if(prio[x]<prio[y])
			return push_down(x),ch[x][1]=merge(ch[x][1],y),push_up(x),x;
		else
			return push_down(y),ch[y][0]=merge(x,ch[y][0]),push_up(y),y;
	}
	inline int query(int t)
	{
		int x,y,z,w,k;
		split2(rt,x,y,t);
		split(x,z,w,size[x]-1);
		k=key[w];
		rt=merge(merge(z,w),y);
		return k;
	}
	inline void modi(int t,int k2)
	{
		int x,y,z,w,k,l,lp=0,rp=0;
		split2(rt,x,y,t);
		split(x,z,w,size[x]-1);
		k=key[w];l=len[w];tr.push(w);
		if(size[z]<t-1)
			lp=new_node(t-1-size[z],k);
		if(size[z]+l>t)
			rp=new_node(size[z]+l-t,k);
		rt=merge(z,merge(merge(merge(lp,new_node(1,min(k,k2))),rp),y));
		return;
	}
	inline void modi_size(int n)
	{
		int x,y,z,w,k;
		if(size[rt]==n)
			return;
		if(size[rt]<n)
			return rt=merge(rt,new_node(n-size[rt],inf)),void();
		split2(rt,x,y,n);tr.push(y);
		if(size[x]==n)
			return rt=x,void();
		split(x,z,w,size[x]-1);k=key[w];tr.push(w);
		rt=merge(z,new_node(n-size[z],k));
		return;
	}
	inline void reverse()
	{
		set_rev(rt);
		return;
	}
	inline void add(int k)
	{
		set_atag(rt,k);
		return;
	}
	inline void mini(int k)
	{
		set_tag(rt,k);
		return;
	}
}
const int N=5e5+5;
int n,cur;
int a[N];
inline void solve(int ttt)
{
	int bk,tl=0;
	register int i;
	scanf("%d",&n);cur=0;
	tl=n;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),tl=tl*10+a[i];
//	if(ttt==83)
//		exit(tl);
	for(i=1;i<=n;i++)
	{
		treap::modi_size(a[i]-1);
		if(a[i]%2==0)
		{
			bk=1;
			if(treap::query(a[i]/2)==0)
				bk=0;
		}
		treap::reverse();
		treap::add(1);
		treap::mini(2);
		if(a[i]%2==0)
			treap::modi(a[i]/2,bk);
		if(treap::Min[treap::rt])
		{
			cur+=treap::Min[treap::rt];
			treap::add(-treap::Min[treap::rt]);
		}
	}
	printf("%d\n",cur);
	treap::clear();
	return;
}
signed main()
{
	treap::init();
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
		solve(i);
	return 0;
}