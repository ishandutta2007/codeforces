#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	b=a*b+2*d;
	c=a*c+2*e;
	if (b<c)
	cout << "First";
	else if (b>c)
	cout << "Second";
	else
	cout << "Friendship";
}