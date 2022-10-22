#include <iostream>
#define llint long long

using namespace std;

llint b, g, n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> b >> g >> n;
	llint l = max(0LL, n-g), r = min(b, n);
	cout << r-l+1 << endl;
	
	return 0;
}