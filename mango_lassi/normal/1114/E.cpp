#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand() {
	return uniform_int_distribution<T>()(rng);
}

int ask(int x) {
	cout << "? " << (x+1) << endl;
	int res;
	cin >> res;
	return res;
}
bool larger(int v) {
	cout << "> " << v << endl;
	bool res;
	cin >> res;
	return res;
}
void answer(int x1, int d) {
	cout << "! " << x1 << ' ' << d << endl;
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int n;
	cin >> n;

	// Find d
	int d = 0;
	vector<int> vals;
	for (int i = 0; i < 30; ++i) {
		int x = rand<ll>() % n;
		int val = ask(x);
		for (auto v : vals) {
			d = gcd(d, abs(v - val));
		}
		vals.push_back(val);
	}

	// Find largest (takes at most 30 operations)
	ll low = 0;
	ll high = INF;
	while(low != high) {
		ll mid = (low + high) >> 1;
		if (larger(mid)) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}

	// Answer
	ll x1 = low - d * (n-1);
	answer(x1, d);
}