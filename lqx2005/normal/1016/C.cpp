#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1000000;
int n;
int a[maxn+5],b[maxn+5];
int suma[maxn+5],sumb[maxn+5],sumc[maxn+5],sumd[maxn+5],sume[maxn+5],sumf[maxn+5];
int calc(int pos,int id,int Time)
{
	int sum=0;
	if(id==0)
	{
		sum+=sumc[n]-sumc[pos-1];
		sum+=(Time-pos)*(suma[n]-suma[pos-1]);
		Time+=(n-pos);
		Time++;
		sum+=sumf[n]-sumf[pos-1];
		sum+=(Time-1)*(sumb[n]-sumb[pos-1]);
	}
	else
	{
		sum+=sumd[n]-sumd[pos-1];
		sum+=(Time-pos)*(sumb[n]-sumb[pos-1]);
		Time+=(n-pos);
		Time++;
		sum+=sume[n]-sume[pos-1];
		sum+=(Time-1)*(suma[n]-suma[pos-1]);		
	}
	return sum;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++) suma[i]=suma[i-1]+a[i];
	for(int i=1;i<=n;i++) sumb[i]=sumb[i-1]+b[i];
	for(int i=1;i<=n;i++) sumc[i]=sumc[i-1]+i*a[i];
	for(int i=1;i<=n;i++) sumd[i]=sumd[i-1]+i*b[i];
	for(int i=1;i<=n;i++) sume[i]=sume[i-1]+(n-i+1)*a[i];
	for(int i=1;i<=n;i++) sumf[i]=sumf[i-1]+(n-i+1)*b[i];
	int ans=0,Time=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			ans=max(ans,sum+calc(i,0,Time));
			sum+=Time*a[i];
			Time++;
			sum+=Time*b[i];
			Time++;
		}
		else
		{
			ans=max(ans,sum+calc(i,1,Time));
			sum+=Time*b[i];
			Time++;
			sum+=Time*a[i];
			Time++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}