#include <iostream>
#define llint long long

using namespace std;

llint n, k;

int main(void)
{
	cin >> n >> k;
	
	llint l = k/2+1;
	llint u = min(n, k-1);
	
	cout << max(0LL, u-l+1) << endl;
	return 0;
}