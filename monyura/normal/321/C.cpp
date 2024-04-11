#pragma comment(linker,"/STACK:650000000")
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
	vector<int> inc;
	int h;
	int was;
	int from;
	bool close;
	vert()
	{
		close = false;
		was =  0;
	}
} g[100100];

int currIter=1;
int bfs(int st)
{
	++currIter;
	queue<int> q;
	g[st].h = 0;
	g[st].from  = -1;
	g[st].was = currIter;
	q.push(st);
	int mx = st;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		if (g[v].h>g[mx].h)
			mx = v;
		rep(i,0,g[v].inc.size())
		{
			int to = g[v].inc[i];
			if (!g[to].close && g[to].was<currIter)
			{
				g[to].h = g[v].h + 1;
				g[to].from = v;
				g[to].was = currIter;
				q.push(to);
			}
		}
	}
	return mx;
}

int getCentr(int In)
{
	int st = bfs(In);
	int f  = bfs(st);
	vector<int> res;
	int pos = f;
	while (pos!=-1)
	{
		res.push_back(pos);
		pos = g[pos].from;
	}
	return res[res.size()/2];
}

char Ans[100100];
void rec(int st,char c)
{
	Ans[st]=c;
	g[st].close = true;
	rep(i,0,g[st].inc.size())
	{
		int to = g[st].inc[i];
		if (!g[to].close)
		{
			int cen = getCentr(to);
			rec(cen,c+1);
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
	int c = getCentr(0);
	//cerr<<c<<endl;
	rec(c,'A');
	rep(i,0,n)
		printf("%c ",Ans[i]);
	puts("");
}

#define problem "proddiff"


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(problem".in","r",stdin);
	//freopen(problem".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}