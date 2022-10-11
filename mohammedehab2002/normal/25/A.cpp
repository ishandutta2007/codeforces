#include <iostream>
using namespace std;
int main()
{
	int t,i,test=0;
	cin >> t;
	int arr[t];
	for (i=0;i<t;i++)
	{
		cin >> arr[i];
		arr[i]=arr[i]%2;
	}
	for (i=0;i<t-2;i++)
	{
		if (arr[i]!=arr[i+1] && arr[i]!=arr[i+2])
		cout << i+1;
		else
		test++;
	}
	if (test==(t-2))
	{
		if (arr[t-2]!=arr[t-1] && arr[t-2]!=arr[t-3])
		cout << t-1;
		else
		cout << t;
	}
}