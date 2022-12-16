#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second

const int maxn = 1e6 + 10, N = 1e6;
vi g[maxn];
bitset <maxn> vis;
char t[maxn];

void work() {
	int n;
	scanf("%d%s", &n, t + 1);
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (t[i] == '1')
			for (int j : g[i]) vis[j] = 1;
		else
			for (int j : g[i]) if (!vis[j]) { ans += j; break; }
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= n; ++i) vis[i] = 0;
}

int main() {
	for (int i = 1; i <= N; ++i)
		for (int j = i; j <= N; j += i) g[j].push_back(i);
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}