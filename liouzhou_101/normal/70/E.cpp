#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=210;

int n,k;
int d[MaxN];
int v[MaxN][MaxN];

void init()
{
	cin>>n>>k;
	for (int i=1;i<n;++i)
		cin>>d[i];
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=n;++j)
			v[i][j]=MaxN;
		v[i][i]=0;
	}
	for (int i=1;i<n;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x][y]=v[y][x]=1;
	}
	for (int k=1;k<=n;++k)
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
				v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
}

int F[MaxN][MaxN];
int c[MaxN];

void solve(int x,int p)
{
	for (int i=1;i<=n;++i)
		F[x][i]=d[v[x][i]]+k;
	for (int i=1;i<=n;++i)
		if (v[x][i]==1&&i!=p)
		{
			solve(i,x);
			for (int j=1;j<=n;++j)
				F[x][j]+=min(F[i][j]-k,F[i][c[i]]);
		}
	c[x]=1;
	for (int i=1;i<=n;++i)
		if (F[x][c[x]]>F[x][i]) c[x]=i;
}

int ans[MaxN];

void get(int x,int p,int cx)
{
	ans[x]=cx;
	for (int i=1;i<=n;++i)
		if (v[x][i]==1&&i!=p)
			get(i,x,(F[i][cx]-k<F[i][c[i]])?cx:c[i]);
}

void work()
{
	solve(1,0);
	cout<<F[1][c[1]]<<endl;
	get(1,0,c[1]);
	for (int i=1;i<=n;++i)
		cout<<ans[i]<<" ";
}

int main()
{
	init();
	work();
	return 0;
}