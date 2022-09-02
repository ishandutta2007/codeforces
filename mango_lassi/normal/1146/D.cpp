#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

const int N = 3 * (int)1e5;
bool reach[N];
int a, b, h;

int dfs(int i) {
	if (reach[i]) return 0;
	reach[i] = true;

	int res = 1;
	if (i + a <= h) res += dfs(i+a);
	if (i - b >= 0) res += dfs(i-b);
	return res;
}

ll sum(ll k, ll t) {
	ll val = (t / k + 1);
	ll len = (t / k);
	ll lst = len * k;

	ll res = 0;
	res += (t - lst + 1) * val;
	res += k * (len * (len + 1) / 2);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> m >> a >> b;
	
	// When n >= 2 * max(a, b), the frog can visit n / gcd(a, b) squares
	// We brute the ones before that.
	ll res = 0;
	ll cou = 1;
	reach[0] = true;
	for (h = 0; h <= min(N, m); ++h) {
		if ((h - a >= 0) && reach[h - a]) {
			cou += dfs(h);
		}
		res += cou;
	}
	if (h <= m) {
		int gd = gcd(a, b);
		res += sum(gd, m) - sum(gd, h-1);
	}

	cout << res << '\n';
}