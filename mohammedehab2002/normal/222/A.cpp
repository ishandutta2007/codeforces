#include <iostream>
#include <deque>
using namespace std;
int main()
{
	int n,k,suf=0,pos=0;
	cin >> n >> k;
	int arr[n];
	for (int i=0;i<n;i++)
	{
		cin >> arr[i];
		if (arr[i]!=suf)
		{
			suf=arr[i];
			pos=i;
		}
	}
	if (pos<k)
	cout << n-(n-pos);
	else
	cout << -1;
}