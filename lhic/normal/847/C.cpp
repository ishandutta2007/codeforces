#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

char s[1000000];
void run(int l, int n, ll k) {
	if (n == 0) {
		if (k == 0)
			return;
		cout << "Impossible\n";
		exit(0);
	}
	int r = l + 2 * n;
	if (k >= n - 1) {
		s[l] = '(';
		s[r - 1] = ')';
		run(l + 1, n - 1, k - (n - 1));
	}
	else {
		s[l] = '(';
		s[l + 2 * k + 1] = ')';
		for (int i = l + 1; i < l + 2 * k + 1; i += 2)
			s[i] = '(', s[i + 1] = ')';
		for (int i = l + 2 * k + 1 + 1; i < r; i += 2)
			s[i] = '(', s[i + 1] = ')';
	}
}

int main() {
	int n;
	ll k;
	cin >> n >> k;
	run(0, n, k);
	printf("%s\n", s);
	return 0;
}