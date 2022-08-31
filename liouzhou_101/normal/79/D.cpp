#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;

const int MaxK=20;
const int MaxN=10010;
const int INF=1000000000;

int n,k,m;
int u[MaxN];
vector<int> v;
int a[MaxN];

void init()
{
	cin>>n>>k>>m;
	for (int i=1;i<=k;++i)
	{
		int x;
		cin>>x;
		u[x]^=1;
		u[--x]^=1;
	}
	for (int i=0;i<=n;++i)
		if (u[i]) v.push_back(i);
	k=v.size();
	for (int i=1;i<=m;++i)
		cin>>a[i];
}

int d[MaxK][MaxN];
int head,tail,Q[MaxN];

void build(int d[MaxN],int S)
{
	for (int i=0;i<=n;++i)
	{
		u[i]=0;
		d[i]=INF;
	}
	d[S]=0;
	u[Q[head=tail=1]=S]=1;
	while (head<=tail)
	{
		int x=Q[head++];
		for (int i=1;i<=m;++i)
		{
			int y=x+a[i];
			if (y<=n) if (!u[y])
			{
				u[Q[++tail]=y]=1;
				d[y]=d[x]+1;
			}
			y=x-a[i];
			if (y>=0) if (!u[y])
			{
				u[Q[++tail]=y]=1;
				d[y]=d[x]+1;
			}
		}
	}
}

int F[1<<MaxK];

int solve(int s)
{
	if (F[s]!=-1) return F[s];
	F[s]=INF;
	for (int i=0;i<k;++i) if (s&(1<<i))
	{
		for (int j=i+1;j<k;++j) if (s&(1<<j))
			F[s]=min(F[s],solve(s^(1<<i)^(1<<j))+d[i][v[j]]);
		break;
	}
	return F[s];
}

void work()
{
	for (int i=0;i<k;++i)
		build(d[i],v[i]);
	for (int i=1;i<(1<<k);++i)
		F[i]=-1;
	int ans=solve((1<<k)-1);
	if (ans==INF) ans=-1;
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}