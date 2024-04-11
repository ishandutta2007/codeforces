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
#include <iomanip>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}


int *g;
int *d;
int *to;
int *in;

int dfs(int k)
{
	if (g[k]==-1) return 1e9;
	int nxt=dfs(g[k]);
	to[k]=to[g[k]];
	return min(d[k],dfs(g[k]));
}

int main()
{
	int n,m,h;
	cin>>n>>m>>h;
	int s=0;
	int k;
	rep(i,0,m)
	{
		int si;
		scanf("%d",&si);
		s+=si;
		if (i==h-1) k=si;
	}
	s--;
	k--;
	n--;
	if (s<n) 
	{
		printf("-1.0\n");
		return 0;
	}
	if (s-k<n)
	{
		printf("1.0\n");
		return 0;
	}
	int sa=(s-n+1),fa=s;
	int sb=sa-k,fb=fa-k;
	if (sa<=fb)
	{
		int tmp=sa;
		sa=fb+1;
		fb=tmp-1;
	}
	double res=1.0;
	while (sa<=fa)
	{
		res*=double(sb)/double(sa);
		sa++;
		sb++;
	}
	printf("%.7lf\n",1-res);
	return 0;
}

/*
1000000 2000000
1000000 2000000

0 2
1 0
*/