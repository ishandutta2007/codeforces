#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
#define pii pair<int, int>
#define eb emplace_back
using namespace std;
typedef double db;
typedef long long i64;
typedef unsigned u32;
const int N = 1e5 + 10; 
int n, q, f[N], son[N], vis[N], done[N], used[N];
i64 t[N], d[N];
multiset<i64> s[N], mx, mn;

void del(int u) {
	if(!s[u].empty() && vis[u]) {
		mx.erase(mx.find(t[u] / (son[u] + 2) + *(s[u].rbegin())));
		mn.erase(mn.find(t[u] / (son[u] + 2) + *(s[u].begin()))); 
	}
	vis[u] = 0;
	return;
}

void add(int u) {
	if(!s[u].empty() && !vis[u]) {
		mx.insert(t[u] / (son[u] + 2) + *(s[u].rbegin()));
		mn.insert(t[u] / (son[u] + 2) + *(s[u].begin()));
	}
	vis[u] = 1;
	return;
}

void ins(int u) {
	if(used[u]) return;
	s[f[u]].insert(d[u]), used[u] = 1;
}

void era(int u) {
	if(!used[u]) return;
	s[f[u]].erase(s[f[u]].find(d[u])), used[u] = 0;
} 

void Del(int u) {
	if(!done[u]) return;
	d[f[u]] -= t[u] / (son[u] + 2);
	d[u] -= t[u] - t[u] / (son[u] + 2) * (son[u] + 1);
	done[u] = 0;
	return;
}

void Add(int u) {
	if(done[u]) return;
	d[u] += t[u] - t[u] / (son[u] + 2) * (son[u] + 1);
	d[f[u]] += t[u] / (son[u] + 2);
	done[u] = 1;
	return;
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &t[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &f[i]);
		son[f[i]]++;
	}
	for(int i = 1; i <= n; i++) Add(i);
	for(int i = 1; i <= n; i++) ins(i);
	for(int i = 1; i <= n; i++) add(i);
	for(int i = 1; i <= q; i++) {
		int opt, u, v;
		scanf("%d", &opt);
		if(opt == 1) {
			scanf("%d%d", &u, &v);
			int w = f[u];
			del(w), del(v), del(f[w]), del(f[v]), del(f[f[w]]), del(f[f[v]]);
			era(w), era(v), era(f[w]), era(f[v]), era(f[f[w]]), era(f[f[v]]), era(u);
			Del(f[v]), Del(f[w]), Del(v), Del(w), Del(u);
			son[w]--;
			f[u] = v;
			son[v]++;
			Add(u), Add(w), Add(v), Add(f[w]), Add(f[v]);
			ins(w), ins(v), ins(f[w]), ins(f[v]), ins(f[f[w]]), ins(f[f[v]]), ins(u);
			add(w), add(v), add(f[w]), add(f[v]), add(f[f[w]]), add(f[f[v]]);
		} else if(opt == 2) {
			scanf("%d", &u);
			printf("%lld\n", d[u] + t[f[u]] / (son[f[u]] + 2));
		} else {
			printf("%lld %lld\n", *mn.begin(), *(--mx.end())); 
		}
	}
	return 0;
}