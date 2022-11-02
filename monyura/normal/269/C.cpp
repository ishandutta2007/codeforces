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
	vector<int> w;
	vector<int> ind;
	int s;
	bool close;
} g[200100];

int Ans[200100];
pii E[200100];

void add(int a,int b,int c,int ind)
{
	g[a].inc.push_back(b);
	g[a].w.push_back(c);
	g[a].ind.push_back(ind);
	g[a].s+=c;
	g[b].inc.push_back(a);
	g[b].w.push_back(c);
	g[b].ind.push_back(ind);
	g[b].s+=c;
	
}


void run()
{
	memset(Ans,-1,sizeof(Ans));
	int n,m;
	cin>>n>>m;
	rep(i,0,m)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		--a;--b;
		add(a,b,c,i);
		E[i]=pii(a,b);
	}
	vector<int> q;
	q.push_back(0);
	while (!q.empty())
	{
		int v = q.back();
		q.pop_back();
		rep(i,0,g[v].inc.size())
		{
			int edge = g[v].ind[i];
			if (Ans[edge]==-1)
			{
				int to = 0;
				if (v!=E[edge].first)
					to = 1;
				Ans[edge] = to;
				int nxt = g[v].inc[i];
				g[nxt].s -= 2*g[v].w[i];
				if (g[nxt].s==0 && nxt!=n-1)
					q.push_back(nxt);
			}
		}
	}
	rep(i,0,m)
		printf("%d\n",Ans[i]);
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

/*
10 10 92
11 10 92
*/