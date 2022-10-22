#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[300030];
int chk(int x)
{
	int lst=0,t,i;
	for (i=1;i<=n;i++) if (lst>=a[i])
	{
		if (lst-a[i]>x) return 0;
	}
	else
	{
		if (a[i]+x<m || (a[i]+x)%m<lst) lst=a[i];
	}
	return 1;
}
int main()
{
	int i,l=0,r,ans=0;cin>>n>>m;r=m;
	for (i=1;i<=n;i++) cin>>a[i];
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (chk(mid)) ans=mid,r=mid-1;else l=mid+1;
	}
	cout<<ans;
}