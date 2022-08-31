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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=1<<17;
const int INF=1000000000;

int n,m;

struct wall
{
	int l,r,t;
}p[MaxN];

bool cmp_t(wall A,wall B)
{
	return A.t<B.t;
}

struct node
{
	node *Lc,*Rc;
	int L,R,m;
	int s,p;
	node (int x,int y)
	{
		Lc=Rc=0;
		L=x;
		R=y;
		m=(L+R)/2;
		if (m-L+1>R-m) --m;
		s=p=0;
	}
};

node *root;

void add(node *it,int L,int R,int v)
{
	if (it->L==L&&it->R==R)
	{
		it->p+=v;
		return;
	}
	it->s+=(R-L+1)*v;
	if (R<=it->m)
	{
		if (!it->Lc) it->Lc=new node(it->L,it->m);
		add(it->Lc,L,R,v);
	}
	else if (L>it->m)
	{
		if (!it->Rc) it->Rc=new node(it->m+1,it->R);
		add(it->Rc,L,R,v);
	}
	else
	{
		if (!it->Lc) it->Lc=new node(it->L,it->m);
		if (!it->Rc) it->Rc=new node(it->m+1,it->R);
		add(it->Lc,L,it->m,v);
		add(it->Rc,it->m+1,R,v);
	}
}

int get(node *it,int L,int R)
{
	if (!it) return 0;
	if (it->L==L&&it->R==R)
		return it->p*(R-L+1)+it->s;
	if (R<=it->m)
		return it->p*(R-L+1)+get(it->Lc,L,R);
	if (L>it->m)
		return it->p*(R-L+1)+get(it->Rc,L,R);
	return it->p*(R-L+1)+get(it->Lc,L,it->m)+get(it->Rc,it->m+1,R);
}

map<int,int> H;

void add_wall(int l,int r,int t)
{
	if (l>=r) return;
	H[l]=r;
	add(root,t-r+1,t-l,1);
	map<int,int>::iterator it=H.lower_bound(r);
	if (it!=H.end())
		if (it->X==r)
		{
			H[l]=it->Y;
			H.erase(it);
		}
	it=H.lower_bound(l);
	if (it!=H.begin())
	{
		--it;
		if (it->Y==l)
		{
			it->Y=H[l];
			H.erase(l);
		}
	}
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
		scanf("%d%d%d",&p[i].l,&p[i].r,&p[i].t);
	sort(p+1,p+m+1,cmp_t);
	root=new node(-INF,INF);
	for (int i=1;i<=m;++i)
	{
		int l=p[i].l,r=p[i].r;
		map<int,int>::iterator it=H.lower_bound(l);
		if (it!=H.begin())
		{
			--it;
			l=max(l,it->Y);
		}
		while (l<r)
		{
			it=H.lower_bound(l);
			if (it==H.end()) break;
			if (it->X>=r) break;
			add_wall(l,it->X,p[i].t);
			l=max(l,it->Y);
		}
		if (l<r) add_wall(l,r,p[i].t);
	}
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",get(root,-INF,x));
	}
	return 0;
}