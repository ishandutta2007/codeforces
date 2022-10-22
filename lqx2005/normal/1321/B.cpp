#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=800000;
int but[maxn+5];
int n;
int b[maxn+5],f[maxn+5];
int ID(int x)
{
	return x+400000;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)
	{
		f[i]=but[ID(i-b[i])]+b[i];
		but[ID(i-b[i])]=max(but[ID(i-b[i])],f[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}