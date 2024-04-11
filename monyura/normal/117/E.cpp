#pragma comment(linker,"/STACK:64000000")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
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

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define x first
#define y second

const double PI=acos(-1.0);

struct vert
{
	vector<int> inc;
	int h;
	int ind;
	int anc;
	int *D;
	int *V;
	int *Add;
	int n;
	int cnt;
	int from;
} g[100001];

int Anc[100001];
int N[100001];
int pathCnt;
int BuffD[400004];
int BuffV[100001];
int BuffAdd[400004];
int SumCnt[100001];

int Root;


int dfs(int k)
{
	g[k].cnt=1;
	rep(i,0,g[k].inc.size())
		if (g[g[k].inc[i]].h==-1)
		{
			g[g[k].inc[i]].h=g[k].h+1;
			g[g[k].inc[i]].from=k;
			g[k].cnt+=dfs(g[k].inc[i]);
		}
	bool st=1;
	rep(i,0,g[k].inc.size())
		if (g[g[k].inc[i]].h>g[k].h)
		{
			if (g[g[k].inc[i]].cnt*2>=g[k].cnt && k!=Root)
			{
				st=0;
				g[k].n=g[g[k].inc[i]].n;
				N[g[k].n]++;
				g[k].ind=g[g[k].inc[i]].ind+1;
			}
			Anc[g[g[k].inc[i]].n]=k;
		}
	if (st)
	{
		g[k].n=pathCnt++;
		Anc[g[k].n]=k;
		N[g[k].n]=1;
		g[k].ind=0;
	}
	return g[k].cnt;
}

void buildHeavyLight(int st,int n)
{
	Root=st;
	pathCnt=0;
	rep(i,0,n)
		g[i].h=-1;
	g[Root].h=0;
	dfs(st);
	SumCnt[0]=0;
	rep(i,1,pathCnt)
		SumCnt[i]=SumCnt[i-1]+N[i-1];
	memset(BuffD,0,sizeof(int)*4*n);
	memset(BuffAdd,0,sizeof(int)*4*n);
	rep(i,0,n)
	{
		g[i].anc=Anc[g[i].n];
		g[i].D=BuffD+4*SumCnt[g[i].n];
		g[i].V=BuffV+SumCnt[g[i].n];
		g[i].Add=BuffAdd+4*SumCnt[g[i].n];
		g[i].V[g[i].ind]=i;

		g[i].n=N[g[i].n];
	}
}

int *Tree;
int *Add;


int SegTreeGet(int v,int l,int r,int ql,int qr)
{
	if (l==ql && r==qr)
		return Add[v]&1 ? r-l+1-Tree[v] : Tree[v];
	int c=(l+r)>>1;
	int val;
	if (qr<=c)
		val=SegTreeGet(2*v,l,c,ql,qr);
	else if (ql>c)
		val=SegTreeGet(2*v+1,c+1,r,ql,qr);
	else
		val=SegTreeGet(2*v,l,c,ql,c)+SegTreeGet(2*v+1,c+1,r,c+1,qr);
	return Add[v]&1 ? qr-ql+1-val : val;
}

void SegTreeChange(int v,int l,int r,int ql,int qr)
{
	if (l==ql && r==qr)
	{
		Add[v]++;
		return;
	}
	int c=(l+r)>>1;
	if (qr<=c)
		SegTreeChange(2*v,l,c,ql,qr);
	else if (ql>c)
		SegTreeChange(2*v+1,c+1,r,ql,qr);
	else
	{
		SegTreeChange(2*v,l,c,ql,c);
		SegTreeChange(2*v+1,c+1,r,c+1,qr);
	}
	Tree[v]=(Add[2*v]&1 ? c-l+1-Tree[2*v]:Tree[2*v]) +
			(Add[2*v+1]&1? r-c-Tree[2*v+1]:Tree[2*v+1]);
}

int getCnt(int a,int b)
{
	int res=0;
	while (g[a].D!=g[b].D)
	{
		if (g[g[a].anc].h<g[g[b].anc].h || a==Root) swap(a,b);
		Tree=g[a].D;
		Add=g[a].Add;
		res+=SegTreeGet(1,0,g[a].n-1,g[a].ind,g[a].n-1);
		a=g[a].anc;
	}
	if (g[a].h>g[b].h) swap(a,b);
	if (a!=b)
	{
		Tree=g[a].D;
		Add=g[a].Add;
		res+=SegTreeGet(1,0,g[a].n-1,g[b].ind,g[a].ind-1);
	}
	return res;
}

int updateCnt(int a,int b)
{
	int res=0;
	while (g[a].D!=g[b].D)
	{
		if (g[g[a].anc].h<g[g[b].anc].h || a==Root) swap(a,b);
		Tree=g[a].D;
		Add=g[a].Add;
		SegTreeChange(1,0,g[a].n-1,g[a].ind,g[a].n-1);
		res+=SegTreeGet(1,0,g[a].n-1,g[a].ind,g[a].n-1);
		a=g[a].anc;
	}
	if (g[a].h>g[b].h) swap(a,b);
	if (a!=b)
	{
		Tree=g[a].D;
		Add=g[a].Add;
		SegTreeChange(1,0,g[a].n-1,g[b].ind,g[a].ind-1);
		res+=SegTreeGet(1,0,g[a].n-1,g[b].ind,g[a].ind-1);
	}
	return res;
}

