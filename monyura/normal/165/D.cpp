#pragma comment(linker,"/STACK:64000000")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <Set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
#define x first
#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

typedef pair<double,double> pdd;
double Eps=1e-9;

struct vert
{
	vector<int> inc;
	vector<int> ind;
	int id;
	int *F;
	int h;
	int n;
	vert()
	{
		F=0;
	}
} g[100100];
int Nom[100100];
int st=0;
int cid;
int cnt;

void dfs(int k,int pr);

void build(int n)
{
	rep(i,0,n)
		if (g[i].inc.size()>2)
			st=i;
	g[st].h=0;
	rep(i,0,g[st].inc.size())
	{
		cnt=0;
		cid=i;
		Nom[g[st].ind[i]]=g[st].inc[i];
		dfs(g[st].inc[i],st);
	}
}

int get(int *F,int pos)
{
	int res=0;
	for (int i=pos;i>0;i-=i&-i)
		res+=F[i];
	return res;
}

void Set(int *F,int pos,int val,int n)
{
	for (int i=pos;i<=n;i+=i&-i)
		F[i]+=val;
}

int sum(int *F,int a,int b)
{
	return get(F,b)-get(F,a-1);
}



int BUFF[200200]={0};
int BUFFcnt=0;


int Col[100100];


void dfs(int k,int pr)
{
	cnt++;
	g[k].id=cid;
	g[k].h=g[pr].h+1;
	rep(i,0,g[k].inc.size())
		if (g[k].inc[i]!=pr)
		{
			dfs(g[k].inc[i],k);
			Nom[g[k].ind[i]]=g[k].inc[i];
			g[k].F=g[g[k].inc[i]].F;
		}
	g[k].n=cnt;
	if (g[k].F==0)
	{
		g[k].F=BUFF+BUFFcnt+1;
		BUFFcnt+=g[k].n;
	}
}

int proc(int a,int b)
{
	if (a==b) return 0;
	if (a==st)
		return sum(g[b].F,1,g[b].h)==0?g[b].h:-1;
	if (b==st)
		return sum(g[a].F,1,g[a].h)==0?g[a].h:-1;
	if (g[a].id!=g[b].id)
	{
		int s1=sum(g[a].F,1,g[a].h);
		int s2=sum(g[b].F,1,g[b].h);
		if (0==s1+s2)
			return g[a].h+g[b].h;
		return -1;
	}
	else
	{
		if (g[a].h>g[b].h)
			swap(a,b);
		int s=sum(g[a].F,g[a].h+1,g[b].h);
		if (s==0)
			return g[b].h-g[a].h;
		return -1;
	}
}

void change(int i)
{
	int v=Nom[i];
	if (Col[i]==0)
		Set(g[v].F,g[v].h,1,g[v].n);
	else
		Set(g[v].F,g[v].h,-1,g[v].n);
	Col[i]=!Col[i];
}

int main()
{
	int n;
	cin>>n;
	rep(i,0,n-1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].inc.push_back(b);
		g[a].ind.push_back(i);
		g[b].inc.push_back(a);
		g[b].ind.push_back(i);
	}
	build(n);
	int m;
	cin>>m;
	rep(i,0,m)
	{
		int t;
		scanf("%d",&t);
		if (t==1 || t==2)
		{
			int e;
			scanf("%d",&e);
			--e;
			change(e);
		}
		else
		{
			int a,b;
			scanf("%d%d",&a,&b);
			--a;--b;
			int res=proc(a,b);
			printf("%d\n",res);
		}
	}
	
	return 0;
}

/*
5
1 2
1 3
1 4
4 5
100
3 2 3
1 1
3 2 3
1 2
3 2 3
2 2
3 2 3
2 1
3 2 3
3 1 4
3 4 2
3 4 3
3 1 1
3 2 2
3 1 5
3 2 5
*/