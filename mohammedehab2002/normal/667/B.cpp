#include <iostream>
using namespace std;
int abs(int x)
{
	return (x>0)? x:-x;
}
int main()
{
	int n,a,i,b=0,c=0;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a;
		b=max(b,a);
		c+=a;
	}
	cout << abs(c-2*b)+1;
}