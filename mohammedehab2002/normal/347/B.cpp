#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int n,i,x,ans=0;
    cin >> n;
    int arr[n];
    for (i=0;i<n;i++)
    {
    	cin >> arr[i];
    	if (arr[i]==i)
    	ans++;
	}
	if (ans<n-1)
	ans++;
	for (i=0;i<n-1;i++)
	{
		if (arr[arr[i]]==i && arr[i]!=i)
		{
			ans++;
			break;
		}
	}
	cout << ans;
}