#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
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

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQ(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;	
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double PI=acos(-1.0);

struct vert
{
	vector<int> inc;
	ll sum;
	ll gr,ls;
	bool was;
	vert()
	{
		gr=ls=0;
		was=0;
	}
} g[100100];


void dfs(int k,int pr)
{
	g[k].was=1;
	rep(i,0,g[k].inc.size())
	{
		int to=g[k].inc[i];
		if (to==pr) continue;
		if (!g[to].was)
			dfs(to,k);
		g[k].gr=max(g[k].gr,g[to].gr);
		g[k].ls=max(g[k].ls,g[to].ls);
	}
	g[k].sum-=g[k].gr-g[k].ls;
	if (g[k].sum<0)
		g[k].ls-=g[k].sum;
	else
		g[k].gr+=g[k].sum;
}



void run()
{
	int n;
	cin>>n;
	rep(i,0,n-1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;
		--b;
		g[a].inc.push_back(b);
		g[b].inc.push_back(a);
	}
	rep(i,0,n)
	{
		int a;
		scanf("%d",&a);
		g[i].sum=a;
	}
	dfs(0,-1);
	ll res=g[0].gr+g[0].ls;
	cout<<res<<endl;
}



int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);	
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}