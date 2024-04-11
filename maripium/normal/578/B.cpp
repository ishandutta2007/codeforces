#include<bits/stdc++.h>
using namespace std;
long a[200005],p[200005],s[200005];
int main()
{
	int n,k,x;
	cin>>n>>k>>x;
	long long mul=1,ans=0;
	while(k--)
		mul*=x;
	for(int i=1;i<=n;i++)
		{
			scanf("%ld",&a[i]);
			p[i]=a[i]|p[i-1];
		}
	for(int i=n;i>0;i--)
		s[i]=s[i+1]|a[i];
	for(int i=1;i<=n;i++)
		ans=max(ans,(p[i-1]|(mul*a[i])|s[i+1]));
	cout<<ans;
	return 0;
}