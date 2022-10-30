# include <bits/stdc++.h>
using namespace std;

set<int> pos;
pair<int,int> a[1000000+10];

const int mod = 1e9 + 7;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	m -= 1;
	pos.insert(0);
	pos.insert(n+1);
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		a[i-1].first = x;
		a[i-1].second = i;
	}
	sort(a, a + n);
	reverse(a, a + n);
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		int p = a[i].second;
		long long val = a[i].first;
		auto it = pos.upper_bound(p);
		int rb = *it; --it;
		int lb = *it;
		pos.insert(p);
		rb = rb - p;
		lb = p - lb;
		if(lb > rb) swap(lb, rb);
		if(lb + rb < m) continue;
		for(int i = 0; i < min(m, lb); ++i) {
			int ml = i, mr = (m - i) % m;
			int cl = (lb - 1 + m - ml) / m;
			int cr = (rb - 1 + m - mr) / m;
			ans = (ans + 1ll * cl * cr % mod * val) % mod;
			if (i == 0) 
				ans = (ans + mod - val) % mod;
		}
	}
	printf("%d\n", ans);
}