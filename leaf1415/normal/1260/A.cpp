#include <iostream>
#define llint long long

using namespace std;

llint n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint c, s;
	for(int i = 1; i <= n; i++){
		cin >> c >> s;
		llint ans = s%c * ((s+c-1)/c)*((s+c-1)/c);
		ans += (c-s%c)*(s/c)*(s/c);
		cout << ans << endl;
	}
	
	return 0;
}