#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a);

const int N = 2e5 + 5;

int p[N], s[N];
vector <int> E[N];

pair <LL, LL> dfs (int x, int K) {
	int son = (int) E[x].size();
	if (son == 0) return {s[x] * 1ll * K, s[x]};
	int each = K / son, left = K % son;
	LL ret = 0;
	vector <LL> w;
	for (auto v : E[x]) {
		auto r = dfs (v, each);
		ret += r.first;
		w.push_back(r.second);
	}
	sort(w.begin(), w.end(), greater <LL> ());
	for (int i = 0; i < left; i++) ret += w[i];
	return {ret + s[x] * 1ll * K, w[left] + s[x]};
}
int n, K;
void work () {
	read(n); read(K);
	for (int i = 1; i <= n; i++) E[i].clear();
	for (int i = 2; i <= n; i++) {
		read(p[i]);
		E[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) read(s[i]);
	printf("%lld\n", dfs (1, K).first);
}

int main() {
	int T;
	read(T);
	while (T--) work();
}