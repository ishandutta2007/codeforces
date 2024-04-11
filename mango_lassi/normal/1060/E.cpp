#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 3 * (int)1e5;
vector<int> conns[N];
ll siz[N];
ll odds[N];

ll solve(int i, int p, int n) {
	ll res = 0;
	siz[i] = 1;
	odds[i] = 1;
	for (auto t : conns[i]) {
		if (t == p) continue;

		res += solve(t, i, n);
		res += (n - siz[t]) * siz[t]; // Amount of paths over this edge
		res += odds[i] * odds[t] + (siz[i] - odds[i]) * (siz[t] - odds[t]); // Amount of odd paths over this subtree
		odds[i] += siz[t] - odds[t];
		siz[i] += siz[t];
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	// We just divide the length of any path by two, rounding up.
	// Answer is:
	// SUM-LEN / 2 + ODD-PATH-COU / 2

	ll res = solve(0, 0, n) / 2;
	cout << res << '\n';
}