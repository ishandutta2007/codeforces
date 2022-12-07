#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=200010;
int n,k,x;
LL a[MAXN],pre[MAXN],suf[MAXN],ans;
int main()
{
	scanf("%d%d%d",&n,&k,&x);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]|a[i];
	for(int i=n;i>=1;i--) suf[i]=suf[i+1]|a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++) a[i]*=x;
		ans=max(ans,pre[i-1]|suf[i+1]|a[i]);
		for(int j=1;j<=k;j++) a[i]/=x;
	}
	printf("%I64d\n",ans);
	return 0;
}