int lca(int a,int b,int &path)
{
	path=g[a].h+g[b].h;
	while (g[a].D!=g[b].D)
	{
		if (g[g[a].anc].h<g[g[b].anc].h || a==Root) swap(a,b);
		a=g[a].anc;
	}
	if (g[a].h>g[b].h) swap(a,b);
	path-=2*g[a].h;
	return a;
}

int v0,u0;

void dfs2(int k,int from)
{
	g[k].h=1;
	rep(i,0,g[k].inc.size())
		if (g[k].inc[i]!=from)
		{
			if (g[g[k].inc[i]].h)
			{
				u0=k;
				v0=g[k].inc[i];
			}
			else
				dfs2(g[k].inc[i],k);
		}
}

bool rebro;
int sum;

int nextVert(int a,int b)
{
	if (g[a].h>g[b].h) return g[a].from;
	while (g[b].D!=g[a].D && g[b].anc!=a)
		b=g[b].anc;
	if (g[b].D==g[a].D) return g[b].V[g[a].ind-1];
	return g[b].V[g[b].n-1];
}

bool ExistCicle(int a,int b)
{
	int path;
	lca(a,b,path);
	return path==getCnt(a,b) && rebro;
}

void calcTree(int u,int v)
{
	sum-=getCnt(u,v);
	sum+=updateCnt(u,v);
}

void calcCicle(int u,int v,int path,int i,int n)
{
	int uu0,vv0,tmp;
	int a=lca(u,u0,uu0);
	lca(v,v0,vv0);
	bool ok=path>uu0+vv0+1;
	if (path==uu0+vv0+1)
	{
		//Need to check lexicographical smallest;
		int b=lca(u,v,tmp);
		int tou0=u0,tov=b;
		if (a!=b)
		{
			if (g[a].h<g[b].h)
			{
				tou0=a;
				tov=v;
				a=b;
			}
		}
		else
		{
			a=lca(v,u0,tmp);
			tou0=u0;
			tov=v;
		}
		if (a==u0 && nextVert(a,tov)>v0)
			ok=true;
		if (a!=u0 && nextVert(a,tov)>nextVert(a,tou0))
			ok=true;
	/*	if (i==143 && n==18)
		{
			if (u==v0 ||
			sum=-10000;
			return;
		}*/
	}
	if (ok)
	{
		rebro=!rebro;
		if (rebro) ++sum;
		else --sum;
		sum-=getCnt(u,u0)+getCnt(v,v0);
		sum+=updateCnt(u,u0)+updateCnt(v,v0);
	}
	else
		calcTree(u,v);
}

int query(int u,int v,int n,int T)
{
	if (u!=v)
	{
		int path;
		int a=lca(u,v,path);
		int uu0,uv0,vv0,vu0;
		lca(u,u0,uu0);
		lca(u,v0,uv0);
		lca(v,u0,vu0);
		lca(v,v0,vv0);
		if (uu0+vv0>uv0+vu0)
			swap(u0,v0);
		if (path<min(uu0+vv0,uv0+vu0)+1)
			calcTree(u,v);
		else
			calcCicle(u,v,path,T,n);
	}
	if (ExistCicle(u0,v0))
		return n-sum+1;
	else
		return n-sum;
}

int main()
{
	int n,m;
	cin>>n>>m;
	rep(i,0,n)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].inc.push_back(b);
		g[b].inc.push_back(a);
	}
	rep(i,0,n)
		g[i].h=0;
	dfs2(0,-1);
	rep(j,0,g[u0].inc.size())
		if (g[u0].inc[j]==v0)
		{
			g[u0].inc.erase(g[u0].inc.begin()+j);
			break;
		}
	rep(j,0,g[v0].inc.size())
		if (g[v0].inc[j]==u0)
		{
			g[v0].inc.erase(g[v0].inc.begin()+j);
			break;
		}
	rebro=false;
	sum=0;
	buildHeavyLight(0,n);
	//cout<<"q"<<endl;
	rep(i,0,m)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		--u;--v;
		int res=query(u,v,n,i);
		printf("%d\n",res);
	}
	return 0;
} 

/*
7 100
4 1
2 4
7 3
2 7
2 5
7 1
1 6


2 5
3 4
3 4
2 5



17 500
12 15
11 4
15 13
2 11
11 5
5 6
3 2
11 13
6 8
17 10
9 17
3 14
16 7
14 16
15 1
2 9
3 12

16 2
1 4
15 9
13 11
10 12
14 1
13 11
2 17
5 11
16 3
15 15
11 4
12 9
9 7
4 15
4 2
3 16
1 17
17 7
10 1
8 2
7 5
6 15
17 4


*/