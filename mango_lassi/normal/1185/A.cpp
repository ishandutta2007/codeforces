#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b < a) swap(a, b);
	if (c < b) swap(b, c);
	if (b < a) swap(a, b);
	if (c < b) swap(b, c);
	ll res = max(0ll, d - (b-a)) + max(0ll, d - (c-b));
	cout << res << '\n';
}