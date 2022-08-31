#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=310;
const int INF=1000000000;

int n,m,ans;
int d[9][MaxN][MaxN];
int v[MaxN][MaxN],w[MaxN][MaxN];

void calc(int v[MaxN][MaxN],int a[MaxN][MaxN],int b[MaxN][MaxN])
{
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
		{
			v[i][j]=INF;
			for (int k=1;k<=n;++k)
				v[i][j]=min(v[i][j],a[i][k]+b[k][j]);
		}
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			if (i!=j) d[0][i][j]=v[i][j]=INF;
	for (int i=1;i<=m;++i)
	{
		int x,y,s,t;
		scanf("%d%d%d%d",&x,&y,&s,&t);
		d[0][x][y]=-s;
		d[0][y][x]=-t;
	}
	for (int k=1;k<=8;++k)
		calc(d[k],d[k-1],d[k-1]);
	for (int k=8;k>=0;--k)
	{
		calc(w,v,d[k]);
		int flag=0;
		for (int i=1;i<=n;++i)
			if (w[i][i]<0) flag=1;
		if (!flag)
		{
			ans+=1<<k;
			for (int i=1;i<=n;++i)
				for (int j=1;j<=n;++j)
					v[i][j]=w[i][j];
		}
	}
	cout<<((ans>=n)?0:ans+1)<<endl;
	return 0;
}