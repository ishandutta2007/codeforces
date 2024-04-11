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

struct vert
{
	vector<int> inc;
	bool was;
} g[100100];

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
	int Cnt[3]={0};
	rep(i,0,n)
	{
		if (g[i].inc.size()<=2)
			Cnt[g[i].inc.size()]++;
	}
	if (Cnt[1]==2 && Cnt[2]==n-2)
	{
		puts("bus topology");
		return;
	}
	Cnt[0]=Cnt[1]=0;
	rep(i,0,n)
	{
		if (g[i].inc.size()==1)
			Cnt[1]++;
		else
			Cnt[0]++;
	}
	if (Cnt[1]==n-1 && Cnt[0]==1)
	{
		puts("star topology");
		return;
	}
	Cnt[0] = 0;
	rep(i,0,n)
	{
		if (g[i].inc.size()==2)
			++Cnt[0];
	}
	if (Cnt[0]==n)
	{
		puts("ring topology");
		return;
	}
	puts("unknown topology");
}

int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("path.in","r",stdin);
	//freopen("path.out","w",stdout);
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