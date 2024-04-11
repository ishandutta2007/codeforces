#include<bits/stdc++.h>
#define ll long long
using namespace std;
int gt(int x)
{
	cout<<"? "<<x<<endl;
	fflush(stdout);
	int y;cin>>y;
	return y;
}
int main()
{
	int n,i;cin>>n;
	int l=1,r=4000*2000,ans;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (gt(mid)==1) ans=mid,r=mid-1;
		else l=mid+1;
	}
	int x=ans;
	for (i=1;i<n;i++)
	{
		int t=x/(i+1),u=gt(t);
		if (t && u)	ans=min(ans,t*u);
	}
	cout<<"! "<<ans<<endl;
}