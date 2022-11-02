#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

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
typedef pair<short,short> pss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

struct vert
{
	vector<int> inc;
	vector<int> cnt;
	bool was;
	void init()
	{
		was=0;
		cnt.clear();
	}
	vert()
	{
		init();
	}
} g[5001];

int n;
int dfs(int k)
{
	g[k].was=true;
	int cnt=0;
	rep(i,0,g[k].inc.size())
		if (!g[g[k].inc[i]].was)
		{
			g[k].cnt.push_back(dfs(g[k].inc[i]));
			cnt+=g[k].cnt.back();
		}
	if (n-1-cnt!=0)
		g[k].cnt.push_back(n-cnt-1);
	return cnt+1;
}


void run()
{
	cin>>n;
	rep(i,0,n-1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].inc.push_back(b);
		g[b].inc.push_back(a);
	}
	bool Can[5001]={0};
	dfs(0);
	rep(i,0,n)
		if (g[i].inc.size()!=1)
		{
			bool D[5001]={1};
			rep(j,0,g[i].cnt.size())
			{
				int add=g[i].cnt[j];
				for (int p=n-add-1;p>=0;p--)
					D[p+add]|=D[p];
			}
			rep(p,0,n)
				Can[p]|=D[p];
		}
	int res=0;
	rep(i,1,n-1)
		if (Can[i])
			++res;
	printf("%d\n",res);
	rep(i,1,n-1)
		if (Can[i])
			printf("%d %d\n",i,n-1-i);
}

int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t beg=clock();
#endif
	run();
#ifdef _MONYURA_
	printf("================\n");
	printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}

/*

*/