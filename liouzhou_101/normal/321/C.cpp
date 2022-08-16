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
typedef pair<ll,ll> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=100010;

int n;
vector<int> v[MaxN];
char c[MaxN];

int head,tail,Q[MaxN];
int u[MaxN],size[MaxN],most[MaxN],pre[MaxN];

void solve(int root,int deep)
{
	u[Q[head=tail=1]=root]=1;
	while (head<=tail)
	{
		int x=Q[head++];
		size[x]=1;
		most[x]=0;
		for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
			if (!u[*it])
			{
				u[Q[++tail]=*it]=1;
				pre[*it]=x;
			}
	}
	for (int k=tail;k>=1;--k)
	{
		int x=Q[k];
		size[pre[x]]+=size[x];
		most[pre[x]]=max(most[pre[x]],size[x]);
		most[x]=max(most[x],tail-size[x]);
	}
	for (int k=1;k<=tail;++k)
	{
		int x=Q[k];
		if (most[root]>most[x]) root=x;
	}
	c[root]=deep+'A';
	for (int k=1;k<=tail;++k)
		u[Q[k]]=0;
	u[root]=1;
	for (vector<int>::iterator it=v[root].begin();it!=v[root].end();++it)
		if (!u[*it]) solve(*it,deep+1);
}

int main()
{
	cin>>n;
	for (int i=1;i<n;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	solve(1,0);
	for (int i=1;i<=n;++i)
		cout<<c[i]<<" ";
	return 0;
}