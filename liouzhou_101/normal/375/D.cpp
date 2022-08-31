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

const int MaxN=100010;

int n,m;
int c[MaxN];
vector<int> v[MaxN],son[MaxN];
vector<pii> w[MaxN];
int size[MaxN],to[MaxN];
map<int,int> H[MaxN];
int ans[MaxN];
map<int,int> a[MaxN];

bool cmp(int i,int j)
{
	return size[i]>size[j];
}

void add(int k,int x,int p)
{
	x=n-x;
	for (;x<MaxN;x+=x&-x)
		a[k][x]+=p;
}

int get(int k,int x)
{
	x=n-x;
	int p=0;
	for (;x;x-=x&-x)
		p+=a[k][x];
	return p;
}

void DFS(int x,int p)
{
	size[x]=1;
	for (auto y : v[x])
		if (y!=p)
		{
			son[x].push_back(y);
			DFS(y,x);
			size[x]+=size[y];
		}
	if (son[x].empty())
	{
		to[x]=x;
		H[x][c[x]]=1;
		add(x,1,1);
	}
	else
	{
	sort(son[x].begin(),son[x].end(),cmp);
	to[x]=to[son[x][0]];
	for (int i=1;i<son[x].size();++i)
	{
		for (auto p : H[to[son[x][i]]])
		{
			add(to[x],H[to[x]][p.X],-1);
			H[to[x]][p.X]+=p.Y;
			add(to[x],H[to[x]][p.X],1);
		}
	}
	add(to[x],H[to[x]][c[x]],-1);
	H[to[x]][c[x]]++;
	add(to[x],H[to[x]][c[x]],1);
	}
	//printf("%d\n",x);
	//for (auto p : H[to[x]]) printf("%d %d\n",p.X,p.Y);
	//for (int i=0;i<=n;++i)
	//	printf("%d ",get(to[x],i));puts("");
	for (auto p : w[x])
	{
		ans[p.Y]=get(to[x],p.X);
	}
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		scanf("%d",&c[i]);
	for (int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		w[x].push_back(pii(y,i));
	}
	DFS(1,0);
	for (int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}