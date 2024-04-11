#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e9;

bool pick(int x, int y) {
	cout << x << ' ' << y << endl;
	string str;
	cin >> str;
	return (str == "black");
}

int main() {
	int n;
	cin >> n;

	int low = 0;
	int high = N+1;
	bool xr = pick(0, 0);
	for (int j = 1; j < n; ++j) {
		int mid = (low + high + 1) >> 1;
		bool sub = pick(mid, 0);
		sub ^= xr;
		if (sub) high = mid;
		else low = mid;
	}
	
	// Make a line that goes between low and high
	// High is always above low
	// ... a b ...
	//     x
	//     .
	//   x .
	if (high - low > 1) {
		int mid = (high + low) / 2;
		cout << mid << ' ' << 0 << ' ' << mid << ' ' << 1 << endl;
	} else {
		if (low < 100) {
			cout << high << ' ' << 1 << ' ' << high+1 << ' ' << 3 << endl;
		} else {
			cout << low << ' ' << 1 << ' ' << low-1 << ' ' << 3 << endl;
		}
	}
}