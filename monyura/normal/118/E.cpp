#pragma comment(linker,"/STACK:64000000")
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
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

struct vert
{
	vector<int> inc;
	char was;
	int tin;
	int f;
	vert()
	{
		was=0;
	}
} *g;

int tme=0;
bool ok=1;
vector<pii> res;
void dfs(int k,int from)
{
	g[k].was=1;
	g[k].tin=++tme;
	g[k].f=1e9;
	rep(i,0,g[k].inc.size())
	{
		if (g[k].inc[i]==from) 
			continue;
		if (g[g[k].inc[i]].was==0)
		{
			dfs(g[k].inc[i],k);
			if (g[k].tin<g[g[k].inc[i]].f) ok=0;
			g[k].f=min(g[k].f,g[g[k].inc[i]].f);
			res.push_back(pii(k,g[k].inc[i]));
		}
		else if (g[g[k].inc[i]].was==1)
		{
			g[k].f=min(g[k].f,g[g[k].inc[i]].tin);
			res.push_back(pii(k,g[k].inc[i]));
		}
	}
	g[k].was=2;
}

int main()
{
	int n,m;
	cin>>n>>m;
	g=new vert[n];
	res.reserve(m+1);
	rep(i,0,m)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		g[a].inc.push_back(b);
		g[b].inc.push_back(a);
	}
	dfs(0,-1);
	if (!ok) 
		printf("0\n");
	else
		rep(i,0,m)
			printf("%d %d\n",res[i].first+1,res[i].second+1);
	return 0;
}
/*
3 2
1 2
2 3
*/