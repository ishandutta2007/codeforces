#include <iostream>
#include <string.h>
using namespace std;
int n,k;
bool test(int o)
{
	int i,arr[k+1];
	memset (arr,0,sizeof(arr));
	while (o)
	{
		if(o%10<=k)
		arr[(o%10)]++;
		o/=10;
	}
	for (i=0;i<=k;i++)
	{
		if (arr[i]==0)
		return false;
	}
	return true;
}
int main()
{
	cin >> n >> k;
	int ans=0,i,s;
	for (i=0;i<n;i++)
	{
		cin >> s;
		if (test(s))
		ans++;
	}
	cout << ans;
}