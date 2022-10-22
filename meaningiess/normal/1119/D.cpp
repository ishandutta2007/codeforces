#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
ll a[N],b[N],c[N],s[N],l,r;int n,i,q;
void pre()
{
	for (i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (i=2;i<=n;i++) b[i-1]=a[i]-a[i-1];
	sort(b+1,b+n);
	for (i=1;i<=n;i++) s[i]=s[i-1]+b[i];
}
int main()
{
	cin>>n;
	pre();
	cin>>q;
	while (q--)
	{
		cin>>l>>r;r-=l;
		int ans=upper_bound(b+1,b+n,r)-b-1;
		cout<<(ll)s[ans]+((ll)n-ans)*(r+1)<<' ';
	}
}