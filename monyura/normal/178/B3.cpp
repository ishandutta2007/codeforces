//#pragma comment(linker,"/STACK:128000000")
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
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
//#define x first
//#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

struct vert
{
	vector<int> inc;
	bool was;
	int f;
	int h;
	int comp;
	vert()
	{
		was=0;
		h=0;
	}

} g[100100];

struct vertLCA
{
	vector<int> inc;
	int up[20];
	bool was;
	int h;
	vertLCA()
	{
		h=0;
		was=0;
	}
} gl[100100];


int ST[100100];
int pos=0;
int Cnt=0;

void dfs(int k,int fr)
{
	ST[pos++]=k;
	g[k].was=1;
	g[k].f=g[k].h;
	rep(i,0,g[k].inc.size())
		if (!g[g[k].inc[i]].was)
		{
			g[g[k].inc[i]].h=g[k].h+1;
			dfs(g[k].inc[i],k);
			if (g[g[k].inc[i]].f>g[k].h)
			{
				int lst=-1;
				do
				{
					lst=ST[--pos];
					g[lst].comp=Cnt;
				}
				while(lst!=g[k].inc[i]);
				Cnt++;
			}
			movmin(g[k].f,g[g[k].inc[i]].f);
		}
		else if (g[k].inc[i]!=fr)
			movmin(g[k].f,g[g[k].inc[i]].h);
}

void dfsLca(int k,int pr)
{
	gl[k].was=1;
	if (gl[k].h!=0)
	{
		gl[k].up[0]=pr;
		rep(i,1,20)
			gl[k].up[i]=gl[gl[k].up[i-1]].up[i-1];
	}
	rep(i,0,gl[k].inc.size())
		if (!gl[gl[k].inc[i]].was)
		{
			gl[gl[k].inc[i]].h=gl[k].h+1;
			dfsLca(gl[k].inc[i],k);
		}
}

int getAns(int a,int b)
{
	if (gl[a].h>gl[b].h) swap(a,b);
	int d=gl[b].h-gl[a].h;
	int res=d;
	rep(i,0,20)
		if (d&(1<<i))
			b=gl[b].up[i];
	if (a==b) return d;
	int st=0;
	while ((1<<st)<=gl[a].h) st++;
	st--;
	for (int j=st;j>=0;j--)
		if (gl[a].up[j]!=gl[b].up[j])
		{
			res+=1<<(j+1);
			a=gl[a].up[j];
			b=gl[b].up[j];
		}
	return res+2;
}

void run()
{
	int n,m;
	scanf("%d%d",&n,&m);
	pii E[100100];
	rep(i,0,m)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].inc.push_back(b);
		g[b].inc.push_back(a);
		E[i].first=a;
		E[i].second=b;
	}
	dfs(0,-1);
	int lst=-1;
	do
	{
		lst=ST[--pos];
		g[lst].comp=Cnt;
	}
	while(lst!=0);
	Cnt++;
	rep(i,0,m)
		if (g[E[i].first].comp!=g[E[i].second].comp)
		{
			gl[g[E[i].first].comp].inc.push_back(g[E[i].second].comp);
			gl[g[E[i].second].comp].inc.push_back(g[E[i].first].comp);
		}
	rep(i,0,Cnt)
	{
		sort(all(gl[i].inc));
		gl[i].inc.resize(unique(all(gl[i].inc))-gl[i].inc.begin());
	}
	dfsLca(0,-1);
	int k;
	cin>>k;
	rep(i,0,k)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		int ca=g[a].comp;
		int cb=g[b].comp;
		int res=getAns(ca,cb);
		printf("%d\n",res);
	}
}

int main()
{

#ifdef _MON_JUDGE_
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	time_t beg=clock();
	run();
#ifdef _MON_JUDGE_
	puts("=================");
	printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}

/*

*/