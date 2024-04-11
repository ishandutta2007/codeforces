#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	n=n*m/__gcd(n,m);
	cout << k/n;
}