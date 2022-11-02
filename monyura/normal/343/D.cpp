#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int SZ = 500100;
const int DO_SZ = 4 * SZ;

struct DO
{
	int Ass[DO_SZ];
	int Mx[DO_SZ];
	DO()
	{
		memset(Ass,-1,sizeof(Ass));
	}
	void build(int v, int l, int r, int val)
	{
		if (l==r)
		{
			Mx[v] = val;
			return;
		}
		int c = (l+r)>>1;
		build(2*v,l,c,val);
		build(2*v+1,c+1,r,val);
		Mx[v] = val;
	}
	void push(int v)
	{
		Ass[2*v] = Ass[v];
		Mx[2*v] = Ass[2*v];
		Ass[2*v+1] = Ass[v];
		Mx[2*v+1] = Ass[2*v+1];
		Ass[v] = -1;
	}
	void setVal(int v, int l,int r,int ql, int qr,int val)
	{
		if (l==ql && r==qr)
		{
			Ass[v] = val;
			Mx[v] = val;
			return;
		}
		if (Ass[v]!=-1)
			push(v);
		int c = (l+r)>>1;
		if (qr<=c)
			setVal(2*v,l,c,ql,qr,val);
		else if (ql>c)
			setVal(2*v+1,c+1,r,ql,qr,val);
		else
		{
			setVal(2*v,l,c,ql,c,val);
			setVal(2*v+1,c+1,r,c+1,qr,val);
		}
		Mx[v] = max(Mx[2*v], Mx[2*v+1]);
	}

	int getMax(int v, int l,int r,int ql, int qr)
	{
		if (Ass[v] != -1)
			return Ass[v];
		if (l==ql && r==qr)
			return Mx[v];
		int c = (l+r)>>1;
		if (qr<=c)
			return getMax(2*v,l,c,ql,qr);
		if (ql>c)
			return getMax(2*v+1,c+1,r,ql,qr);
		return max(getMax(2*v,l,c,ql,c), getMax(2*v+1,c+1,r,c+1,qr));
	}
};

DO Fill, empty;

struct vert
{
	vector<int> inc;
	int l,r;
} g[SZ];

int Tm = 0;
void dfs(int k, int prev)
{
	g[k].l = Tm++;
	rep(i,0,g[k].inc.size())
		if (g[k].inc[i]!=prev)
			dfs(g[k].inc[i], k);
	g[k].r = Tm - 1;
}


void run()
{
	int n;
	cin>>n;
	Fill.build(1,0,n-1,-1);
	empty.build(1,0,n-1,0);
	rep(i,0,n-1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].inc.push_back(b);
		g[b].inc.push_back(a);
	}
	Tm = 0;
	dfs(0, -1);
	//rep(i,0,n)
	//	printf("%d %d\n",g[i].l, g[i].r);
	int q;
	cin>>q;
	rep(i,0,q)
	{
		int type,v;
		scanf("%d%d",&type, &v);
		--v;
		if (type == 1)
		{
			Fill.setVal(1,0,n-1,g[v].l, g[v].r,i+1);
		}
		else if (type == 2)
		{
			empty.setVal(1,0,n-1,g[v].l,g[v].l,i+1);
		}
		else
		{
			int lastFill = Fill.getMax(1,0,n-1,g[v].l,g[v].l);
			int lastEmpty = empty.getMax(1,0,n-1,g[v].l, g[v].r);
			int res = lastFill > lastEmpty;
			printf("%d\n",res);
		}


	}
}

//#define prob "tria"

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
	#ifdef prob
		freopen(prob".in","r",stdin);
		freopen(prob".out","w",stdout);
	#endif
#endif
    run();
#ifdef _MONYURA_
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

    return 0;
}