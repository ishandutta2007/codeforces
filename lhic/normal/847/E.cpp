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
int n;
char s[120000];
vector<int> p;
vector<int> f;

int main() {
	scanf("%d", &n);
	scanf(" %s", s);
	for (int i = 0; i < n; ++i)
		if (s[i] == 'P')
			p.push_back(i);
		else if (s[i] == '*')
			f.push_back(i);
	int lb = -1;
	int rb = n * 3;
	while (rb - lb > 1) {
		int mid = (lb + rb) >> 1;
		int cur = 0;
		for (int i = 0; i < p.size() && cur < f.size(); ++i) {
			if (f[cur] < p[i]) {
				int d = p[i] - f[cur];
				int go = max((mid - d) >> 1, mid - d * 2);
				if (go >= 0) {
					while (cur < f.size() && f[cur] <= p[i] + go)
						++cur;
				}
			}
			else {
				while (cur < f.size() && f[cur] - p[i] <= mid)
					++cur;
			}
		}
		if (cur == f.size())
			rb = mid;
		else
			lb = mid;
	}
	cout << rb << "\n";
	return 0;
}