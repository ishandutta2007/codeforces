#include <iostream>
#define llint long long

using namespace std;

llint n, k;

int main(void)
{
	cin >> n >> k;
	llint ans = (2*n+k-1)/k;
	ans += (5*n+k-1)/k;
	ans += (8*n+k-1)/k;
	cout << ans << endl;
	
	return 0;
}