#include<cstdio>
#include<iostream>

using namespace std;

const int INF=1000000000;
const int MaxN=210;

int n,a,b;
int h[MaxN],s[MaxN];
int F[MaxN][MaxN*MaxN][2];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>a>>b;
	for (int i=1;i<=n;++i)
	{
		cin>>h[i];
		s[i]=s[i-1]+h[i];
	}
	for (int i=1;i<=n;++i)
		for (int j=0;j<=a;++j)
			for (int k=0;k<2;++k)
				F[i][j][k]=INF;
	if (h[1]<=a) F[1][h[1]][0]=0;
	if (h[1]<=b) F[1][0][1]=0;
	for (int i=1;i<n;++i)
		for (int j=0;j<=a;++j)
			for (int k=0;k<2;++k)
			{
				if (F[i][j][k]==INF) continue;
				if (k==0)
				{
					if (j+h[i+1]<=a)
						F[i+1][j+h[i+1]][0]=min(F[i+1][j+h[i+1]][0],F[i][j][0]);
					if (s[i]-j+h[i+1]<=b)
						F[i+1][j][1]=min(F[i+1][j][1],F[i][j][0]+min(h[i],h[i+1]));
				}
				else
				{
					if (j+h[i+1]<=a)
						F[i+1][j+h[i+1]][0]=min(F[i+1][j+h[i+1]][0],F[i][j][1]+min(h[i],h[i+1]));
					if (s[i]-j+h[i+1]<=b)
						F[i+1][j][1]=min(F[i+1][j][1],F[i][j][1]);
				}
			}
	int ans=INF;
	for (int x=0;x<=a;++x)
		for (int k=0;k<2;++k)
			ans=min(ans,F[n][x][k]);
	if (ans==INF)
		puts("-1");
	else
		cout<<ans<<endl;
	return 0;
}