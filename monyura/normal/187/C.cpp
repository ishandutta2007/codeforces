//#pragma comment(linker,"/STACK:128000000")
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
//#define x first
//#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

int pred[200200];
int n,m;
vector<int> g[200200];
int dist[200200];
bool theChosenOne[200200]={0};
bool was[200200];

int getPred(int a)
{
	if (pred[a]!=a)
		pred[a]=getPred(pred[a]);
	return pred[a];
}

bool can(int dst,int s,int t)
{
	rep(i,0,n)
		pred[i]=i;
	queue<int> q;
	rep(i,0,n)
		if (theChosenOne[i])
		{
			dist[i]=0;
			q.push(i);
			was[i]=1;
		}
		else
		{
			dist[i]=1e6;
			was[i]=0;
		}
	int pv,pi;
	while (!q.empty())
	{
		int v=q.front();
		q.pop();
		if (dist[v]>=dst) continue;
		rep(i,0,g[v].size())
		{
			if (!was[g[v][i]])
			{
				dist[g[v][i]]=dist[v]+1;
				was[g[v][i]]=1;
				q.push(g[v][i]);
				pv=getPred(v);
				pi=getPred(g[v][i]);
				pred[pi]=pv;
			}
			else
			{
				if (dist[g[v][i]]+dist[v]+1<=dst)
				{
					pv=getPred(v);
					pi=getPred(g[v][i]);
					pred[pi]=pv;
				}
			}
		}
	}
	return getPred(s)==getPred(t);

}

void run()
{
	int k;
	cin>>n>>m>>k;
	rep(i,0,k)
	{
		int a;
		scanf("%d",&a);
		--a;
		theChosenOne[a]=1;
	}
	rep(i,0,m)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int s,t;
	scanf("%d%d",&s,&t);
	--s;--t;
	theChosenOne[t]=1;
	int l=0,r=n+2;
	int res=n+2;
	while(l<=r)
	{
		int c=(l+r)>>1;
		if (can(c,s,t))
		{
			res=c;
			r=c-1;
		}
		else
			l=c+1;
	}
	if (res==n+2)
		cout<<-1<<endl;
	else
		cout<<res<<endl;
	/*if (m==1000)
	{
		printf("%d %d\n",s+1,t+1);
		rep(j,0,n)
			if (theChosenOne[j])
				rep(i,0,g[j].size())
				if (theChosenOne[g[j][i]] || g[j][i]==t || g[j][i]==s)
					printf("%d %d\n",j+1,g[j][i]+1);
	}*/
}

int main()
{

#ifdef _MON_JUDGE_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
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