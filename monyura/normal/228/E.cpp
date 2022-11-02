#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <cstdio>
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
#include <cmath>
#include <queue>
#include <ctime>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct vert
{
	vector<int> inc;
	vector<int> c;
	bool was;
	int val;
	vert()
	{
		was=0;
	}
} g[200];

bool allOk;
vector<int> v;
void dfs(int k)
{
	v.push_back(k);
	g[k].was=1;
	rep(i,0,g[k].inc.size())
	{
		if (!g[g[k].inc[i]].was)
		{
			g[g[k].inc[i]].val = (g[k].val ^ g[k].c[i]);
			dfs(g[k].inc[i]);
		}
		else if (g[g[k].inc[i]].val != (g[k].val^g[k].c[i]))
			allOk=0;
	}
}


void run()
{
	int n,m;
	cin>>n>>m;
	rep(i,0,m)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		--a;--b;
		c^=1;
		g[a].inc.push_back(b);
		g[a].c.push_back(c);
		g[b].inc.push_back(a);
		g[b].c.push_back(c);
	}
	rep(i,0,n)
		if (!g[i].was)
		{
			bool find=0;
			rep(val,0,2)
			{
				g[i].val = val;
				allOk = 1;
				v.clear();
				dfs(i);
				if (allOk)
				{
					find=1;
					break;
				}
				rep(j,0,v.size())
					g[v[j]].was=0;
			}
			if (!find)
			{
				puts("Impossible");
				return;
			}
		}
	vector<int> res;
	rep(i,0,n)
		if (g[i].val)
			res.push_back(i);
	printf("%d\n",res.size());
	rep(i,0,res.size())
		printf("%d ",res[i]+1);
	puts("");

}



int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#endif
    run();
#ifdef _MONYURA_
    printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*

*/