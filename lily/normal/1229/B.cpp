#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)


#define N 123121
#define MOD 1000000007

LL gcd(LL a, LL b) {
	LL c;
	while (b) {
		c = a;
		a = b;
		b = c % b;
	}
	return a;
}

int n;
vector <int> E[N];
LL a[N], ans ;

void dfs(int x, int fa, int dep, vector <pair<LL, int>> s) {
	{
	auto nx = s;
	nx.push_back({a[x], dep});
	s.clear();
	for (auto &v : nx) {
		LL cur = gcd(a[x], v.first);
		if (s.size() && s.back().first == cur) {
			continue;
		}
		s.push_back({cur, v.second});
	}
	}
	for (int i = (int)s.size() - 1, cur = dep + 1; ~i; i--) {
		(ans += s[i].first * (cur - s[i].second)) %= MOD;
		cur = s[i].second;
	}

	for (auto v : E[x]) if (v != fa){
		dfs(v, x, dep + 1, s);
	}
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++)scanf("%lld", & a[i]);
	for (int i = 1; i < n; i++) {
		int u, v;
		read(u); read(v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1, -1, 0, {});
	cout << ans << endl;
}