#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
const int INF = (int)1e9 + 7;

class DSU {
	private:
		vector<int> comp, siz;
		vector<int> tp; // on or off
		vector<int> onc, offc; // on count, off count
	public:
		DSU(int n) : comp(n), siz(n, 1), tp(n, 0), onc(n, 0), offc(n, 1) {
			for (int i = 0; i < n; ++i) comp[i] = i;
			offc[n-1] = INF;
		}
		pair<int, int> getc(int i) {
			if (comp[i] != i) {
				auto sub = getc(comp[i]);
				comp[i] = sub.first;
				tp[i] ^= sub.second;
			}
			return {comp[i], tp[i]};
		}
		int join(int a, int b, int t) {
			int at, bt;
			tie(a, at) = getc(a);
			tie(b, bt) = getc(b);
			t ^= at ^ bt;

			if (a == b) return 0;
			if (siz[a] < siz[b]) {
				swap(a, b);
				swap(at, bt);
			}

			int add = -(min(onc[a], offc[a]) + min(onc[b], offc[b]));
			
			siz[a] += siz[b];
			comp[b] = a;
			tp[b] = t;

			if (tp[b]) {
				onc[a] += offc[b];
				offc[a] += onc[b];
			} else {
				onc[a] += onc[b];
				offc[a] += offc[b];
			}

			add += min(onc[a], offc[a]);

			return add;
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> lamps(n, {k, k});

	string str;
	cin >> str;
	for (int j = 0; j < k; ++j) {
		int c;
		cin >> c;
		for (int i = 0; i < c; ++i) {
			int x;
			cin >> x;
			--x;
			if (lamps[x].first == k) lamps[x].first = j;
			else if (lamps[x].second == k) lamps[x].second = j;
		}
	}

	DSU dsu(k+1);

	int res = 0;
	for (int i = 0; i < n; ++i) {
		// Add condition of lamp i
		res += dsu.join(lamps[i].first, lamps[i].second, str[i] == '0');
		cout << res << '\n';
	}
}