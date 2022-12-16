#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

const int maxn = 3e5 + 10;
int n,m,a[maxn];
set <pii> con;
map <int, int> cnt;
vector <int> p[maxn];
void work() {
	scanf("%d%d", &n, &m);
	cnt.clear(), con.clear();
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), cnt[a[i]]++, p[i].clear(), con.insert(make_pair(a[i], a[i]));
	for (int i = 1; i <= m; ++i) {
		int u,v;
		scanf("%d%d", &u, &v);
		con.insert(make_pair(u, v));
		con.insert(make_pair(v, u));
	}
	for (pii pp : cnt) p[pp.second].push_back(pp.first);
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		sort(p[i].begin(), p[i].end(), greater <int> ());
		for (int x : p[i]) {
			for (int j = 1; j <= i; ++j) {
				auto it = p[j].begin();
				while (it != p[j].end() && con.find(make_pair(*it, x)) != con.end()) ++it;
				if (it != p[j].end())
					ans = max(ans, 1ll * (i + j) * (x + (*it)));
			}
		}
	}
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}