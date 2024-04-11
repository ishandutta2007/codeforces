#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

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
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


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

const double PI=acos(-1.0);

struct vert
{
	vector<int> inc;
	int was;
	vert()
	{
		was=0;
	}
} g[300100];

int ts[100100];
int tcnt=0;
bool cic=false;
int m;
void dfs(int k)
{
	g[k].was = 1;
	rep(i,0,g[k].inc.size())
	{
		int to=g[k].inc[i];
		if (g[to].was == 1)
			cic=true;
		if (g[to].was == 0)
			dfs(to);
	}
	g[k].was=2;
	if (k<m)
		ts[tcnt++]=k;
}


void run()
{
	int n;
	cin>>n>>m;
	pii A[100100];
	int last=m;
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			scanf("%d",&A[j].first);
			A[j].second = j;
		}
		sort(A,A+m);
		int pr=-1;
		int j=0;
		while (j<m && A[j].first==-1)
			++j;
		for (;j<m;)
		{
			int st=j;
			while (j<m && A[j].first==A[st].first)
				++j;
			if (pr!=-1)
					rep(k,st,j)
						g[pr].inc.push_back(A[k].second);
			if (j<m)
			{
				rep(k,st,j)
					g[A[k].second].inc.push_back(last);
				pr=last;
				last++;
			}
			
		}
	}
	cic=false;
	rep(i,0,last)
		if (!g[i].was)
			dfs(i);
	if (cic)
	{
		puts("-1");
	}
	else
	{
		reverse(ts,ts+m);
		/*int r[100100];
		rep(i,0,m)
			r[ts[i]]=i;*/
		rep(i,0,m)
			printf("%d ",ts[i]+1);
		puts("");
	}

}



int main()
{
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