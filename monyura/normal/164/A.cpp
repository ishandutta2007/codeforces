#pragma comment(linker,"/STACK:128000000")
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

typedef unsigned long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
#define x first
#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

struct vert
{
	vector<int> inc;
	vector<int> back;
	int val;
	int col;
	bool can2;
	bool can1;
	vert()
	{
		col=0;
		can1=can2=0;
	}
} g[100100];

void dfs2(int k)
{
	g[k].col=1;
	g[k].can2=1;
	if (g[k].val!=1)
		rep(i,0,g[k].back.size())
			if (g[g[k].back[i]].col==0)
				dfs2(g[k].back[i]);
}

void dfs1(int k)
{
	g[k].col=1;
	g[k].can1=1;
	rep(i,0,g[k].inc.size())
		if (g[g[k].inc[i]].val!=1 && g[g[k].inc[i]].col==0)
			dfs1(g[k].inc[i]);
}

void run()
{
	 int n,m;
	 cin>>n>>m;
	 rep(i,0,n)
		 scanf("%d",&g[i].val);
	 rep(i,0,m)
	 {
		 int a,b;
		 scanf("%d%d",&a,&b);
		 --a;--b;
		 g[a].inc.push_back(b);
		 g[b].back.push_back(a);
	 }
	 rep(i,0,n)
		 if (g[i].col==0 && g[i].val==2)
			 dfs2(i);
	 rep(i,0,n)
		 g[i].col=0;
	 rep(i,0,n)
		 if (g[i].col==0 && g[i].val==1)
			 dfs1(i);
	 rep(i,0,n)
		 printf("%c\n",(g[i].can1 && g[i].can2?'1':'0'));

}

int main()
{
#ifdef _MON_JUDGE_
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	time_t beg=clock();
	run();
#ifdef _MON_JUDGE_
	puts("=================");
	printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}

/*

*/