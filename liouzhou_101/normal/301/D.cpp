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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=200010;

int n,m;
int a[MaxN],p[MaxN];
vector<int> w[MaxN];
vector<pii> v[MaxN];
int ans[MaxN];
int u[MaxN];

void add(int x,int p)
{
	for (;x<MaxN;x+=x&-x)
		u[x]+=p;
}

int get(int x)
{
	int p=0;
	for (;x;x-=x&-x)
		p+=u[x];
	return p;
}

int get(int x,int y)
{
	return get(y)-get(x-1);
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		p[a[i]]=i;
	}
	for (int i=1;i<=n;++i)
		for (int j=i;j<=n;j+=i)
		{
			int x=p[i],y=p[j];
			if (x>y) swap(x,y);
			w[y].push_back(x);
		}
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[y].push_back(pii(x,i));
	}
	for (int i=1;i<=n;++i)
	{
		for (int j=0;j<w[i].size();++j)
			add(w[i][j],1);
		for (int j=0;j<v[i].size();++j)
			ans[v[i][j].Y]=get(v[i][j].X,i);
	}
	for (int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}