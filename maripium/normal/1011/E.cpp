#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	int GCD = k;
	while (n--) {
		int x; cin >> x;
		x % k;
		GCD = __gcd(GCD, x);
	}
	cout << k / GCD << '\n';
	for (int i = 0; i < k; i += GCD) cout << i << ' ';
}