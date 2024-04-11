#include<bits/stdc++.h>
using namespace std;

const int maxn=1010;
typedef long long ll;
const ll mo=998244353;
int a[maxn];
int n;
ll ans;
ll f[maxn];
ll C[maxn][maxn];

void prepare()
{
	C[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
}
int main()
{
	scanf("%d",&n);
	prepare();
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[n+1]=1;
	for (int i=n;i>=1;i--)
	if (a[i]>0)
	{
		for (int j=i+1;j<=n+1;j++)
		if (j-i-1>=a[i])
			f[i]=(f[i]+(C[j-i-1][a[i]]*f[j])%mo)%mo;
		ans=(ans+f[i])%mo;
	}
	printf("%lld\n",ans);
	return 0;
}