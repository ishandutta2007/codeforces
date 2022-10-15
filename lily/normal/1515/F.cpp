#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)

const int N = 3e5 + 5;

int n, m, X;
vector < pair<int, int> > E[N];
int a[N], f[N];
int getf(int x) {
	return f[x] == x? x : (f[x] = getf(f[x]));
}
LL V[N];

int main() {
	read(n); read(m); read(X);
	//n = 3e5, m = n - 1, X = 1;
	LL sum = 0;
	for (int i = 1; i <= n; i++) read(a[i]), sum += a[i]; //a[i] = i % 3 == 0 ? 2 + (rand() & 3) : 0,  sum += a[i];
	if (X * 1ll * (n - 1) > sum) return puts("NO"), 0;
	for (int i = 1; i <= m; i++) {
		int u, v;
		read(u); read(v);
		//u = i, v = i + 1;
		E[u].push_back({v, i});
		E[v].push_back({u, i});
	}
	puts("YES");
	priority_queue < pair<LL, int> > q;
	for (int i = 1; i <= n; i++) {
		f[i] = i;
		V[i] = a[i];
		q.push({V[i], i});
	}
	int cnt = 1;
	while (cnt < n) {
		assert (!q.empty());
		auto o = q.top(); q.pop();
		LL vn = o.first; int x = o.second;
		if (V[x] != vn || f[x] != x) continue; 
		int maked = 0;
		while (E[x].size()) {
			auto c = E[x].back();
			c.first = getf(c.first);
			if (x == c.first)
				E[x].pop_back();
			else if (V[c.first] + V[x] >= X) {
				V[x] += V[c.first] - X;
				f[c.first] = x;
				printf("%d\n", c.second);
				cnt++;
				maked++;
				E[x].pop_back();
				if (E[x].size() > E[c.first].size());
				else E[x].swap(E[c.first]);
				for (auto v : E[c.first]) E[x].push_back(v);
				E[c.first].clear();
			} else {
				assert (maked);
				break;
			}
		}
		q.push({V[x], x});
	}
	
}