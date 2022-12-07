#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=400010;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int n,a[MAXN],GCD[MAXN],Max[MAXN],f[MAXN];
LL ans,d[MAXN];
bool flag[MAXN];
LL solve(int k)
{
	for(int i=1;i<n;i++) flag[i]=false;
	for(int i=1;i<n;i++)
		if(GCD[i]==k) flag[i]=true;
	LL w=0;
	for(int i=1;i<=n;i++)
	{
		if(flag[i]) w++;
		d[i]=w;
	}
	for(int i=0;i<n;i++) f[i]=0,Max[i]=0;
	for(int i=0;i<n;i++) Max[i%k]=max(Max[i%k],a[i]);
	if(a[0]>=Max[0]) f[0]=1;
	else f[0]=0;
	for(int i=0;i<n+n;i++)
	{
		if(a[i]>=Max[i%k]) f[i]=f[i-1]+1;
		else f[i]=0;
		if(f[i]>n) f[i]=n;
	}
	LL ans=0;
	for(int i=n;i<n+n;i++) ans+=d[f[i]];
	return ans;	
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=n;i<n+n;i++) a[i]=a[i-n];
	for(int i=1;i<=n;i++) GCD[i]=gcd(i,n);
	for(int i=1;i<n;i++)
		if(n%i==0) ans+=solve(i);
	printf("%I64d\n",ans);
	return 0;
}