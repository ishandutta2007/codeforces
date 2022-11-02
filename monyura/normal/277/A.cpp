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
	bool was;
	vert()
	{
		was=0;
	}
} g[101];

void dfs(int k)
{
	g[k].was=1;
	rep(i,0,g[k].inc.size())
	{
		int to =g[k].inc[i];
		if (!g[to].was)
			dfs(to);
	}
}


void run()
{
	int n,m;
	cin>>n>>m;
	bool A[101][101]={0};
	bool allOne = n!=1;
	rep(i,0,n)
	{
		int k;
		scanf("%d",&k);
		if (k)
			allOne=0;
		rep(j,0,k)
		{
			int a;
			scanf("%d",&a);
			--a;
			A[i][a]=1;
		}
	}
	rep(i,0,n)
		rep(j,0,n)
		if (i!=j)
		{
			bool con =false;
			rep(k,0,m)
				if (A[i][k] && A[j][k])
					con=true;
			if (con)
				g[i].inc.push_back(j);
		}
	int res=allOne;
	rep(i,0,n)
		if (!g[i].was)
		{
			dfs(i);
			++res;
		}
	cout<<res-1<<endl;

	
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