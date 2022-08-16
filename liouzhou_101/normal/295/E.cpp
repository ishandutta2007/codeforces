#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=1<<18;
const int INF=2000000000;

int n,m;
int x[MaxN],tx[MaxN];
vector<int> p;

struct node
{
	ll size;
	ll ans;
	ll ls,rs;
	ll lx,rx;
};

struct segment_tree
{
	node v[MaxN<<1];
	void update(node &c,node &Lc,node &Rc)
	{
		c.size=Lc.size+Rc.size;
		c.lx=min(Lc.lx,Rc.lx);
		c.rx=max(Lc.rx,Rc.rx);
		
		if (!c.size)
		{
			c.ls=c.rs=c.ans=0;
			return;
		}
		if (!Lc.size)
		{
			c=Rc;
			return;
		}
		if (!Rc.size)
		{
			c=Lc;
			return;
		}
		
		if (Rc.size)
			c.ls=Lc.ls+Rc.ls+Rc.size*(Rc.lx-Lc.lx);
		else
			c.ls=Lc.ls;
		
		if (Lc.size)
			c.rs=Rc.rs+Lc.rs+Lc.size*(Rc.rx-Lc.rx);
		else
			c.rs=Rc.rs;
		
		if (!Lc.size&&!Rc.size)
			c.ans=0;
		else if (!Lc.size)
			c.ans=Rc.ans;
		else if (!Rc.size)
			c.ans=Lc.ans;
		else
		{
			c.ans=Lc.ans+Rc.ans;
			c.ans+=Lc.rs*Rc.size;
			c.ans+=Rc.ls*Lc.size;
			c.ans+=(Rc.lx-Lc.rx)*Lc.size*Rc.size;
		}
	}
	void update(int k)
	{
		update(v[k],v[k<<1],v[k<<1|1]);
	}
	void insert(int k,int L,int R,int x)
	{
		if (L==R)
		{
			++v[k].size;
			v[k].ans=0;
			v[k].ls=v[k].rs=0;
			v[k].lx=v[k].rx=p[x-1];
			return;
		}
		int m=(L+R)>>1;
		if (x<=m)
			insert(k<<1,L,m,x);
		else
			insert(k<<1|1,m+1,R,x);
		update(k);
	}
	void insert(int x)
	{
		insert(1,1,MaxN,x+1);
	}
	void erase(int k,int L,int R,int x)
	{
		if (L==R)
		{
			--v[k].size;
			v[k].ans=0;
			v[k].ls=v[k].rs=0;
			v[k].lx=INF;
			v[k].rx=-INF;
			return;
		}
		int m=(L+R)>>1;
		if (x<=m)
			erase(k<<1,L,m,x);
		else
			erase(k<<1|1,m+1,R,x);
		update(k);
	}
	void erase(int x)
	{
		erase(1,1,MaxN,x+1);
	}
	node query(int k,int L,int R,int x,int y)
	{
		if (L==x&&R==y)
			return v[k];
		int m=(L+R)>>1;
		if (y<=m)
			return query(k<<1,L,m,x,y);
		if (x>m)
			return query(k<<1|1,m+1,R,x,y);
		node Lc=query(k<<1,L,m,x,m);
		node Rc=query(k<<1|1,m+1,R,m+1,y);
		node c;
		update(c,Lc,Rc);
		return c;
	}
	ll query(int x,int y)
	{
		return query(1,1,MaxN,x+1,y+1).ans;
	}
}T;

struct task
{
	int t,a,b;
	void init()
	{
		scanf("%d%d%d",&t,&a,&b);
		if (t==1)
		{
			x[a]+=b;
			p.push_back(x[a]);
		}
	}
	void solve()
	{
		if (t==1)
		{
			int px=lower_bound(p.begin(),p.end(),x[a])-p.begin();
			T.erase(px);
			x[a]+=b;
			int py=lower_bound(p.begin(),p.end(),x[a])-p.begin();
			T.insert(py);
		}
		else
		{
			a=lower_bound(p.begin(),p.end(),a)-p.begin();
			b=upper_bound(p.begin(),p.end(),b)-p.begin()-1;
			if (a>b)
				puts("0");
			else
				printf("%I64d\n",T.query(a,b));
		}
	}
}q[MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&x[i]);
		tx[i]=x[i];
		p.push_back(x[i]);
	}
	cin>>m;
	for (int i=1;i<=m;++i)
		q[i].init();
	for (int i=1;i<=n;++i)
		x[i]=tx[i];
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
}

void work()
{
	for (int i=1;i<(MaxN<<1);++i)
	{
		T.v[i].lx=INF;
		T.v[i].rx=-INF;
	}
	for (int i=1;i<=n;++i)
	{
		int px=lower_bound(p.begin(),p.end(),x[i])-p.begin();
		T.insert(px);
	}
	for (int i=1;i<=m;++i)
		q[i].solve();
}

int main()
{
	init();
	work();
	return 0;
}