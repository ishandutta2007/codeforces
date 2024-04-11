#include<iostream>
using namespace std;
int n,a[111],mx,mxi;
bool f;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		if (a[i]>mx)
		{
			mx=a[i];
			mxi=i;
		}
	}
	for (int i=mxi-1;i>=1;i--)
	{
		if (a[i]>a[i+1] || (a[i]==a[i+1] && a[i]!=mx)) 
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for (int i=mxi+1;i<=n;i++)
	{
		if (a[i]>a[i-1] || (a[i]==a[i-1] && a[i]!=mx))
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}