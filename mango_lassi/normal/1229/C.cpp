#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
vector<int> mores[N];
vector<int> conns[N];

ll cont(int i) {
	return ((ll)conns[i].size() - (ll)mores[i].size()) * (ll)mores[i].size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
		mores[min(a, b)].push_back(max(a, b));
	}
	ll res = 0;
	for (int i = 0; i < n; ++i) res += cont(i);
	cout << res << '\n';

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int i;
		cin >> i;
		--i;
		for (auto t : mores[i]) {
			res -= cont(t);
			mores[t].push_back(i);
			res += cont(t);
		}
		res -= cont(i);
		mores[i].clear();
		mores[i].shrink_to_fit();

		cout << res << '\n';
	}
}