#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}
template<class T>
T rand() {
	return uniform_int_distribution<T>()(rng);
}

const int N = 1e5;
ll cou[N];
ll tmp[N];
int n;

ll ask(int i) {
	cout << "? " << i+1 << endl;
	ll r;
	cin >> r;
	return r;

	/*
	ll r = cou[i];
	for (int i = 0; i < n; ++i) {
		int pre = (i + (n-1)) % n;
		int nxt = (i + 1) % n;

		if (pre != 0) tmp[i] = (cou[pre] + 1) / 2;
		else tmp[i] = cou[pre];
		if (nxt != 0) tmp[i] += cou[nxt] / 2;
	}
	for (int i = 0; i < n; ++i) {
		cou[i] = tmp[i];
	}
	return cou[i];
	*/
}

void answer(int i) {
	cout << "! " << i + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	/*
	for (n = 4; n <= 10; ++n) {
		for (ll k = 2; k <= 10; k += 2) {
			for (int x0 = 0; x0 < n; ++x0) {

			}
		}
	}
	*/

	ll k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cou[i] = k;

	// If dist(p, i) <= t and i != p,
	//	If the distance to p through both directions is the same, the number if k
	//	If the distance to p goes left, the number is > k
	//	Otherwise, the number is < k
	//	Equality only possible in the two middle elements when n is odd

	int x = rand(0, n-1);
	int t = 0;
	ll v = k;
	for (; t < 1000 && v == k; ++t) {
		x = (x + t) % n;
		v = ask(x);
	}

	if (v > k) {
		// It's somewhere within the previous t
		int low = x + 10*n - t;
		int high = x + 10*n - 1;
		while(low != high) {
			int mid = (low + high + 1) >> 1;
			x = mid % n;
			v = ask(x);
			if (v <= k) low = mid;
			else high = mid - 1;
		}
		answer(low % n);
	} else {
		// It's somewhere within the next t
		int low = x + 10*n + 1;
		int high = x + 10*n + t;
		while(low != high) {
			int mid = (low + high) >> 1;
			x = mid % n;
			v = ask(x);
			if (v >= k) high = mid;
			else low = mid + 1;
		}
		answer(low % n);
	}
}