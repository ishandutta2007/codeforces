#include<bits/stdc++.h>
using namespace std;
const int N=1110;
int t,n,k,l;
int f[N][N];
int p[N<<2],d[N];
int main()
{
	scanf("%d",&t);
	for(int amo=1;amo<=t;amo++)
	{
		scanf("%d%d%d",&n,&k,&l);
		for(int i=1;i<=n;i++) scanf("%d",&d[i]);
		for(int i=0;i<=k;i++) p[i]=i;
		for(int i=k+1;i<2*k;i++) p[i]=2*k-i;
		k*=2;
		for(int i=0;i<k;i++) for(int j=0;j<=n+1;j++) f[j][i]=0;
		for(int i=0;i<k;i++) f[n+1][i]=1;
		for(int i=n;i>=1;i--)
		{
			for(int j=0;j<k;j++) f[i][j]|=f[i+1][(j+1)%k];
			for(int j=0;j<k;j++) if(d[i]+p[j%k]>l) f[i][j]=0;
			for(int j=k*2;j>=0;j--)
			{
				if(d[i]+p[j%k]>l) continue;
				f[i][j%k]|=f[i][(j+1)%k];
			}
		}
		int flag=0;
		for(int i=0;i<k;i++) if(f[1][i]) flag=1;
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}