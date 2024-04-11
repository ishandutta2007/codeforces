#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,l;
	cin >> n >> l;
	int arr[n],arr2[n];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	for (int i=0;i<n;i++)
	cin >> arr2[i];
	int c=l+1;
	while (c--)
	{
		for (int i=0;i<n;i++)
		{
			arr[i]--;
			if (arr[i]<0)
			arr[i]+=l;
		}
		sort(arr,arr+n);
		bool b=1;
		for (int i=0;i<n;i++)
		b&=(arr[i]==arr2[i]);
		if (b)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}