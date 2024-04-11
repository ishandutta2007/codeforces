#include <iostream>
using namespace std;
int main()
{
	bool l=true;
	int n,i,pos=-1,ans=0;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		if (l)
		{
			if (arr[i])
			l=false;
			pos=i;
		}
	}
	if (pos==-1)
	{
		cout << 0;
		return 0;
	}
	for (i=pos;i<n;i++)
	{
		if (arr[i])
		ans++;
		else
		{
			if (i!=n-1 && arr[i+1])
			ans++;
			else
			{
				while (arr[i]==0)
				i++;
				i--;
			}
		}
	}
	cout << ans;
}