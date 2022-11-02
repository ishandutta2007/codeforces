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

struct elem
{
	int x;
	int from;
	int t;
	int nom;
	elem(int a,int b,int c,int d)
	{
		x=a;
		from=b;
		t=c;
		nom=d;
	}
	elem(){}
};

bool operator<(const elem &a,const elem &b)
{
	if (a.x!=b.x)
		return a.x<b.x;
	return a.from<b.from;
}

struct vert
{
	vector<int> inc;
	vector<int> w;
	vector<int> tramp;
	int dist;
	bool close;
	int from;
	int tr;
	vert()
	{
		close=false;
		dist=1e9+10;
		tr=0;
	}

} g[200100];

void Dejkstra(int st)
{
	priority_queue<pii> q;
	q.push(pii(0,st));
	g[st].dist=0;
	while (!q.empty())
	{
		int d=-q.top().first;
		int v=q.top().second;
		q.pop();
		if (g[v].close) continue;
		g[v].close=true;
		rep(i,0,g[v].inc.size())
			if (g[g[v].inc[i]].dist>d+g[v].w[i])
			{
				g[g[v].inc[i]].dist=d+g[v].w[i];
				g[g[v].inc[i]].from=v;
				g[g[v].inc[i]].tr=g[v].tramp[i];
				q.push(pii(-g[g[v].inc[i]].dist,g[v].inc[i]));
			}
	}
}

int main()
{
	int n,L;
	cin>>n>>L;
	elem A[200100];
	rep(i,0,n)
	{
		int x,d,t,p;
		scanf("%d%d%d%d",&x,&d,&t,&p);
		A[2*i]=elem(x+d,x-p,p+t,i+1);
		A[2*i+1]=elem(x-p,-1,-1,-1);
	}
	A[2*n]=elem(0,-100,-1,-1);
	A[2*n+1]=elem(L,-1,-1,-1);
	n+=1;
	sort(A,A+2*n);
	map<int,int> mp;
	int pr=-1;
	rep(i,0,2*n)
		if (A[i].x>=0)
		{
			if (mp.find(A[i].x)==mp.end())
				mp[A[i].x]=mp.size();
			if (pr!=-1)
				if (pr!=A[i].x)
				{
					int a=mp[pr],b=mp[A[i].x];
					g[a].inc.push_back(b);
					g[a].tramp.push_back(0);
					g[a].w.push_back(A[i].x-pr);
					g[b].inc.push_back(a);
					g[b].tramp.push_back(0);
					g[b].w.push_back(A[i].x-pr);
				}
			if (A[i].from>=0)
			{
				int a=mp[A[i].from],b=mp[A[i].x];
				g[a].inc.push_back(b);
				g[a].tramp.push_back(A[i].nom);
				g[a].w.push_back(A[i].t);
			}
			pr=A[i].x;
		}
	Dejkstra(mp[0]);
	vector<int> res;
	int curr=mp[L];
	while (curr!=mp[0])
	{
		if (g[curr].tr)
			res.push_back(g[curr].tr);
		curr=g[curr].from;
	}
	printf("%d\n",g[mp[L]].dist);
	printf("%d\n",res.size());
	for (int i=res.size()-1;i>=0;i--)
		printf("%d\n",res[i]);
	return 0;
} 

/*
2 0
4 6 1 1
2 2 1 2

2 10
6 4 1 1
2 4 1 2

1 10
1 10 2 2
*/