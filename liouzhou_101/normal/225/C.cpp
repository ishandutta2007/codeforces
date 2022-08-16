#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=1010;
const int INF=1000000000;

int n,m,x,y;
char s[MaxN][MaxN];
int p[MaxN],q[MaxN];
int F[MaxN][2];

int main()
{
	cin>>n>>m>>x>>y;
	for (int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for (int i=1;i<=m;++i)
	{
		for (int j=1;j<=n;++j)
			if (s[j][i]=='.') ++p[i]; else ++q[i];
		p[i]+=p[i-1];
		q[i]+=q[i-1];
	}
	for (int i=0;i<=m;++i)
		for (int k=0;k<=1;++k)
			F[i][k]=INF;
	F[0][0]=F[0][1]=0;
	for (int i=1;i<=m;++i)
	{
		for (int j=1;j<=i;++j)
		{
			if (!(i-j+1>=x&&i-j+1<=y)) continue;
			F[i][0]=min(F[i][0],F[j-1][1]+p[i]-p[j-1]);
			F[i][1]=min(F[i][1],F[j-1][0]+q[i]-q[j-1]);
		}
	}
	cout<<min(F[m][0],F[m][1])<<endl;
	return 0;
}