#include <iostream>
using namespace std;
int main()
{
	int n,a=0,b=0;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		int c,d;
		cin >> c >> d;
		a+=(c>d);
		b+=(d>c);
	}
	if (a>b)
	cout << "Mishka";
	else if (a==b)
	cout << "Friendship is magic!^^";
	else
	cout << "Chris";
}