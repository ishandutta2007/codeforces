#include <iostream>
using namespace std;
int main()
{
	int n,a,n1=0,n2=0,i;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a;
		if (a==100)
		n1++;
		else
		n2++;
	}
	if (n1%2==0 && n2%2==0)
	{
		cout << "YES";
		return 0;
	}
	if (n1%2==0 && n2%2 && n1!=0)
	{
		cout << "YES";
		return 0;
	}
	n2+=n1/2;
	n1=n1%2;
	if (n2%2==0 && n1==0)
	cout << "YES";
	else
	cout << "NO";
}