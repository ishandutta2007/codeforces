#include <iostream>
using namespace std;
int abs(int x)
{
	return (x>0)? x:x*-1;
}
int main()
{
	int n,i,mini,c1=1;
	cin >> n;
	int arr[n],ans[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	for (i=1;i<n;i++)
	ans[i]=abs(arr[i]-arr[i-1]);
	ans[0]=abs(arr[0]-arr[n-1]);
	mini=ans[1];
	for (i=0;i<n;i++)
	{
		if (ans[i]<=mini)
		{
			mini=ans[i];
			c1=i;
		}
	}
	if (c1==0)
	cout << 1 << " " << n;
	else
	cout << c1 << " " << c1+1;
}