#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxP=10000010;

int u[MaxP],p[MaxP];
int n,m;

int main()
{
	for (int i=2;i<=10000000;++i)
	{
		if (!u[i])
		{
			p[i]=i;
			for (int j=i+i;j<=10000000;j+=i)
			{
				if (u[j]) continue;
				u[j]=1;
				p[j]=i;
			}
		}
	}
	memset(u,0,sizeof(u));
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		while (x>1)
		{
			u[p[x]]++;
			int t=p[x];
			while (x%t==0) x/=t;
		}
	}
	for (int i=1;i<=10000000;++i)
		u[i]+=u[i-1];
	cin>>m;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		y=min(y,10000000);
		if (x>y)
			puts("0");
		else
			printf("%d\n",u[y]-u[x-1]);
	}
	return 0;
}