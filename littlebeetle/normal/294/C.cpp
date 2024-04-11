#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1002,M=1000000007;
typedef long long ll;
ll n,m,i,a[N],fac[N],inv[N],f[N],ans;
int main(){
	scanf("%lld%lld",&n,&m);
	for(f[0]=1,fac[0]=1,i=1;i<=n;i++)
		f[i]=f[i-1]*2%M,fac[i]=fac[i-1]*i%M;
	for(inv[1]=1,i=2;i<=n;i++)
		inv[i]=(M-M/i)*inv[M%i]%M;
	inv[0]=1;
	for(i=2;i<=n;i++)
		inv[i]=inv[i-1]*inv[i]%M;	
	for(i=1;i<=m;i++)
		scanf("%lld",a+i);
	sort(a+1,a+m+1);
	a[m+1]=n+1;
	ans=fac[n-m];
	for(i=1;i<=m+1;i++)
		ans=ans*inv[a[i]-a[i-1]-1]%M;
	for(i=2;i<=m;i++)
		if(a[i]!=a[i-1]+1)
		ans=ans*f[a[i]-a[i-1]-2]%M;
	printf("%lld",ans);
}