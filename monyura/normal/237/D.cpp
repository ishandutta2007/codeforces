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
#define SQ(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const double PI=acos(-1.0);

struct vert
{
	vector<int> inc;
	bool was;
	int id;
	vert()
	{
		was=0;
		id=-1;
	}
} g[100100];

struct node
{
	int a,b;
	vector<int> inc;
	bool was;
	node()
	{
		was=0;
	}
} V[100100];

int cnt=0;

void dfs(int k)
{
	g[k].was=1;
	int prev=g[k].id;
	rep(i,0,g[k].inc.size())
	{
		int v=g[k].inc[i];
		if (!g[v].was)
		{
			g[v].id=cnt;
			V[cnt].a=k;
			V[cnt].b=v;
			if (prev!=-1)
			{
				V[cnt].inc.push_back(prev);
				V[prev].inc.push_back(cnt);
			}
			prev=cnt;
			cnt++;
			dfs(v);
			
		}
	}
}

vector<pii> res;
void dfs2(int k)
{
	V[k].was=1;
	rep(i,0,V[k].inc.size())
	{
		int v=V[k].inc[i];
		if (!V[v].was)
		{
			res.push_back(pii(k,v));
			dfs2(v);
		}
	}
}

void run()
{
	int n;
	cin>>n;
	rep(i,0,n-1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].inc.push_back(b);
		g[b].inc.push_back(a);
	}
	dfs(0);
	dfs2(0);
	printf("%d\n",n-1);
	rep(i,0,n-1)
		printf("2 %d %d\n",V[i].a+1,V[i].b+1);
	rep(i,0,res.size())
		printf("%d %d\n",res[i].first+1,res[i].second+1);
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