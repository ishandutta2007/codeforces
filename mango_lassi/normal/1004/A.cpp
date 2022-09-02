#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int n, d;
	cin >> n >> d;
	int ans = 2;
	int prev;
	cin >> prev;
	for (int i = 1; i < n; ++i) {
		int x;
		cin >> x;
		if (x - prev >= 2 * d) ++ans;
		if (x - prev >  2 * d) ++ans;
		prev = x;
	}
	cout << ans << '\n';
}