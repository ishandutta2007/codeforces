#include <iostream>
using namespace std;
int main()
{
	int a1,a2,a3,b1,b2,b3,n,a,b;
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
	a=a1+a2+a3;
	b=b1+b2+b3;
	if (a%5)
	a=a/5+1;
	else
	a/=5;
	if (b%10)
	b=b/10+1;
	else
	b/=10;
	if (a+b<=n)
	cout << "YES";
	else
	cout << "NO";
}