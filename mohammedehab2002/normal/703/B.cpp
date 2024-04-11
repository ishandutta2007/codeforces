#include <iostream>
using namespace std;
bool c[100005];
int arr[100005],cap[100005];
int main()
{
	long long n,k,sum=0,ans=0;
	cin >> n >> k;
	for (int i=0;i<n;i++)
	cin >> arr[i],sum+=arr[i];
	for (int i=0;i<k;i++)
	{
		cin >> cap[i];
		sum-=arr[cap[i]-1];
		ans+=arr[cap[i]-1]*sum;
		c[cap[i]-1]=true;
	}
	for (int i=0;i<n;i++)
	{
		ans+=arr[i]*arr[(i+1)%n];
		if (c[i] || c[(i+1)%n])
		ans-=arr[i]*arr[(i+1)%n];
	}
	cout << ans;
}