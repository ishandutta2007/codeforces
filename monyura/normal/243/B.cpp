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

vector<int> inc[200200];

void run()
{
	int n,m,h,t;
	cin>>n>>m>>h>>t;
	pii E[200200];
	rep(i,0,m)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		E[i]=pii(a,b);
		inc[a].push_back(b);
		inc[b].push_back(a);
	}
	rep(i,0,n)
		sort(all(inc[i]));
	rep(i,0,m)
		E[i+m]=pii(E[i].second,E[i].first);
	vector<int> H;
	vector<int> T;
	vector<int> B;
	H.reserve(300);
	T.reserve(300);
	B.reserve(300);
	rep(i,0,2*m)
	{
		int u=E[i].first;
		int v=E[i].second;
		if (inc[u].size()<=h || inc[v].size()<=t)
			continue;
		H.clear();
		T.clear();
		B.clear();
		int pu=0;
		int pv=0;
		while (pu<inc[u].size() && pv<inc[v].size() && H.size()<h && T.size()<t && B.size()<h+t)
		{
			if (inc[u][pu]==inc[v][pv])
			{
				B.push_back(inc[u][pu]);
				pu++;
				pv++;
			}
			else if (inc[u][pu]<inc[v][pv])
			{
				if (inc[u][pu]!=v)
					H.push_back(inc[u][pu]);
				pu++;
			}
			else
			{
				if (inc[v][pv]!=u)
					T.push_back(inc[v][pv]);
				pv++;
			}
		}
		if (B.size()<h+t)
		{
			for (;pv<inc[v].size() && T.size()<t;++pv)
					if (inc[v][pv]!=u)
						T.push_back(inc[v][pv]);
			for (;pu<inc[u].size() && H.size()<h;++pu)
					if (inc[u][pu]!=v)
						H.push_back(inc[u][pu]);
		}
		int dh=h-H.size();
		int dt=t-T.size();
		if (B.size()>=dh+dt)
		{
			rep(i,0,dh)
			{
				H.push_back(B.back());
				B.pop_back();
			}
			rep(i,0,dt)
			{
				T.push_back(B.back());
				B.pop_back();
			}
		}
		if (H.size()==h && T.size()==t)
		{
			puts("YES");
			printf("%d %d\n",u+1,v+1);
			rep(i,0,h)
				printf("%d%c",H[i]+1,(i==h-1?'\n':' '));
			rep(i,0,t)
				printf("%d%c",T[i]+1,(i==t-1?'\n':' '));
			return;
		}
	}
	puts("NO");
	return;
}


int main()
{
	srand(time(0));
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
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