#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,s=0,e=0;
	bool b=true;
	cin >> n;
	int arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	for (int i=1;i<n;i++)
	{
		if  (arr[i]>arr[i-1])
		{
			if (!b)
			{
				e=i;
				b=true;
			}
		}
		else
		{
			if (b)
			{
				s=i-1;
				e=i-2;
				b=false;
			}
		}
	}
	if (s==e)
	{
		cout << "yes" << endl << 1 << ' ' << 1;
		return 0;
	}
	if (s>e)
	e=n;
	reverse(arr+s,arr+e);
	for (int i=1;i<n;i++)
	{
		if (arr[i]<arr[i-1])
		{
			cout << "no";
			return 0;
		}
	}
	cout << "yes" << endl << s+1 << ' ' << e;
}