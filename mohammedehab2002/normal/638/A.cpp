#include <iostream>
using namespace std;
int main()
{
	int a,b;
	cin >> a >> b;
	if (b%2)
	cout << (b+1)/2;
	else
	cout << (a-b+2)/2;
}