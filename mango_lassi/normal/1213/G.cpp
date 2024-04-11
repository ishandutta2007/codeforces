#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

class DJF {
	private:
		vector<int> rep, siz;

		int coll(int i) {
			if (rep[i] != i) rep[i] = coll(rep[i]);
			return rep[i];
		}
	public:
		ll cou = 0;

		DJF(int n) : rep(n), siz(n, 1) {
			for (int i = 0; i < n; ++i) rep[i] = i;
		}
		void join(int a, int b) {
			a = coll(a);
			b = coll(b);
			if (siz[a] < siz[b]) swap(a, b);
			cou += (ll)siz[a] * siz[b];
			siz[a] += siz[b];
			rep[b] = a;
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	DJF djf(n);

	vector<pair<int, pair<int, int>>> edges;
	for (int i = 0; i < n-1; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		edges.push_back({w, {a-1, b-1}});
	}
	sort(edges.begin(), edges.end());

	vector<pair<int, ll>> res(n);
	res[0] = {0, 0};
	for (int i = 0; i < n-1; ++i) {
		djf.join(edges[i].second.first, edges[i].second.second);
		res[i+1] = {edges[i].first, djf.cou};
	}

	for (int qi = 0; qi < q; ++qi) {
		int v;
		cin >> v;

		int low = 0;
		int high = n-1;
		while(low != high) {
			int mid = (low + high + 1) >> 1;
			if (res[mid].first <= v) low = mid;
			else high = mid - 1;
		}
		cout << res[low].second << ' ';
	}
	cout << '\n';
}