#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=500010;

int n;
int a[MaxN],b[MaxN];
int lg[MaxN],pow[MaxN];

int v[MaxN][20];

int v_max(int x,int y)
{
	return (b[x]<b[y])?x:y;
}

int F[MaxN][20];

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		a[n+i]=a[i];
	}
	for (int i=1;i<=n*2;++i)
		b[i]=i-a[i];
	for (int i=2;i<=n*2;++i)
		lg[i]=lg[i>>1]+1;
	for (int i=pow[0]=1;i<=20;++i)
		pow[i]=pow[i-1]<<1;
	for (int i=1;i<=n*2;++i)
		v[i][0]=i;
	for (int k=1;k<20;++k)
		for (int i=1;i<=n*2;++i)
		{
			v[i][k]=v[i][k-1];
			if (i+pow[k-1]<=n*2)
				v[i][k]=v_max(v[i][k],v[i+pow[k-1]][k-1]);
		}
	for (int i=2;i<=n*2;++i)
	{
		int x=max(b[i],1),y=i-1;
		int k=lg[y-x+1];
		F[i][0]=v_max(v[x][k],v[y-pow[k]+1][k]);
	}
	for (int k=1;k<20;++k)
		for (int i=1;i<=n*2;++i)
			F[i][k]=F[F[i][k-1]][k-1];
}

void work()
{
	long long ans=0;
	for (int i=n;i<2*n;++i)
	{
		if (b[i]<=i-n+1)
		{
			++ans;
			continue;
		}
		int x=i;
		for (int k=19;k>=0;--k)
			if (b[F[x][k]]>i-n+1)
			{
				ans+=pow[k];
				x=F[x][k];
			}
		ans+=2;
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}