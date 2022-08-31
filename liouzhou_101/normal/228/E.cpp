#include<cstdio>
#include<iostream>
#include<bitset>

using namespace std;

const int MaxN=110;
const int MaxM=5010;

int n,m;

bitset<MaxN> A[MaxM];

int x[MaxM],y[MaxM],c[MaxM];

int u[MaxN];

void init()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		cin>>x[i]>>y[i]>>c[i];
		A[i][x[i]]=A[i][y[i]]=1;
		A[i][0]=c[i]^1;
	}
}

void work()
{
	int now=0;
	for (int i=1;i<=n;++i)
	{
		int flag=0;
		for (int j=now+1;j<=m;++j)
			if (A[j][i])
			{
				++now;
				if (now!=j)
					swap(A[now],A[j]);
				flag=1;
				break;
			}
		if (!flag) continue;
		for (int j=1;j<=m;++j)
			if (now!=j&&A[j][i])
				A[j]^=A[now];
	}
	for (int i=1;i<=m;++i)
	{
		int flag=0;
		for (int j=1;j<=n;++j)
			if (A[i][j]) flag=1;
		if (flag) continue;
		if (A[i][0])
		{
			puts("Impossible");
			return;
		}
	}
	for (int i=1;i<=m;++i)
	{
		if (!A[i][0]) continue;
		for (int j=1;j<=n;++j)
			if (A[i][j])
			{
				u[j]=1;
				break;
			}
	}
	int num=0;
	for (int i=1;i<=n;++i)
		num+=u[i];
	cout<<num<<endl;
	num=0;
	for (int i=1;i<=n;++i)
	{
		if (u[i])
		{
			if (num) putchar(' ');
			printf("%d",i);
			++num;
		}
	}
	if (num) puts("");
}

int main()
{
	init();
	work();
	return 0;
}