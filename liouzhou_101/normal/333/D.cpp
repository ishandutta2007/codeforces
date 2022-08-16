#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=1010;

int n,m;
int a[MaxN][MaxN];

int tot;
struct node
{
	int x,y,d;
	bool operator < (node A) const
	{
		return d<A.d;
	}
}p[MaxN*MaxN];

bitset<MaxN> u[MaxN];

bool check(int ans)
{
	for (int i=1;i<=n;++i)
	{
		u[i].reset();
		for (int j=1;j<=m;++j)
			if (a[i][j]>=ans) u[i][j]=1;
	}
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j)
			if ((u[i]&u[j]).count()>=2) return true;
	return false;
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			int x;
			scanf("%d",&x);
			p[++tot]=(node){i,j,x};
		}
	sort(p+1,p+tot+1);
	for (int i=1;i<=tot;++i)
		a[p[i].x][p[i].y]=i;
	int L=1,R=tot;
	int ans=L;
	while (L<=R)
	{
		int m=(L+R)>>1;
		if (check(m))
		{
			ans=m;
			L=m+1;
		}
		else
			R=m-1;
	}
	cout<<p[ans].d<<endl;
	return 0;
}