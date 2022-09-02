#include <iostream>
using namespace std;
using ll = long long;

void solve() {
	ll n, s, t;
	cin >> n >> s >> t;
	ll b = s+t-n;
	ll a = s - b;
	ll c = t - b;
	cout << max(a+1, c+1) << '\n';
}

int main() {
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}