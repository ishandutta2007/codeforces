#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n==1)
	cout << "1 1" << endl << 1;
	else
	cout << 2*(n-1) << ' ' << 2 << endl << 1 << ' ' << 2;
}