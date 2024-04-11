#include <iostream>
#include <chrono>
#include <random>
using namespace std;
typedef long long ll;

bool ask(ll a, ll b) {
	cout << a << ' ' << b << endl;
	string ans;
	cin >> ans;
	return (ans == "Yes");
}

int main() {
	// Good random gen to avoid hacks
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	ll n;
	int k;
	cin >> n >> k;

	ll a = 1;
	ll b = n;
	while(true) {
		a = max((ll)1, a - k);
		b = min(n, b + k);
		ll len = b - a + 1;
		if (len <= 50) {
			ll pos = uniform_int_distribution<ll>(a, b)(rng);
			if (ask(pos, pos)) break;
		} else {
			ll mid = (a + b) >> 1;
			if (ask(a, mid)) b = mid;
			else a = mid + 1;
		}
	}
}