#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=105,mod=1e9+7;
int n,q,b[MAXN],c[MAXN];
int f[MAXN][MAXN*MAXN],ans;
int main(){
	//freopen("in","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",c+i);
	for(int i=1; i<n; i++)
		scanf("%d",b+i);
	for(int i=2; i<n; i++)
		b[i]+=b[i-1];
	for(int i=2; i<n; i++)
		b[i]+=b[i-1];
	scanf("%d",&q);
	scanf("%d",&q);
	f[0][0]=1;
	for(int i=1; i<=n; i++)
		for(int j=i*q+b[i-1]; j<=1e4; j++)
			for(int k=0; k<=c[i]&&k<=j; k++)
				f[i][j]=(f[i][j]+f[i-1][j-k])%mod;
	for(int i=0; i<=1e4; i++)
		ans=(ans+f[n][i])%mod;
	printf("%d\n",ans);
	return 0;
}