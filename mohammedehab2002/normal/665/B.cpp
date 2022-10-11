#include <iostream>
using namespace std;
int main()
{
	int n,m,k,ans=0;
	cin >> n >> m >> k;
	int arr[k];
	for (int i=0;i<k;i++)
	cin >> arr[i];
	for (int i=0;i<n*m;i++)
	{
		int a,p;
		cin >> a;
		for (int x=0;x<k;x++)
		{
			if (arr[x]==a)
			{
				p=x+1;
				break;
			}
		}
		ans+=p;
		for (int x=p-1;x;x--)
		swap(arr[x],arr[x-1]);
	}
	cout << ans;
}