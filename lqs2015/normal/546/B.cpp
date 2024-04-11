//546B
#include<iostream>
using namespace std;
int n,a[55555];
int num[55555];
int ans,mx;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		num[a[i]]++;
		if (a[i]>mx) mx=a[i];
	}
	for (int i=1;i<=2*n;i++)
	{
		for (int j=1;num[i]>1;j++)
		{
			num[i]--;
			ans+=j;
			num[i+j]++;
		}
	}
	cout<<ans<<endl;
	return 0;
}