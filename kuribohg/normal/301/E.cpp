#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
int n,m,K,C[110][110],f[101][51][101][101],ans;
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	C[0][0]=1;
	for(int i=1;i<=100;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=min(110,C[i-1][j-1]+C[i-1][j]);
	}
	for(int i=1;i+i<=n;i++) f[1][i][i+i][1]=1;
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j*2<=n;j++)
			for(int len=j;len<=n;len++)
				for(int p=1;p<=K;p++)
					if(f[i-1][j][len][p])
					{
						ans=(ans+(LL)f[i-1][j][len][p]*(LL)(m-i+1))%MOD;
						for(int x=1;len+2*x<=n;x++)
						{
							int t=p*C[j+x-1][x];
							if(t>K) continue;
							f[i][x][len+x+x][t]=(f[i][x][len+x+x][t]+f[i-1][j][len][p])%MOD;
						}
					}
	}
	printf("%d\n",ans);
	return 0;
}