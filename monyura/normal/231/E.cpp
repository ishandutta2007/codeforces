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
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const int INF=1e9;

struct vert
{
	vector<int> inc;
	int h;
	bool was;
	int id;
	vert()
	{
		h=0;
	}
} g[200200];


struct node
{
	vector<int> inc;
	bool was;
	int val;
	int h;
	int pr[20];
	int mn[20];
	node()
	{
		was=h=0;
	}
} T[200200];

vector<int> v;
int idCnt=0;
void dfsId(int k,int prev)
{
	g[k].was=1;
	v.push_back(k);
	rep(i,0,g[k].inc.size())
		if (g[k].inc[i]!=prev)
		{
			if (g[g[k].inc[i]].was)
			{
				if (g[g[k].inc[i]].h >=g[k].h)
					continue;
				while (1)
				{
					int last=v.back();
					g[last].id=idCnt;
					v.pop_back();
					if (last==g[k].inc[i])
						break;
				}
				T[idCnt].val=2;
				idCnt++;
			}
			else
			{
				g[g[k].inc[i]].h = g[k].h + 1;
				dfsId(g[k].inc[i],k);
			}
		}
	if (!v.empty() && v.back()==k)
	{
		T[idCnt].val=1;
		g[k].id = idCnt++;
		v.pop_back();
	}
}

void  dfsConnect(int k)
{
	g[k].was=1;
	rep(i,0,g[k].inc.size())
	{
		int to=g[k].inc[i];
		if (g[k].id!=g[to].id)
		{
			T[g[k].id].inc.push_back(g[to].id);
			T[g[to].id].inc.push_back(g[k].id);
		}
		if (!g[to].was)
			dfsConnect(to);
	}
}

const int mod=1000000007;

void dfsLca(int k,int prev)
{
	T[k].was=1;
	if (T[k].h!=0)
	{
		T[k].pr[0]=prev;
		T[k].mn[0]=T[k].val;
		rep(i,1,20)
			if ((1<<i)<=T[k].h)
			{
				int v=T[k].pr[i-1];
				T[k].pr[i]=T[v].pr[i-1];
				T[k].mn[i]=T[k].mn[i-1]*ll(T[v].mn[i-1])%mod;
			}
			else
				break;
	}
	rep(i,0,T[k].inc.size())
		if (!T[T[k].inc[i]].was)
		{
			T[T[k].inc[i]].h=T[k].h+1;
			dfsLca(T[k].inc[i],k);
		}
}

int lca(int a,int b)
{
	a=g[a].id;
	b=g[b].id;
	ll res=1;
	if (T[a].h<T[b].h)
		swap(a,b);
	int dh=T[a].h - T[b].h;
	rep(i,0,20)
		if ((dh>>i)&1)
		{
			res=(res*T[a].mn[i])%mod;
			a=T[a].pr[i];
		}
	if (a==b)
	{
		res=(res*T[a].val)%mod;
		return res;
	}
	for (int i=19;i>=0;i--)
		if (T[a].pr[i]!=T[b].pr[i])
		{
			res=(res*T[a].mn[i])%mod;
			res=(res*T[b].mn[i])%mod;
			a=T[a].pr[i];
			b=T[b].pr[i];
		}
	res=(res*T[a].mn[0])%mod;
	res=(res*T[b].mn[0])%mod;
	a=T[a].pr[0];
	b=T[b].pr[0];
	res=(res*T[a].val)%mod;
	return res;
}




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
	rep(i,0,n)
		g[i].was=0;
	idCnt=0;
	dfsId(0,-1);
	rep(i,0,n)
		g[i].was=0;
	dfsConnect(0);
	rep(i,0,n)
		T[i].was=0;
	rep(i,0,n)
	{
		sort(all(T[i].inc));
		T[i].inc.resize(unique(all(T[i].inc))-T[i].inc.begin());
	}
	dfsLca(0,-1);
	int q;
	cin>>q;
	rep(i,0,q)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		int res=lca(a,b);
		printf("%d\n",res);
	}

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