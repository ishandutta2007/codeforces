#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n%2==0 && n%4)
	cout << n/2-2 << ' ' << n/2+2;
	else
	cout << (n+1)/2-1 << ' ' << n/2+1;
}