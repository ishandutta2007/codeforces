#pragma comment(linker,"/STACK:65000000")
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
#include <assert.h>


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
typedef vector<int> vi;

const double PI = acos(-1.0);

vector<int> curr;

struct vert
{
	vector<int> inc;
	bool was;
	vert()
	{
		was =0;
	}
} g[100];

void dfs(int k)
{
	g[k].was = 1;
	curr.push_back(k+1);
	rep(i,0,g[k].inc.size())
		if (!g[g[k].inc[i]].was)
			dfs(g[k].inc[i]);

}

void run()
{
	int n,m;
	cin>>n>>m;
	rep(i,0,m)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].inc.push_back(b);
		g[b].inc.push_back(a);
	}
	vector<vector<int> > Cnt[4];
	rep(i,0,n)
		if (!g[i].was)
		{
			curr.clear();
			dfs(i);
			if (curr.size()>3)
			{
				puts("-1");
				return;
			}
			Cnt[curr.size()].push_back(curr);
		}
	if (Cnt[2].size()>Cnt[1].size())
	{
		puts("-1");
		return;
	}
	rep(i,0,Cnt[3].size())
	{
		rep(j,0,3)
			printf("%d ",Cnt[3][i][j]);
		puts("");
	}
	rep(i,0,Cnt[2].size())
		printf("%d %d %d\n",Cnt[2][i][0],Cnt[2][i][1],Cnt[1][i][0]);
	for (int i=Cnt[2].size();i<Cnt[1].size();i+=3)
		printf("%d %d %d\n",Cnt[1][i][0],Cnt[1][i+1][0],Cnt[1][i+2][0]);
}


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(name".in","r",stdin);
	//freopen(name".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
24 54 96 108
*/