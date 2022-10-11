#include <iostream>
using namespace std;
int main()
{
	int a;
	cin >> a;
	if (a%3)
	cout << a/3*2+1;
	else
	cout << a*2/3;
}