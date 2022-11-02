#include<bits/stdc++.h>
using namespace std;

//typedef long long ll;
const int maxn=20010;
int a[maxn];
int pre[maxn];
int pos[maxn][110];
int ha[maxn];
int f[maxn][110];
int n,m,p;
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	memset(ha,-1,sizeof(ha));
	memset(pos,-1,sizeof(pos));
	/*
	for (int i=0;i<=n;i++)
		for (int j=0;j<p;j++)
			f[i][j]=-100000;
	f[0][0]=0;
	*/
	ha[0]=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i][1]=(f[i-1][1]+a[i])%p;
		pre[i]=(pre[i-1]+a[i])%p;
		for (int j=0;j<p;j++)
			pos[i][j]=ha[(pre[i]-j+p)%p];
		ha[pre[i]]=i;
	}
	for (int i=1;i<=n;i++)
		for (int j=2;j<=m && j<=i;j++)
			for (int l=0;l<p;l++)
			if (pos[i][l]!=-1)
			{
				int k=pos[i][l];
				if (l==0 && k>=j-1)
				{
					f[i][j]=max(f[i][j],f[k][j]);
				}
				if (k>=j-1)
					f[i][j]=max(f[i][j],f[k][j-1]+(pre[i]-pre[k]+p)%p);
			}
	printf("%d\n",f[n][m]);
	return 0;
}