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

struct edge
{
	int to;
	int flow;
	int cap;
	edge(){}
	edge(int t,int f,int c)
	{
		to = t;
		flow = f;
		cap = c;
	}
} E[100100];


int ecnt=0;

struct vert
{
	vector<int> inc;
	int dist;
	int pntr;
} g[10000];

void add(int a,int b,int cap)
{
	E[ecnt]=edge(b,0,cap);
	g[a].inc.push_back(ecnt++);
	E[ecnt]=edge(a,0,0);
	g[b].inc.push_back(ecnt++);
}

int S,T;

const int INF=1e9;
bool bfs(int n)
{
	rep(i,0,n)
	{
		g[i].pntr = 0;
		g[i].dist = INF;
	}
	g[S].dist = 0;
	queue<int> q;
	q.push(S);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		rep(i,0,g[v].inc.size())
		{
			edge &e = E[g[v].inc[i]];
			if (g[e.to].dist==INF && e.flow<e.cap)
			{
				g[e.to].dist = g[v].dist + 1;
				q.push(e.to);
			}
		}
	}
	return g[T].dist!=INF;
}

int dfs(int k,int flow)
{
	if (k==S)
		return flow;
	for (int &i = g[k].pntr; i<g[k].inc.size();i++)
	{
		edge &e = E[g[k].inc[i]];
		if (e.flow<e.cap && g[k].dist+1==g[e.to].dist)
		{
			int val = dfs(e.to,min(flow,e.cap-e.flow));
			if (val)
			{
				e.flow+=val;
				E[g[k].inc[i]^1].flow-=val;
				return val;
			}
		}
	}
	return 0;
}

int dinic(int n)
{
	int flow = 0,curr;
	while (bfs(n))
		while (curr=dfs(S,INF))
			flow+=curr;
	return flow;
}

void run()
{
	char A[100];
	char B[1000];
	scanf("%s%s",A,B);
	int cntA[10]={0};
	rep(i,0,strlen(A))
	{
		char c = A[i];
		if (c=='5') c='2';
		if (c=='9') c='6';
		cntA[c-'0']++;
	}
	int cntB[10]={0};
	rep(i,0,strlen(B))
	{
		char c = B[i];
		if (c=='5') c='2';
		if (c=='9') c='6';
		cntB[c-'0']++;
	}
	int res = INF;
	rep(i,0,10)
		if (cntA[i]>cntB[i])
			res = 0;
		else if (cntA[i]!=0)
			res=min(cntB[i]/cntA[i],res);
	cout<<res<<endl;
}

#define problem "party"


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