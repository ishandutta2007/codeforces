#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=5010;
const int INF=1000000000;

int n;
int h[MaxN];
int F[MaxN][MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&h[i]);
		h[i]+=h[i-1];
	}
}

void work()
{
	for (int i=1;i<=n;++i)
		F[i][1]=i-1;
	for (int i=2;i<=n;++i)
	{
		int k=1;
		for (int j=2;j<=i;++j)
		{
			while (k<j)
			{
				if (h[i]-h[j-1]>=h[j-1]-h[k-1]) break;
				++k;
			}
			if (k==j)
			{
				for (int _j=j;_j<=i;++_j)
					F[i][_j]=INF;
				break;
			}
			F[i][j]=F[j-1][k]+i-j;
		}
		for (int j=i-1;j>=1;--j)
			F[i][j]=min(F[i][j],F[i][j+1]);
	}
	int ans=INF;
	for (int j=1;j<=n;++j)
		ans=min(ans,F[n][j]);
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}