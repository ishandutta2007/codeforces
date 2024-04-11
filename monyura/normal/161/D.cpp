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
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
//#define x first
//#define y second

const double PI=acos(-1.0);

struct vert
{
	vector<int> inc;
	bool was;
	ll D[501];
	vert()
	{
		was=false;
		memset(D,0,sizeof(D));
	}
	
} g[50001];
int K;
ll res=0;

void dfs(int k,int pr)
{
	g[k].D[0]=1;
	g[k].was=true;
	rep(i,0,g[k].inc.size())
		if (!g[g[k].inc[i]].was)
		{
			dfs(g[k].inc[i],k);
			rep(j,1,K+1)
				g[k].D[j]+=g[g[k].inc[i]].D[j-1];
		}
	res+=2*g[k].D[K];
	rep(i,0,g[k].inc.size())
		if (g[k].inc[i]!=pr)
		{
			rep(j,1,K)
				res+=g[g[k].inc[i]].D[j-1]*(g[k].D[K-j]-g[g[k].inc[i]].D[K-j-1]);
		}
}


int main()
{
	int n;
	cin>>n>>K;
	rep(i,0,n-1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].inc.push_back(b);
		g[b].inc.push_back(a);
	}
	dfs(0,-1);
	cout<<res/2<<endl;
	return 0;
} 

/*
5 2
1 2
1 3
1 4
1 5

*/