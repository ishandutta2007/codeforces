#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 1e5 + 10;
int T,n,ans[maxn],mx[maxn];
struct node {
	int a,b,id;
	bool operator < (const node &x) const { return a < x.a; }
}v[maxn];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", &v[i].a), v[i].id = i;
		for (int i = 1; i <= n; ++i) scanf("%d", &v[i].b);
		sort(v + 1, v + n + 1);
		for (int i = 1; i <= n; ++i) mx[i] = max(mx[i - 1], v[i].b);
		deque <int> q;
		for (int i = n; i >= 1; --i) {
			ans[v[i].id] = (q.empty() || mx[i] > q.front());
			while ((int)q.size() > 1 && v[i].b > q.front()) q.pop_front();
			if (q.empty() || v[i].b < q.back()) q.push_back(v[i].b);
		}
		for (int i = 1; i <= n; ++i) printf("%d", ans[i]);
		putchar('\n');
	}
	return 0;
}