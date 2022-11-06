#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int inf=0x3f3f3f3f;
int n,q;
int a[N];
struct cell
{
	int pos,id;
};
vector<cell> qu[N];
int ans[N];
int bit[N];
inline void add(int x,int k)
{
	while(x<=n)
		bit[x]+=k,x+=x&-x;
	return;
}
inline int ask(int x)
{
	int res=0;
	while(x)
		res+=bit[x],x&=x-1;
	return res;
}
namespace tree
{
	const int N=3e5+5;
	int rt,tot;
	int key[N],tag[N],size[N],prio[N],Min[N],ch[N][2];
	inline void push_down(int x)
	{
		if(!tag[x])
			return;
		if(ch[x][0])
			key[ch[x][0]]+=tag[x],Min[ch[x][0]]+=tag[x],tag[ch[x][0]]+=tag[x];
		if(ch[x][1])
			key[ch[x][1]]+=tag[x],Min[ch[x][1]]+=tag[x],tag[ch[x][1]]+=tag[x];
		tag[x]=0;
		return;
	}
	inline void push_up(int x)
	{
		Min[x]=min(min(Min[ch[x][0]],Min[ch[x][1]]),key[x]);
		size[x]=size[ch[x][0]]+1+size[ch[x][1]];
		return;
	}
	void split(int z,int &x,int &y,int k)
	{
		if(!z)
			return x=y=0,void();
		push_down(z);
		if(size[ch[z][0]]+1<=k)
			x=z,split(ch[z][1],ch[z][1],y,k-size[ch[z][0]]-1);
		else
			y=z,split(ch[z][0],x,ch[z][0],k);
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
	int find(int x)
	{
		if(Min[x]>0)
			return 0;
		push_down(x);
		if(key[x]<=0)
			return size[ch[x][0]]+1;
		else if(Min[ch[x][0]]<=0)
			return find(ch[x][0]);
		else
			return size[ch[x][0]]+1+find(ch[x][1]);
	}
	inline void update(int k)
	{
//		printf("%d!\n",k);
		int x,y,z,w,d;
		add(k,1);
		split(rt,x,y,k);
		split(x,z,w,k-1);
		key[w]=Min[w]=inf;tag[w]=0;
		if(y)
			key[y]--,Min[y]--,tag[y]--;
		rt=merge(merge(z,w),y);
		if(d=find(rt))
			return update(d);
	}
	inline void set(int k,int dd)
	{
		int x,y,z,w,d;
		split(rt,x,y,k);
		split(x,z,w,k-1);
		key[w]=Min[w]=dd;tag[w]=0;
		rt=merge(merge(z,w),y);
		if(d=find(rt))
			return update(d);
	}
}
signed main()
{
	int l,r;
	register int i;
	tree::Min[0]=inf;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		tree::prio[i]=rand();
		tree::key[i]=tree::Min[i]=inf;tree::size[i]=1;
		tree::rt=tree::merge(tree::rt,i);
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		qu[l].push_back(cell{r,i});
	}
	for(i=n;i>=0;i--)
	{
		for(cell c:qu[i])
			ans[c.id]=ask(n-c.pos);
		if(i>0&&a[i]<=i)
			tree::set(i,i-a[i]);
	}
	for(i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}