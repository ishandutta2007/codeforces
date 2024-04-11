#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	int s=a+b+c+d+e;
	if (s%5 || !s)
	cout << -1;
	else
	cout << s/5;
}