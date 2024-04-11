#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long arr[n],dif[n-1];
	for (int i=0;i<n;i++)
	{
		cin >> arr[i];
		if (i)
		dif[i-1]=abs(arr[i]-arr[i-1]);
	}
	for (int i=0;i<n-1;i+=2)
	dif[i]=-dif[i];
	long long ans=0,s=0;
	for (int i=0;i<n-1;i++)
	{
		s+=dif[i];
		s=max(s,dif[i]);
		ans=max(ans,s);
	}
	s=0;
	for (int i=0;i<n-1;i++)
	{
		s-=dif[i];
		s=max(s,-dif[i]);
		ans=max(ans,s);
	}
	cout << ans;
}