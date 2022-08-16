#include<cstdio>
#include<iostream>

using namespace std;

int N,M;
int v[21][21],w[21][21],p[1<<20];
unsigned long long F[21][1<<19];
unsigned long long ans;

void init()
{
	cin>>N>>M;
	for (int i=1;i<=M;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x][++v[x][0]]=y;
		v[y][++v[y][0]]=x;
		w[x][y]=w[y][x]=1;
	}
	for (int i=0;i<(1<<N);++i)
		for (int j=0;j<N;++j)
			if (i&(1<<j)) ++p[i];
}

void work()
{
	for (int i=N;i>=3;--i)
	{
		F[i][0]=1;
		for (int s=0;s<(1<<(i-1));++s)
			for (int k=1;k<=i;++k)
			{
				if (!F[k][s]) continue;
				unsigned long long tmp=F[k][s];
				F[k][s]=0;
				if (p[s]>=2&&w[i][k]) ans+=tmp;
				for (int u=1;u<=v[k][0];++u)
				{
					int x=v[k][u];
					if (x>=i) continue;
					if (s&(1<<(x-1))) continue;
					F[x][s|(1<<(x-1))]+=tmp;
				}
			}
	}
	cout<<ans/2<<endl;
}

int main()
{
	init();
	work();
	return 0;
}