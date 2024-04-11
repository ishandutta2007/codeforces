#include <iostream>
#define llint long long

using namespace std;

llint n;

int main(void)
{
	cin >> n;
	n++;
	
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	
	llint ans = 0;
	if(n % 2 == 0){
		ans++;
		n /= 2;
		ans += n-1;
	}
	else ans = n;
	cout << ans << endl;
	
	return 0;
}