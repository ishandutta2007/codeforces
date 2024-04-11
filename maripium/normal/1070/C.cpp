#include <bits/stdc++.h>
using namespace std;

template<class T>
class fenwick {
	private:
		vector<T> fw;
	public:
		fenwick(int n = 0) {
			fw.assign(n + 5, T(0));
		}
		void upd(int p,T x) {
			for (; p < fw.size(); p += p & -p) fw[p] += x; 
		}
		T get(int p) {
			T ret = T(0);
			for (; p > 0; p -= p & -p) ret += fw[p];
			return ret;
		}
		int find(T sum) {
			T cursum = T();
			int curpos = 0;
			for (int i = 19; i >= 0; --i) {
				if (cursum + fw[curpos + (1 << i)] <= sum) {
					curpos += (1 << i);
					cursum += fw[curpos];
				}
			} 
			return curpos;
		}
};

struct event {
	int price, cores, type;
};

const int N = 1000005;

int n, m; 
long long k;
vector<event> E[N];
fenwick<long long> fw0(1 << 20);
fenwick<long long> fw1(1 << 20);

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> m;
	while (m--) {
		int l, r, cores, price; cin >> l >> r >> cores >> price;
		E[l].push_back({price, cores, 1});
		E[r + 1].push_back({price, cores, -1});
	}
	long long res = 0;
	for (int i = 1; i <= n; ++i) {
		for (auto e : E[i]) {
			fw0.upd(e.price, 1LL * e.type * e.cores);
			fw1.upd(e.price, 1LL * e.type * 1LL * e.price * e.cores);
		}
		int x = fw0.find(1LL * k);
		res += fw1.get(x);
		if (x + 1 < (1 << 20)) {
			long long rem = min(k, fw0.get(x + 1)) - fw0.get(x);
			res += rem * (x + 1);
		}
	}
	cout << res << '\n';
}