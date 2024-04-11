#include <iostream>

using namespace std;

int n, k;

int main(void)
{
	cin >> n >> k;
	cout << 2*n+1 + min(k-1, n-k)*2 + max(k-1, n-k) << endl;
	return 0;
}