#include <iostream>
using namespace std;
int main()
{
	int n,k;
	cin >> n >> k;
	cout << (n!=k && k) << ' ';
	if (k<=n/3)
	cout << k*2;
	else
	cout << n-k;
}