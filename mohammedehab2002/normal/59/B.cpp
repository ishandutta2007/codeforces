#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main()
{
	int n,i,n1=1,n2=1,ans=0;
	cin >> n;
	int arr[n],e[n+1],o[n+1];
	e[0]=0;
	o[0]=0;
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		if (arr[i]%2 || arr[i]==1)
		{
			o[n1]=arr[i];
			n1++;
		}
		else
		{
			e[n2]=arr[i];
			ans+=arr[i];
			n2++;
		}
	}
	sort (o,o+n1);
	sort (e,e+n2);
	ans+=o[n1-1];
	for (i=n1-2;i>0;i-=2)
	{
		if (i==1)
		break;
		ans+=o[i]+o[i-1];
	}
	if (ans%2)
	cout << ans;
	else
	cout << 0;
}