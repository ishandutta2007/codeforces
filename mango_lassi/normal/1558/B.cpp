#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mAdd(ll a, ll b, ll p) {
	if (a + b >= p) return a + b - p;
	else return a + b;
}
ll mSub(ll a, ll b, ll p) {
	if (a < b) return a + p - b;
	else return a - b;
}

const int N = 4 * (int)1e6;
ll suff[N+2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, p;
	cin >> n >> p;

	suff[n] = 1;
	for (int i = n-1; i >= 1; --i) {
		// Subtractions
		suff[i] = mAdd(suff[i+1], suff[i+1], p);

		// Divisions
		for (int j = 2; i*j <= n; ++j) {
			int a = i*j;
			int b = min(n + 1, (i+1)*j);
			suff[i] = mAdd(suff[i], mSub(suff[a], suff[b], p), p);
		}
	}
	cout << mSub(suff[1], suff[2], p) << '\n';
}