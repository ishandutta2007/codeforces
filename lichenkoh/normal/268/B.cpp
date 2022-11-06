#include <iostream>
#include <assert.h>
using namespace std;
int calc(int n) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (n-i)*(i+1) - i;
	}
	return ans;
}

int main() {
	int n = 0;
	cin >> n;
	int ans = calc(n);
	cout << ans << endl;
	return 0;
}