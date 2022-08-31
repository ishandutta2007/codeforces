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

const int MaxN=1000010;

int n,m,tot;
int a[MaxN],d[MaxN];

bool cmp_a(int i,int j)
{
	return a[i]<a[j];
}

vector<int> v[MaxN];
int deg[MaxN];

void addedge(int x,int y)
{
	v[x].push_back(y);
	deg[y]++;
}

int head,tail;
int Q[MaxN];

int main()
{
	cin>>n>>m;
	tot=m;
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j)
		{
			scanf("%d",&a[j]);
			d[j]=j;
		}
		sort(d+1,d+m+1,cmp_a);
		++tot;
		for (int j=1;j<=m;++j)
		{
			if (a[d[j]]==-1) continue;
			if (a[d[j]]==a[d[j-1]]) continue;
			for (int k=j;k<=m;++k)
				if (a[d[j]]==a[d[k]]) addedge(tot,d[k]);
			++tot;
			for (int k=j;k<=m;++k)
				if (a[d[j]]==a[d[k]]) addedge(d[k],tot);
		}
	}
	head=1;
	for (int i=1;i<=tot;++i)
		if (!deg[i])
		{
			Q[++tail]=i;
		}
	while (head<=tail)
	{
		int x=Q[head++];
		for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
			if (!--deg[*it])
			{
				Q[++tail]=*it;
			}
	}
	if (tail!=tot)
	{
		puts("-1");
	}
	else
	{
		for (int i=1;i<=tot;++i)
			if (Q[i]<=m) printf("%d ",Q[i]);
	}
	return 0;
}