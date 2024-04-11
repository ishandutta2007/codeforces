#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <utility>
const int N = 1e4;

int h = 1;
std::bitset<N + 1> ans;
std::vector<int> adds [4 * N];

void addQue(int s, int e, int x, int ia = 0, int ib = h - 1, int i = 1) {
	if (e < ia || ib < s) return;
	if (s <=ia && ib<= e) {
		adds[i].push_back(x);
		return;
	} else {
		int mid = (ia + ib) >> 1;
		addQue(s, e, x, ia, mid, 2 * i);
		addQue(s, e, x, mid + 1, ib, 2 * i + 1);
	}
}
void dfs(std::bitset<N + 1> bits, int i = 1) {
	if (adds[i].size() > 0) {
		for (auto v : adds[i]) {
			bits = bits | (bits << v);
		}
	}
	if (i >= h) {
		ans |= bits;
	} else {
		dfs(bits, 2 * i);
		dfs(bits, 2 * i + 1);
	}
}

int main() {
	int n, q;
	std::cin >> n >> q;
	while(h < n) h <<= 1;	

	for (int i = 0; i < q; ++i) {
		int l, r, x;
		std::cin >> l >> r >> x;
		--l; --r;
		addQue(l, r, x);
	}

	std::bitset<N + 1> tmp;
	for (int i = 0; i <= n; ++i) {
		tmp[i] = 0;
		ans[i] = 0;
	}
	tmp[0] = 1;
	dfs(tmp);

	std::vector<int> res;
	for (int i = 1; i <= n; ++i) {
		if (ans[i] == 1) res.push_back(i);
	}
	std::cout << res.size() << '\n';
	for (auto it : res) std::cout << it << ' '; std::cout << '\n';
}