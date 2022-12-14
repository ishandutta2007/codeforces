#include<iostream>
#include<algorithm>
using namespace std;
int a[111];
int n,ans;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n]*n;
	for (int i=1;i<=n;i++)
	{
		ans-=a[i];
	}
	cout<<ans<<endl;
	return 0;
}