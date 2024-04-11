#pragma GCC optimize(2,"inline")
#include<cstdio>
#include<cmath>
#include<algorithm>
#define random Mr_Spade
#define getchar() *(fin++)
#define putchar(x) (*(fout++)=(x))
using std::swap;
char *fin,*fout;
char in[1<<23],out[1<<23];
inline int read()
{
	int res=0;
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	for(;ch>='0'&&ch<='9';ch=getchar())
		res=res*10+ch-'0';
	return res;
}
inline void write(int x)
{
	if(x>=10)
		write(x/10);
	putchar(x%10+'0');
	return;
}
inline int random()
{
	static int x=17;
	return x^=x<<13,x^=x>>5,x^=x<<17,x;
}
const int N=1e5+5,SQRTN=400;
const int mod=(1<<20)-1;
int n,m,unit;
int a[N];
int bl[N];
int cnt[SQRTN][N];
namespace treap
{
	int root,tot;
	int key[N],prio[N],size[N],ch[N][2];
	struct Queue
	{
		int q[1<<20],head,tail;
		inline void push(int x)
		{
			q[tail++&mod]=x;
			return;
		}
		inline void pop()
		{
			head++;
			return;
		}
		inline int front()
		{
			return q[head&mod];
		}
		inline bool empty()
		{
			return head==tail;
		}
	}Q;
	inline int new_node(int k)
	{
		int x=++tot;
		key[x]=k;prio[x]=random();size[x]=1;
		return x;
	}
	inline void push_up(int x)
	{
		size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
		return;
	}
	void split(int now,int &x,int &y,int k)
	{
		if(!now)
			return x=y=0,void();
		if(size[ch[now][0]]<k)
			x=now,split(ch[now][1],ch[now][1],y,k-size[ch[now][0]]-1);
		else
			y=now,split(ch[now][0],x,ch[now][0],k);
		push_up(now);
		return;
	}
	int merge(int x,int y)
	{
		if(x*y==0)
			return x+y;
		if(prio[x]<prio[y])
			return ch[x][1]=merge(ch[x][1],y),push_up(x),x;
		else
			return ch[y][0]=merge(x,ch[y][0]),push_up(y),y;
	}
	inline void rotate(int l,int r)
	{
		int x,y,z,w,x1,x2;
		split(root,x,y,r);
		split(x,z,w,l-1);
		split(w,x1,x2,size[w]-1);
		w=merge(x2,x1);
		x=merge(z,w);
		root=merge(x,y);
		return;
	}
	inline void push_back(int k)
	{
		root=merge(root,new_node(k));
		return;
	}
	inline int ask(int pos)
	{
		int x=root;
		while(pos)
			if(size[ch[x][0]]+1==pos)
				return key[x];
			else if(size[ch[x][0]]+1<pos)
				pos-=size[ch[x][0]]+1,x=ch[x][1];
			else
				x=ch[x][0];
		return -1;
	}
	inline int count(int l,int r,int k)
	{
		int res=0,now;
		int x,y,z,w;
		split(root,x,y,r);
		split(x,z,w,l-1);
		if(w)
			Q.push(w);
		while(!Q.empty())
		{
			now=Q.front();Q.pop();
			res+=(key[now]==k);
			if(ch[now][0])
				Q.push(ch[now][0]);
			if(ch[now][1])
				Q.push(ch[now][1]);
		}
		x=merge(z,w);
		root=merge(x,y);
		return res;
	}
}
void modify(int l,int r)
{
	int last;
	register int i;
	if(bl[l]==bl[r])
		void();
	else
	{
		cnt[bl[l]][treap::ask(r)]++;
		cnt[bl[l]][last=treap::ask(bl[l]*unit)]--;
		for(i=bl[l]+1;i<=bl[r]-1;i++)
		{
			cnt[i][last]++;
			cnt[i][last=treap::ask(i*unit)]--;
		}
		cnt[bl[r]][last]++;
		cnt[bl[r]][treap::ask(r)]--;
	}
	treap::rotate(l,r);
	return;
}
int query(int l,int r,int k)
{
	int res=0;
	register int i;
	if(bl[l]==bl[r])
		return treap::count(l,r,k);
	if(bl[l]*unit-l+1<=unit/2)
		res+=treap::count(l,bl[l]*unit,k);
	else
		res+=cnt[bl[l]][k]-treap::count((bl[l]-1)*unit+1,l-1,k);
	for(i=bl[l]+1;i<=bl[r]-1;i++)
		res+=cnt[i][k];
	if(r-(bl[r]-1)*unit<=unit/2)
		res+=treap::count((bl[r]-1)*unit+1,r,k);
	else
		res+=cnt[bl[r]][k]-treap::count(r+1,bl[r]*unit,k);
	return res;
}
inline void init()
{
	register int i;
	unit=ceil(sqrt(n*log2(n))*1.3);
	for(i=1;i<=n;i++)
		bl[i]=(i+unit-1)/unit;
	for(i=1;i<=n;i++)
		treap::push_back(a[i]);
	for(i=1;i<=n;i++)
		cnt[bl[i]][a[i]]++;
	return;
}
signed main()
{
	fin=in;fout=out;
	fread(in,1,1<<23,stdin);
	int l,r,k,lastans=0;
	register int i;
	n=read();
	for(i=1;i<=n;i++)
		a[i]=read();
	m=read();
	init();
	while(m--)
		if(read()&1)
		{
			l=(read()+lastans-1)%n+1;r=(read()+lastans-1)%n+1;
			if(l>r)
				swap(l,r);
			modify(l,r);
		}
		else
		{
			l=(read()+lastans-1)%n+1;r=(read()+lastans-1)%n+1;k=(read()+lastans-1)%n+1;
			if(l>r)
				swap(l,r);
			write(lastans=query(l,r,k));putchar('\n');
		}
	fwrite(out,1,fout-out,stdout);
	return 0;
}