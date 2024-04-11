#include <iostream>
using namespace std;
int main()
{
	int n,o=0,lo;
	cin >> n;
	long long arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	again: lo=o;
	for (int i=0;i<n;i++)
	{
		if (i+1==n)
		break;
		if (arr[i]>arr[i+1])
		{
			cout << i+1 << ' ' << i+2 << endl;
			swap(arr[i],arr[i+1]);
			o++;
			i++;
		}
	}
	if (lo==o)
	return 0;
	goto again;
}