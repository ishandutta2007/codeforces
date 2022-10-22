#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[100010],b[100010];
int chk(int x)
{
	ll i=2,j,d=1,t=1,s=k-1;
	while (i<=n)
	{
		t*=x;d++;b[d]=0;
		for (j=1;j<=t && i<=n;i++,j++) a[i]=d,s-=d,b[d]++;
	}
	if (s<0) return 0;j=n;
	while (s)
	{
		d++;if (b[a[j]]==1) j--;
		t=min(s,d-a[j]);s-=t;b[a[j]]--;a[j--]+=t;
	}
	return 1;
}
int main()
{
	ll l=1,r,mid,i,ans;cin>>n>>k;r=n;
	if (k<2*n-1 || k>n*(n+1)/2) puts("No"),exit(0);
	puts("Yes");
	while (l<=r)
	{
		mid=(l+r)>>1;if (chk(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	chk(ans);a[r=1]=1;sort(a+2,a+n+1);memset(b,0,sizeof(b));
	for (i=2;i<=n;i++)
	{
		while (a[r]!=a[i]-1 || b[r]==ans) r++;
		cout<<r<<' ';b[r]++;
	}
}