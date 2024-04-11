#include<bits/stdc++.h>
using namespace std;

const int maxn=110;
char s[2][maxn];
int f[maxn][4];
char a[2][2];
int n;
int main()
{
	scanf("%s",s[0]+1);
	scanf("%s",s[1]+1);
	n=strlen(s[0]+1);
	f[0][0]=f[0][1]=f[0][2]=-1;
	f[0][3]=0;
	for (int i=1;i<=n;i++)
	{
		f[i][0]=f[i][1]=f[i][2]=f[i][3]=-1;
		for (int j=0;j<4;j++)
		if (f[i-1][j]!=-1)
		{
			if (j&2)	a[0][0]='X';else a[0][0]='0';
			if (j&1)	a[1][0]='X';else a[1][0]='0';
			a[0][1]=s[0][i];
			a[1][1]=s[1][i];
			int t=0;
			if (a[0][1]=='X')	t+=2;
			if (a[1][1]=='X')	t+=1;
			f[i][t]=max(f[i-1][j],f[i][t]);
			if (a[0][0]=='0' && a[0][1]=='0' && a[1][0]=='0')
				f[i][t+2]=max(f[i-1][j]+1,f[i][t+2]);
			if (a[0][0]=='0' && a[0][1]=='0' && a[1][1]=='0')
				f[i][t+3]=max(f[i-1][j]+1,f[i][t+3]);
			if (a[0][1]=='0' && a[1][0]=='0' && a[1][1]=='0')
				f[i][t+3]=max(f[i-1][j]+1,f[i][t+3]);
			if (a[0][0]=='0' && a[1][0]=='0' && a[1][1]=='0')
				f[i][t+1]=max(f[i-1][j]+1,f[i][t+1]);
		}
	}
	printf("%d\n",max(max(f[n][0],f[n][1]),max(f[n][2],f[n][3])));
	return 0;
}