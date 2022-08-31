#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

const int MaxN=25;
const int MaxT=MaxN*MaxN;

int n,m,a,b;
vector<int> v[MaxN];
long double p[MaxN];

int T;
long double A[MaxT][MaxT];

int place(int x,int y)
{
	return (x-1)*n+y;
}

long double getabs(long double x)
{
	return (x>=0)?x:-x;
}

void init()
{
	cin>>n>>m>>a>>b;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1;i<=n;++i)
		cin>>p[i];
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
		{
			if (i==j)
			{
				A[place(i,j)][place(i,j)]=-1;
				continue;
			}
			for (vector<int>::iterator x=v[i].begin();x!=v[i].end();++x)
				A[place(*x,j)][place(i,j)]=(1-p[i])*p[j]/v[i].size();
			for (vector<int>::iterator y=v[j].begin();y!=v[j].end();++y)
				A[place(i,*y)][place(i,j)]=(1-p[j])*p[i]/v[j].size();
			for (vector<int>::iterator x=v[i].begin();x!=v[i].end();++x)
				for (vector<int>::iterator y=v[j].begin();y!=v[j].end();++y)
					A[place(*x,*y)][place(i,j)]=(1-p[i])*(1-p[j])/v[i].size()/v[j].size();
			A[place(i,j)][place(i,j)]=p[i]*p[j]-1;
		}
	T=n*n;
	for (int i=1;i<=T;++i)
		A[place(a,b)][i]=0;
	A[place(a,b)][T+1]=1;
	for (int i=1;i<=n;++i)
		A[place(a,b)][place(i,i)]=1;
}

void work()
{
	for (int i=1;i<=T;++i)
	{
		int p=i;
		for (int j=i+1;j<=T;++j)
			if (getabs(A[p][i])<getabs(A[j][i])) p=j;
		for (int k=i;k<=T+1;++k)
			swap(A[p][k],A[i][k]);
		for (int k=T+1;k>=i;--k)
			A[i][k]/=A[i][i];
		for (int j=1;j<=T;++j) if (i!=j)
			for (int k=T+1;k>=i;--k)
				A[j][k]-=A[j][i]*A[i][k];
	}
	for (int i=1;i<=n;++i)
		printf("%.10lf ",(double)A[place(i,i)][T+1]);
}

int main()
{
	init();
	work();
	return 0;
}