#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n%10<5)
	cout << n-n%10;
	else
	cout << n+10-n%10;
}