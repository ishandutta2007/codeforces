#include<cstdio>
#include<iostream>

using namespace std;

const int INF=1000000000;

int n;
int a[1010];
int F[210][1010];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int i=n;i>=1;--i)
	{
		for (int j=0;j<=1000;++j)
			F[i][j]=INF;
		if (2*i+1>n)
		{
			if (2*i<=n)
			{
				puts("-1");
				return 0;
			}
			else
				F[i][a[i]]=0;
			for (int j=1;j<=1000;++j)
				F[i][j]=min(F[i][j-1],F[i][j]);
			continue;
		}
		for (int j=0;j<=1000;++j)
			F[i][max(a[i]-j,0)]=min(F[i][max(a[i]-j,0)],F[2*i][j]+F[2*i+1][j]+j);
		for (int j=1;j<=1000;++j)
			F[i][j]=min(F[i][j-1],F[i][j]);
	}
	if (F[1][0]==INF) F[1][0]=-1;
	cout<<F[1][0]<<endl;
	return 0;
}