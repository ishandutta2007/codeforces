#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <cstdio>
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
#include <cmath>
#include <queue>
#include <ctime>


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
typedef pair<ll,int> pli;

const double PI=acos(-1.0);

struct edge
{
	int a,b;
	int cost;
	int flow;
	int cap;
};


const int INF=1e9;

struct vert
{
	//vector<int> inc;
	int dist;
	int from;
} g[100100];

vector<edge> E;

void connect(int a,int b,int cap,int cost)
{
	edge e;
	e.a=a;
	e.b=b;
	e.cap=cap;
	e.cost=cost;
	e.flow=0;
	//g[a].inc.push_back(2*E.size());
	edge e2;
	e2.a=b;
	e2.b=a;
	e2.cost=-cost;
	e2.cap=0;
	e2.flow=0;
	//g[b].inc.push_back(2*E.size()+1);
	E.push_back(e);
	E.push_back(e2);
}

void bellman(int s,int n)
{
	rep(i,0,n)
		g[i].dist=INF;
	g[s].dist=0;
	rep(i,0,n)
	{
		bool was=0;
		rep(i,0,E.size())
		{
			edge e=E[i];
			if (e.flow!=e.cap && g[e.a].dist + e.cost < g[e.b].dist)
			{
				g[e.b].dist=g[e.a].dist + e.cost;
				g[e.b].from=i;
				was=1;
			}
		}
		if (!was)
			break;
	}
}


vector<int> vec;
void goFlow(int s,int t)
{
	vec.clear();
	int v=t;
	int val=INF;
	while (v!=s)
	{
		int e=g[v].from;
		vec.push_back(e);
		val=min(val,E[e].cap-E[e].flow);
		v=E[e].a;
	}
	rep(i,0,vec.size())
	{
		int e=vec[i];
		E[e].flow+=val;
		E[e^1].flow-=val;
	}
}

void MKMF(int s,int t,int n)
{
	while (1)
	{
		bellman(s,n);
		if (g[t].dist==INF) break;
		goFlow(s,t);
	}
}

int buildGraph(char str[101],char A[101][101],int Cnt[101],int n,int &S,int &T)
{
	S=0;
	T=1;
	int l=strlen(str);
	sort(str,str+l);
	int cnt=2;
	int V[101];
	int M[101][101];
	rep(i,0,l)
		V[i]=cnt++;
	int G[101];
	rep(i,0,n)
	{
		l=strlen(A[i]);
		sort(A[i],A[i]+l);
		rep(j,0,l)
			M[i][j]=cnt++;
	}
	rep(i,0,n)
		G[i]=cnt++;
	int ls=strlen(str);
	rep(i,0,ls)
		connect(V[i],T,1,0);
	rep(i,0,n)
	{
		l=strlen(A[i]);
		for (int j=0,pos=0;j<l && pos<ls;)
		{
			if (str[pos]>A[i][j]) 
				++j;
			else if (str[pos]<A[i][j]) 
				++pos;
			else
			{
				for (int h=pos;str[h]==A[i][j];h++)
					connect(M[i][j],V[h],1,i+1);
				++j;
				++pos;
			}
		}
		rep(j,0,l)
			connect(G[i],M[i][j],1,0);
		connect(S,G[i],Cnt[i],0);
	}	
	return cnt;
}

void run()
{
	char str[101];
	scanf("%s",str);
	char A[101][101];
	int Cnt[101];
	int n;
	cin>>n;
	rep(i,0,n)
		scanf("%s%d\n",A[i],Cnt+i);
	int S,T;
	int vert=buildGraph(str,A,Cnt,n,S,T);
	MKMF(S,T,vert);
	/*rep(i,0,E.size())
	{
		fprintf(stderr,"%d->%d cap=%d cost=%d f=%d\n",E[i].a,E[i].b,E[i].cap,E[i].cost,E[i].flow);
	}*/
	bool ok=1;
	int sum=0;
	rep(i,0,E.size())
	{
		if (E[i].b==T && E[i].flow!=E[i].cap)
			ok=0;
		sum+=E[i].flow*E[i].cost;
	}
	sum>>=1;
	if (!ok)
		sum=-1;
	printf("%d\n",sum);

}


int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
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