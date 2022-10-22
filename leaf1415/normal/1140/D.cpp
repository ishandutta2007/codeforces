#include <iostream>
#define llint long long

using namespace std;

llint n;

int main(void)
{
	cin >> n;
	
	llint ans = 0;
	for(llint i = 2; i <= n-1; i++){
		ans += i*(i+1);
	}
	cout << ans << endl;
	
	return 0;
}