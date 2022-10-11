#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,x,l;
	cin >> n;
	for (i=0;i<n/2;i++)
	{
		l=(i+1)*2-1;
		for (x=0;x<(n-l)/2;x++)
		cout << '*';
		for (x=0;x<l;x++)
		cout << 'D';
		for (x=0;x<(n-l)/2;x++)
		cout << '*';
		cout << endl;
	}
	for (i=0;i<n;i++)
	cout << 'D';
	for (i=0;i<n/2;i++)
	{
		cout << endl;
		l=(n/2-i)*2-1;
		for (x=0;x<(n-l)/2;x++)
		cout << '*';
		for (x=0;x<l;x++)
		cout << 'D';
		for (x=0;x<(n-l)/2;x++)
		cout << '*';
	}
}