#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define i64 long long
#define cnt(x) int(__builtin_popcountll(x))
using namespace std;
const int N = 10;
int n, k;
i64 x[N];

void dfs(int now, i64 msk, i64 sub) {
	if(now == k) {
		int t = cnt(msk);
		if((msk >> (n - t)) != ((1ll << t) - 1)) {
			cout << "REJECTED" << endl, exit(0);
		}
		return;
	}
	i64 other = (x[now] & sub) ^ x[now];
	int tot = cnt(~msk & sub & x[now]);
	sub ^= other;
	vector<i64> pos;
	pos.reserve(cnt(x[now]));
	for(i64 i = x[now], j = 0; i; i -= i & (-i), j++) {
		i64 t = i & (-i);
		if(j < tot) msk &= ~t;
		else msk |= t;
		pos.push_back(t);
	}
	int del = cnt(other);
	for(int i = tot; i < tot + del; i++) {
		dfs(now + 1, msk, sub);
		msk ^= pos[i];
	}
	dfs(now + 1, msk, sub);
	return;
}

int main() {
	cin >> n >> k;
	i64 all = 0;
	for(int i = 0; i < k; i++) {
		int m;
		cin >> m;
		for(int j = 0; j < m; j++) {
			int p;
			cin >> p;
			x[i] |= 1ll << (p - 1);
		}
		all |= x[i];
	}
	if(n == 1) {
		cout << "ACCEPTED" << endl;
		exit(0);
	}
	if(all != (1ll << n) - 1) cout << "REJECTED" << endl, exit(0);
	dfs(0, 0, 0);
	cout << "ACCEPTED" << endl;
	return 0;
}