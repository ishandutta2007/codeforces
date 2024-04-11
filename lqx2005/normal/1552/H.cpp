#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define i64 long long
using namespace std;
int f[9];
int ask(int x) {
	cout << "? "<< 200 * (200 / x) << endl;
	for(int i = x; i <= 200; i += x) {
		for(int j = 1; j <= 200; j++) {
			cout << i <<" " << j << " ";
		}
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}

int main() {
	f[0] = ask(1);
	int l = 1, r = 7, best = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		f[mid] = ask(1 << mid);
		if(f[mid] * (1 << mid) == f[0]) {
			best = mid, l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	f[8] = 0;
	int h = abs(f[best] - f[best + 1] * 2);
	assert(f[best] > 0);
	int w = f[0] / h;
	cout <<"! "<< 2 * (h + w - 2) << endl;
	return 0;
}