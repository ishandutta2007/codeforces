#include <iostream>
using namespace std;
int main()
{
	int n,k,ans=0;
	cin >> n >> k;
	int arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	for (int i=0;i<k;i++)
	ans+=arr[i];
	int mini=ans,pos=1;
	for (int i=k;i<n;i++)
	{
		ans=ans+arr[i]-arr[i-k];
		if (ans<mini)
		{
			mini=ans;
			pos=i+2-k;
		}
	}
	cout << pos;
}