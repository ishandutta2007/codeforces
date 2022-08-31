#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MaxN=5010;

int n;
char s[MaxN];
int F[MaxN][MaxN];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	s[0]=1;
	for (int i=1;i<=n;++i)
	{
		for (int j=0;s[i-j]==s[i+j];++j)
			F[i-j][i+j]=1;
		for (int j=0;s[i-j]==s[i+j+1];++j)
			F[i-j][i+j+1]=1;
	}
	for (int j=1;j<=n;++j)
		for (int i=1;i+j<=n;++i)
			F[i][i+j]+=F[i+1][i+j]+F[i][i+j-1]-F[i+1][i+j-1];
	int T;
	cin>>T;
	while (T--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",F[x][y]);
	}
	return 0;
}