#include <iostream>

using namespace std;

int n;

int main(void)
{
	cin >> n;
	int a, ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(a > 0) ans += a;
		else ans -= a;
	}
	cout << ans << endl;
	return 0;
}