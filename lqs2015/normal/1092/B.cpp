#include<bits/stdc++.h>
using namespace std;
int n,a[111],ans;
int main()
{
	cin>>n; 
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i+=2)
	{
		ans+=(a[i+1]-a[i]);
	}
	cout<<ans<<endl;
	return 0;
}