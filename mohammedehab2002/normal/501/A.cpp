#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a,b,c,d,n1,n2;
	cin >> a >> b >> c >> d;
	n1=max(3*a/10,a-a/250*c);
	n2=max(3*b/10,b-b/250*d);
	if (n1==n2)
	cout << "Tie";
	else if (n1>n2)
	cout << "Misha";
	else
	cout << "Vasya";
}