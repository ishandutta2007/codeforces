#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,mini,ans=0,t=0,p;
	cin >> n;
	int arr[n*2-1];
	for (i=0;i<2*n-1;i++)
	{
		cin >> p;
		if (p<0)
		{
			t++;
			arr[i]=-1*p;
		}
		else
		arr[i]=p;
	}
	mini=arr[0];
	for (i=0;i<n*2-1;i++)
	{
		ans+=arr[i];
		if (arr[i]<mini)
		mini=arr[i];
	}
	t%=n;
	if (t%2==0 || (n-t)%2==0)
	cout << ans;
	else
	cout << ans-2*mini;
}