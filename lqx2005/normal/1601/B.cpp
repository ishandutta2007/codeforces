#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 6e5 + 10;
int n, a[N], b[N];
int dis[N], pre[N];
queue<int> q;
set<int> s[2];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++) s[0].insert(i), s[1].insert(i);
	q.push(n);
	dis[n] = 0;
	s[0].erase(n);
	int now = -1, ans = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(u > n) {
			u -= n;
			if(s[0].count(u + b[u])) {
				s[0].erase(u + b[u]);
				dis[u + b[u]] = dis[u + n];
				q.push(u + b[u]);
				pre[u + b[u]] = u + n;
			}
		} else {
			if(u - a[u] <= 0) {
				now = u;
				ans = dis[u];
				break;
			}
			auto itr = s[1].lower_bound(u + 1), itl = s[1].lower_bound(u - a[u]);
			for(auto it = itl; it != itr; it++) {
				int v = *it;
				dis[v + n] = dis[u] + 1;
				pre[v + n] = u;
				q.push(v + n);
			}
			s[1].erase(itl, itr);
		}
	}
	if(now == -1) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", ans + 1);
	vector<int> res;
	res.push_back(0);
	for(int i = now; i != 0; i = pre[i]) if(i > n) res.push_back(i - n);
	for(int i = sz(res) - 1; i >= 0; i--) printf("%d ", res[i]);
	printf("\n");
	return 0;
}