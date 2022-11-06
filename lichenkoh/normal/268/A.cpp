#include <iostream>
#include <assert.h>
using namespace std;
int calc(int *home, int *guest, int n) {
	int ans = 0;
	for (int i = 0; i < n; i++) { //i is the host
		for (int j = 0; j < n; j++) { //j is the guest
			if (i == j) continue;
			if (home[i] == guest[j]) {
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	int *home = new int[n];
	int * guest = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> home[i];
		cin >> guest[i];
	}
	int ans = calc(home,guest,n);
	cout << ans << endl;
	return 0;
}