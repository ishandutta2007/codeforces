#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,i,x,j,ans=0,k,c1,c2;
    cin >> n;
    int arr[n];
    for (i=0;i<n;i++)
    cin >> arr[i];
    c1=count(arr,arr+n,1);
    c2=c1;
    for (i=0;i<n;i++)
    {
    	for (x=i;x<n;x++)
    	{
    		for (j=i;j<=x;j++)
    		{
    			if (arr[j])
    			c2--;
    			else
    			c2++;
			}
			if (c2>ans)
			ans=c2;
			c2=c1;
		}
	}
	cout << ans;
}