#include <iostream>
using namespace std;
int main()
{
	int arr[6],i,s=0;
	for (i=0;i<6;i++)
	cin >> arr[i];
	for (i=0;i<3;i++)
	{
		arr[i]-=arr[i+3];
		if (arr[i]>0)
		arr[i]/=2;
		s+=arr[i];
	}
	if (s>=0)
	cout << "YES";
	else
	cout << "NO";
}