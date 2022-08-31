#include<cstdio>
#include<iostream>
#include<bitset>

using namespace std;

const int MaxN=20010;

int n,m,p;
int x[MaxN],y[MaxN];

void init()
{
	cin>>n>>m>>p;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&x[i]);
		x[i]%=p;
	}
	for (int j=1;j<=m;++j)
	{
		scanf("%d",&y[j]);
		y[j]%=p;
	}
}

bitset<MaxN> v[MaxN/2];
int F[MaxN],G[MaxN];

void print(int x,int y)
{
	if (x==1&&y==1) return;
	if (v[x][y])
	{
		print(x-1,y);
		putchar('C');
	}
	else
	{
		print(x,y-1);
		putchar('S');
	}
}

void work()
{
	for (int j=0;j<=m+1;++j)
		F[j]=-1;
	F[1]=0;
	for (int i=1;i<=n/2+1;++i)
	{
		for (int j=1;j<=m;++j)
		{
			int c=x[i]+y[j];
			if (c>=p) c-=p;
			if (F[j]>F[j-1])
			{
				v[i][j]=1;
				F[j]+=c;
			}
			else
			{
				v[i][j]=0;
				F[j]=F[j-1]+c;
			}
		}
	}
	for (int j=0;j<=m+1;++j)
		G[j]=-1;
	G[m]=0;
	for (int i=n;i>=n/2+1;--i)
	{
		for (int j=m;j>=1;--j)
		{
			int c=x[i]+y[j];
			if (c>=p) c-=p;
			G[j]=max(G[j],G[j+1])+c;
		}
	}
	int get=1,most=-1;
	for (int i=n/2+1,j=1;j<=m;++j)
	{
		int c=x[i]+y[j];
		if (c>=p) c-=p;
		if (F[j]+G[j]-c>most)
		{
			most=F[j]+G[j]-c;
			get=j;
		}
	}
	cout<<most<<endl;
	print(n/2+1,get);
	for (int j=0;j<=m+1;++j)
		G[j]=-1;
	G[m]=0;
	int d=n/2;
	for (int i=n;i>=n/2+1;--i)
	{
		for (int j=m;j>=1;--j)
		{
			int c=x[i]+y[j];
			if (c>=p) c-=p;
			if (G[j]>G[j+1])
			{
				v[i-d][j]=1;
				G[j]+=c;
			}
			else
			{
				v[i-d][j]=0;
				G[j]=G[j+1]+c;
			}
		}
	}
	for (int i=1,j=get;i!=n-d||j!=m;)
	{
		if (v[i][j])
		{
			putchar('C');
			++i;
		}
		else
		{
			putchar('S');
			++j;
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}