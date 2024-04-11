#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans=1;
const ll mo=998244353;
const int maxn=200010;
int n,m,A;
int a[maxn];
ll powmod(ll a,ll b)
{
	ll ans=1;
	while (b)
	{
		if (b&1)	ans=(ans*a)%mo;
		a=a*a%mo;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&A);
	for (int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	m=unique(a+1,a+m+1)-a-1;
	ll inv2=powmod(2,mo-2);
	for (int i=1;i<=m;i++)
	{
		int t=a[i]-a[i-1];
		ll q=powmod(A,t);
		q=q*(q-1)%mo*inv2%mo;
		(q+=powmod(A,t))%=mo;
		ans=ans*q%mo;
	}
	ans=ans*powmod(A,n-2*a[m])%mo;
	cout<<ans<<endl;
	return 0;
}