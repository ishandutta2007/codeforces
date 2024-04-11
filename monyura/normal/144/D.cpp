#pragma comment(linker,"/STACK:62000000")
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
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

struct vert
{
	vector<int> inc;
	vector<int> w;
	bool close;
	int dist;
	vert()
	{
		dist=1e9+1;
		close=0;
	}
} g[100001];

void Dejkstra(int s)
{
	priority_queue<pii> q;
	q.push(pii(0,s));
	g[s].dist=0;
	while (!q.empty())
	{
		int v=q.top().second;
		int d=-q.top().first;
		q.pop();
		if (g[v].close) continue;
		g[v].close=1;
		rep(i,0,g[v].inc.size())
			if (g[g[v].inc[i]].dist>d+g[v].w[i])
			{
				g[g[v].inc[i]].dist=d+g[v].w[i];
				q.push(pii(-g[g[v].inc[i]].dist,g[v].inc[i]));
			}
	}
}

int main()
{
	int n,m,s;
	cin>>n>>m>>s;
	--s;
	pii E[100001];
	int W[100001];
	rep(i,0,m)
	{
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		--a;--b;
		g[a].inc.push_back(b);
		g[a].w.push_back(w);
		g[b].inc.push_back(a);
		g[b].w.push_back(w);
		E[i]=pii(a,b);
		W[i]=w;
	}
	int l;
	cin>>l;
	Dejkstra(s);
	int res=0;
	rep(i,0,n)
		res+=(g[i].dist==l);
	rep(i,0,m)
	{
		int a=E[i].first;
		int b=E[i].second;
		if (g[a].dist<l && g[a].dist+W[i]>l && (l<=g[b].dist+W[i]-(l-g[a].dist)))
			res++;
		if (g[b].dist<l && g[b].dist+W[i]>l && (l<=g[a].dist+W[i]-(l-g[b].dist)))
			res++;
		if (g[b].dist<l && g[b].dist+W[i]>l && (l==g[a].dist+W[i]-(l-g[b].dist)))
			res--;
	}
	printf("%d\n",res);
	return 0;
} 

/*
5 6 3
3 1 1
3 2 1
3 4 1
3 5 1
1 2 7
4 5 8
4

3 3 1
1 2 1
1 3 4
2 3 2
3
*/