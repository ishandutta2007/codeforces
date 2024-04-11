#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1000;
vector<int> conns[N];
bool ban[N];

pair<int, int> far(int i, int p) {
	pair<int, int> res = {0, i};
	for (auto t : conns[i]) {
		if (t == p || ban[t]) continue;
		auto sub = far(t, i);
		++sub.first;
		res = max(res, sub);
	}
	return res;
}
int apply(int i, int x) {
	if (i == x || ban[i]) return 0;
	ban[i] = 1;
	int res = 1;
	for (auto t : conns[i]) res += apply(t, x);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	// Ask the two furthest away nodes,
	// then root is in some other subtree of the answer
	int cur = 0;
	while(n > 1) {
		int a = far(cur, -1).second;
		int b = far(a, -1).second;
		cout << "? " << a+1 << ' ' << b+1 << endl;
		cin >> cur;
		--cur;

		n -= apply(a, cur);
		n -= apply(b, cur);
	}
	cout << "! " << cur+1 << '\n';
}