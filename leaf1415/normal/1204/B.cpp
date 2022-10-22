#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint n, l, r;

int main(void)
{
	cin >> n >> l >> r;
	
	llint ans = 0;
	for(int i = 0; i < l; i++) ans += (1LL<<i);
	ans += (n-l);
	cout << ans << " ";
	
	ans = 0;
	for(int i = 0; i < r; i++) ans += (1LL<<i);
	ans += (n-r) * (1LL<<(r-1));
	cout << ans << endl;
	
	return 0;
}