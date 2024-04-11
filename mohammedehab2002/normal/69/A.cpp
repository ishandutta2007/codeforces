#include <iostream>
using namespace std;
int main()
{
	int n,i,ax=0,ay=0,az=0;
	cin >> n;
	int x[n],y[n],z[n];
	for (i=0;i<n;i++)
	{
		cin >> x[i] >> y[i] >> z[i];
		ax+=x[i];
		ay+=y[i];
		az+=z[i];
	}
	if (ax==0 && ay==0 && az==0)
	cout << "YES";
	else
	cout << "NO";
}