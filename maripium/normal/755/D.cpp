#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

template<class T>
class fenwick {
	private:
		vector<int> fenw;
	public:
		fenwick(int n = 0) {
			fenw.assign(n + 1, 0);
		}
		void upd(int x,T v) {
			for (; x < fenw.size(); x += x & -x) {
				fenw[x] += v;
			}
		}
		T get(int x) {
			T ret = 0;
			for (; x > 0; x -= x & -x) {
				ret += fenw[x];
			}
			return ret;
		}
		T get(int l,int r) {
			if (l <= r) {
				return get(r) - get(l - 1);
			}
			else {
				return get(fenw.size() - 1) - get(l - 1) + get(r);
			}
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n, k; cin >> n >> k; k = min(k, n - k);
	fenwick<long long> fenw(n);
	int cur = 1;
	long long res = 1;
	for (int i = 1; i <= n; ++i) {
		int nxt = cur + k;
		if (nxt > n) nxt -= n;
		res += fenw.get(cur + 1, nxt - 1) + 1;
		cout << res << ' ';
		fenw.upd(cur, 1), fenw.upd(nxt, 1);
		cur = nxt;
	}
}