#include <iostream>
#include <vector>
#include <string>
#define llint long long
#define mod 998244353

using namespace std;

llint h, w;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> w >> h;
	llint ans = 1;
	for(int i = 1; i <= w+h; i++) ans *= 2, ans %= mod;
	cout << ans << endl;
	
	return 0;
}