#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)


struct w {
	unordered_set <int> s;
	int tag;
	w () {tag = rand();}
	bool count (int x) {
		return s.count(x ^ tag);
	}
	bool merge (w & other, int rtv) {
		other.tag ^= rtv;
		if (s.size() < other.s.size()) {
			s.swap(other.s);
			swap(tag, other.tag);
		}
		for (auto i : other.s) {
			if (s.count(i ^ other.tag ^ tag ^ rtv)) {
				return 1;
			}
		}
		for (auto i : other.s) {
			s.insert (i ^ other.tag ^ tag);
		}
		other.s.clear();
		return 0;
	}
	void clear() {s.clear();}
};
const int N = 2e5 + 5;
int n, ans;
int a[N];
vector <int> E[N];
w s[N];


void dfs (int x, int fa) {
	bool bad = 0;
	for (auto v : E[x]) if (v != fa) {
		dfs (v, x);
		if (s[x].merge(s[v], a[x])) {
			bad = 1;
		}
	}
	if (s[x].count(a[x]) || s[x].count(0)) bad = 1;
	else {
		s[x].s.insert(a[x] ^ s[x].tag);
	}
	if (bad) {
		s[x].clear();
		ans ++;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i < n; i++) {
		int u, v;
		read(u); read(v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1, -1);
	printf("%d\n", ans);
}