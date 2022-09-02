#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll mx = 0;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		mx = max(mx, a);
		sum += a;
	}
	// n*k - sum > sum
	// n*k > 2*sum
	// k > 2*sum / n

	cout << max(mx, 2*sum / n + 1) << '\n';
}