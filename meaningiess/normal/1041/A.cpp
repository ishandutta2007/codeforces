#include<iostream>
#include<algorithm>
using namespace std;
int a[1010];
int main()
{
	int n,i,ans=0;cin>>n;
	for (i=0;i<n;i++) cin>>a[i];sort(a,a+n);
	for (i=1;i<n;i++) ans+=a[i]-a[i-1]-1;
	cout<<ans;
}