#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
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

const int MaxN=1<<18;

int n,m,k;
map<int,set<pii> > a,b;
set<pii> H;
map<pii,set<pii> > u;
pii s,w;

void add_point(int x,int y)
{
	pii p(x,y);
	a[x+y].insert(p);
	b[x-y].insert(p);
	H.insert(p);
}

void init()
{
	cin>>n>>m>>k;
	for (int i=0;i<=n+1;++i)
	{
		add_point(i,0);
		add_point(i,m+1);
	}
	for (int j=0;j<=m+1;++j)
	{
		add_point(0,j);
		add_point(n+1,j);
	}
	for (int i=1;i<=k;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_point(x,y);
	}
	string s;
	cin>>::s.X>>::s.Y>>s;
	w=pii((s[0]=='N')?-1:1,(s[1]=='W')?-1:1);
}

pii operator - (pii a,pii b)
{
	return pii(a.X-b.X,a.Y-b.Y);
}

pii operator - (pii a)
{
	return pii(-a.X,-a.Y);
}

vector<pii> pa[MaxN],pb[MaxN];

void add_line(pii a,pii b)
{
	//cout<<a.X<<a.Y<<" "<<b.X<<b.Y<<endl;
	if (a>b) swap(a,b);
	if (a.X+a.Y==b.X+b.Y)
		pa[a.X+a.Y].push_back(pii(a.X-a.Y+m,b.X-b.Y+m));
	else
		pb[a.X-a.Y+m].push_back(pii(a.X+a.Y,b.X+b.Y));
}

ll ans;

void deal(vector<pii> &p)
{
	if (p.empty()) return;
	sort(p.begin(),p.end());
	vector<pii> v;
	pii a=p[0];
	for (int i=1;i<p.size();++i)
	{
		if (p[i].X>a.Y)
		{
			v.push_back(a);
			a=p[i];
		}
		else
			a.Y=max(a.Y,p[i].Y);
	}
	v.push_back(a);
	p=v;
	for (int i=0;i<p.size();++i)
		ans+=(p[i].Y-p[i].X)/2+1;
}

vector<pii> p[MaxN];

void add_event(int a,int b,int c)
{
	p[b].push_back(pii(a,c));
}

int v[MaxN];

void add(int x,int p)
{
	for (;x<MaxN;x+=x&-x)
		v[x]+=p;
}

int get(int x)
{
	int p=0;
	for (;x;x-=x&-x)
		p+=v[x];
	return p;
}

int get(int x,int y)
{
	return get(y)-get(x-1);
}

void work()
{
	while (1)
	{
		set<pii>::iterator it;
		if (w==pii(-1,1))
			it=--a[s.X+s.Y].upper_bound(s);
		else if (w==pii(-1,-1))
			it=--b[s.X-s.Y].upper_bound(s);
		else if (w==pii(1,1))
			it=b[s.X-s.Y].upper_bound(s);
		else
			it=a[s.X+s.Y].upper_bound(s);
		add_line(s,*it-w);
		s=*it-w;
		if (!(u[*it].insert(w).Y)) break;
		int x=H.count(pii(it->X-w.X,it->Y));
		int y=H.count(pii(it->X,it->Y-w.Y));
		if (x==y)
			w=-w;
		else if (x)
		{
			s.X+=w.X;
			w.Y=-w.Y;
		}
		else
		{
			s.Y+=w.Y;
			w.X=-w.X;
		}
	}
	/*
	for (int i=1;i<=n+m;++i)
	{
		pa[i].clear();
		pb[i].clear();
	}
	add_line(pii(1,1),pii(3,3));
	add_line(pii(1,3),pii(3,1));
	add_line(pii(1,2),pii(2,3));
	add_line(pii(2,3),pii(2,3));
	add_line(pii(2,3),pii(3,2));
	*/
	for (int i=1;i<=n+m;++i)
	{
		deal(pa[i]);
		deal(pb[i]);
	}
	/*
	for (int i=1;i<=n+m;++i)
	{
		printf("%d:",i);
		for (int j=0;j<pa[i].size();++j)
			printf("(%d,%d)",pa[i][j].X,pa[i][j].Y);
		puts("");
	}
	for (int i=1;i<=n+m;++i)
	{
		printf("%d:",i);
		for (int j=0;j<pb[i].size();++j)
			printf("(%d,%d)",pb[i][j].X,pb[i][j].Y);
		puts("");
	}
	*/
	/*
	set<pii> Q;
	for (int i=1;i<=n+m;++i)
	{
		for (vector<pii>::iterator it=pa[i].begin();it!=pa[i].end();++it)
			for (int d=it->X;d<=it->Y;d+=2)
			{
				if (!Q.insert(pii(i,d)).Y) --ans;
			}
		for (vector<pii>::iterator it=pb[i].begin();it!=pb[i].end();++it)
			for (int d=it->X;d<=it->Y;d+=2)
			{
				if (!Q.insert(pii(d,i)).Y) --ans;
			}
	}
	*/
	for (int i=1;i<=n+m;++i)
	{
		for (vector<pii>::iterator it=pb[i].begin();it!=pb[i].end();++it)
		{
			add_event(i,it->X,1);
			add_event(i,it->Y+2,-1);
		}
	}
	for (int i=1;i<=n+m;i+=2)
	{
		for (vector<pii>::iterator it=p[i].begin();it!=p[i].end();++it)
			add(it->X,it->Y);
		for (vector<pii>::iterator it=pa[i].begin();it!=pa[i].end();++it)
			ans-=get(it->X,it->Y);
	}
	memset(v,0,sizeof(v));
	for (int i=2;i<=n+m;i+=2)
	{
		for (vector<pii>::iterator it=p[i].begin();it!=p[i].end();++it)
			add(it->X,it->Y);
		for (vector<pii>::iterator it=pa[i].begin();it!=pa[i].end();++it)
			ans-=get(it->X,it->Y);
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}