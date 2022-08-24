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

multiset<int> ss;

int n;
int p[323000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", p + i);
	ll cur = 0;
	for (int i = 0; i < n; ++i) {
		if (!ss.empty()) {
			int x = *ss.begin();
			if (x < p[i]) {
				cur -= x;
				ss.erase(ss.begin());
				cur += p[i];
				ss.insert(p[i]);
				ss.insert(p[i]);
			}
			else {
				ss.insert(p[i]);
			}
		}
		else {
			ss.insert(p[i]);
		}
	}
	cout << cur << "\n";
	return 0;
}