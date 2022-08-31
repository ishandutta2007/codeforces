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

const int MaxN=3010;

int n;
int x[MaxN],y[MaxN];
bitset<MaxN> u[MaxN];

int tot;
struct node
{
	int x,y;
	ld d;
	bool operator < (node A) const
	{
		return d>A.d;
	}
}p[MaxN*MaxN/2];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j)
		{
			ld d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))/2;
			p[++tot]=(node){i,j,d};
		}
	sort(p+1,p+tot+1);
	for (int i=1;i<=tot;++i)
	{
		u[p[i].x][p[i].y]=u[p[i].y][p[i].x]=1;
		if ((u[p[i].x]&u[p[i].y]).any())
		{
			printf("%.20lf\n",p[i].d);
			break;
		}
	}
	return 0;
}