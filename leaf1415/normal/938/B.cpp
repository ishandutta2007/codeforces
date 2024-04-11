#include <iostream>

using namespace std;

int n;

int main(void)
{
	cin >> n;
	int x, ans = 0;
	for(int i = 0; i < n; i++){
		cin >> x;
		ans = max(ans, min(x-1, 1000000-x));
	}
	cout << ans << endl;
	return 0;
}