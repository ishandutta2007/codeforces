#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,t;
	cin >> n>> t;
	int arr[n+1];
	for (int i=1;i<n;i++)
	cin >> arr[i];
	int pos=1;
	while (pos<t)
	pos+=arr[pos];
	if (pos==t)
	cout << "YES";
	else
	cout << "NO";
}