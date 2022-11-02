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

struct vert
{
	int next;
	int h;
	int id;
	vert()
	{
		id=-1;
	}
} g[3010];

int currId=0;
void dfs(int k)
{
	if (g[k].next!=-1 && g[g[k].next].id==-1)
		dfs(g[k].next);
	if (g[k].next==-1)
	{
		g[k].id = currId++;
		g[k].h = 0;
	}
	else
	{
		g[k].id = g[g[k].next].id;
		g[k].h = g[g[k].next].h+1;
	}
}


void run()
{
	int n,x;
	cin>>n>>x;
	--x;
	rep(i,0,n)
	{
		scanf("%d",&g[i].next);
		--g[i].next;
	}
	rep(i,0,n)
		if (g[i].id==-1)
			dfs(i);
	int Val[3002]={0};
	rep(i,0,n)
		if (g[i].id!=g[x].id)
			Val[g[i].id]=max(Val[g[i].id],g[i].h+1);
	bool Can[3010]={0};
	Can[0]=1;
	rep(i,0,n)
	{
		for (int j=n;j>=0;j--)
			if (j-Val[i]>=0)
				Can[j]|=Can[j-Val[i]];
	}
	rep(i,0,n)
		if (Can[i])
			printf("%d\n",i+g[x].h+1);
}


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
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