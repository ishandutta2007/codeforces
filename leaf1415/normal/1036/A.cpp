#include <iostream>
#define llint long long

using namespace std;

llint n, k;

int main(void)
{
	cin >> n >> k;
	cout << (k+n-1)/n << endl;
	return 0;
}