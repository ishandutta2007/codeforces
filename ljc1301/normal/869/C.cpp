#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=998244353,maxn=5005;
int a,b,c;
long long f[maxn][maxn];
int main()
{
	int i,j,res=1;
	long long t;
	scanf("%d%d%d",&a,&b,&c);
	memset(f,0,sizeof(f));
	f[0][b]=1;
	for(i=1;i<=a;i++)
		for(j=max(0,b-i);j<=b;j++)
			f[i][j]=(f[i-1][j]+(j+1)*f[i-1][j+1])%mod;
	t=0;
	for(i=0;i<=b;i++) t=(t+f[a][i])%mod;
	res=(res*t)%mod;
	memset(f,0,sizeof(f));
	f[0][c]=1;
	for(i=1;i<=b;i++)
		for(j=max(0,c-i);j<=c;j++)
			f[i][j]=(f[i-1][j]+(j+1)*f[i-1][j+1])%mod;
	t=0;
	for(i=0;i<=c;i++) t=(t+f[b][i])%mod;
	res=(res*t)%mod;
	memset(f,0,sizeof(f));
	f[0][c]=1;
	for(i=1;i<=a;i++)
		for(j=max(0,c-i);j<=c;j++)
			f[i][j]=(f[i-1][j]+(j+1)*f[i-1][j+1])%mod;
	t=0;
	for(i=0;i<=c;i++) t=(t+f[a][i])%mod;
	res=(res*t)%mod;
	printf("%d\n",res);
    return 0;
}