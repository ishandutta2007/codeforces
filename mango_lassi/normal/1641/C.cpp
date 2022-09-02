#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

// van Emde Boas tree. Maintains a set of integers in range [0, 2^B) and supports operations
//	findNext(i): returns minimum j >= i in set, or 2^B if none exist
// 	findPrev(i): returns maximum j <= i in set, or -1 if none exist
//	insert(i), erase(i): insert/erase i into the set
//	empty(): returns TRUE if the set is empty
//	clear(): empties the set
//	init(bts): inits the set, after the call i will be in the set if bts[i] = 1. bts should be a bitset, but can be a vector of 0/1
// All operations except empty, clear and init are O(log B) = O(log log 2^B) with good constants
template<int B, typename ENABLE = void>
class VEBTree {
	private:
		const static int K = B / 2, R = (B + 1) / 2, M = (1 << B);
		const static int S = 1 << K, MASK = (1 << R) - 1;
		array<VEBTree<R>, S> ch;
		VEBTree<K> act;
		int mi, ma;
	public:
		bool empty() const { return ma < mi; }
		
		int findNext(int i) const {
			if (i <= mi) return mi;
			if (i > ma) return M;
			
			int j = i >> R, x = i & MASK;
			int res = ch[j].findNext(x);
			if (res <= MASK) return (j << R) + res;
			
			j = act.findNext(j + 1);
			return (j >= S) ? ma : ((j << R) + ch[j].findNext(0));
		}
		int findPrev(int i) const {
			if (i >= ma) return ma;
			if (i < mi) return -1;
			
			int j = i >> R, x = i & MASK;
			int res = ch[j].findPrev(x);
			if (res >= 0) return (j << R) + res;
			
			j = act.findPrev(j - 1);
			return (j < 0) ? mi : ((j << R) + ch[j].findPrev(MASK));
		}
		void insert(int i) {
			if (i <= mi) {
				if (i == mi) return;
				swap(mi, i);
				if (i == M) ma = mi; // we were empty
				if (i >= ma) return; // we had mi == ma
			} else if (i >= ma) {
				if (i == ma) return;
				swap(ma, i);
				if (i <= mi) return; // we had mi == ma
			}
			int j = i >> R;
			if (ch[j].empty()) act.insert(j);
			ch[j].insert(i & MASK);
		}
		void erase(int i) {
			if (i <= mi) {
				if (i < mi) return;
				i = mi = findNext(mi + 1);
				if (i >= ma) {
					if (i > ma) ma = -1; // we had mi == ma
					return; // after erase we have mi == ma
				}
			} else if (i >= ma) {
				if (i > ma) return;
				i = ma = findPrev(ma - 1);
				if (i <= mi) return; // after erase we have mi == ma
			}
			int j = i >> R;
			ch[j].erase(i & MASK);
			if (ch[j].empty()) act.erase(j);
		}

		void clear() {
			mi = M, ma = -1;
			act.clear();
			for (int i = 0; i < S; ++i) ch[i].clear();
		}
		template<class T>
		void init(const T& bts, int shift = 0, int s0 = 0, int s1 = 0) {
			while(s0 + s1 < M && !bts[shift + s0]) ++s0;
			while(s0 + s1 < M && !bts[shift + M-1 - s1]) ++s1;
			if (s0 + s1 >= M) clear();
			else {
				act.clear();
				mi = s0, ma = M-1 - s1;
				++s0; ++s1;
				for (int j = 0; j < S; ++j) {
					ch[j].init(bts, shift + (j << R), max(0, s0 - (j << R)), max(0, s1 - ((S-1-j) << R)));
					if (! ch[j].empty()) act.insert(j);
				}
			}
		}
};
template<int B>
class VEBTree<B, enable_if_t<(B <= 6)>> {
	private:
		const static int M = (1 << B);
		ull act;
	public:
		bool empty() const { return !act; }
		void clear() { act = 0; }

		int findNext(int i) const {
			return ((i < M) && (act >> i)) ? i + __builtin_ctzll(act >> i) : M;
		}
		int findPrev(int i) const {
			return ((i != -1) && (act << (63 - i))) ? i - __builtin_clzll(act << (63 - i)) : -1;
		}
		void insert(int i) { act |= 1ull << i; }
		void erase(int i) { act &= ~(1ull << i); }
		
		template<class T>
		void init(const T& bts, int shift = 0, int s0 = 0, int s1 = 0) {
			act = 0;
			for (int i = s0; i + s1 < M; ++i) act |= ((ull)bts[shift + i]) << i;
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<pair<int, int>> qs;
	vector<pair<int, pair<int, int>>> zeros;
	vector<pair<pair<int, pair<int, int>>, pair<int, int>>> ones;
	for (int qi = 0; qi < q; ++qi) {
		int t;
		cin >> t;
		if (t == 0) {
			int a, b, x;
			cin >> a >> b >> x;
			--a; --b;

			if (x == 0) zeros.emplace_back(qi, make_pair(a, b));
			else ones.emplace_back(make_pair(-1, make_pair(qi, q)), make_pair(a, b));
		} else {
			int i;
			cin >> i;
			--i;

			qs.emplace_back(qi, i);
		}
	}

	// Parallel BS
	bitset<(1 << 18)> one_bits;
	for (int i = 0; i < n; ++i) one_bits[i] = 1;

	for (int it = 0; it < 20; ++it) {
		for (int i = 0; i < ones.size(); ++i) {
			int ia = ones[i].first.second.first;
			int ib = ones[i].first.second.second;
			ones[i].first.first = (ia + ib) >> 1;
		}
		sort(ones.begin(), ones.end());

		VEBTree<18> act;
		act.init(one_bits);

		for (int qi = 0, zi = 0, oi = 0; qi < q; ++qi) {
			if (zi < zeros.size() && zeros[zi].first == qi) {
				int ia = zeros[zi].second.first;
				int ib = zeros[zi].second.second;
				for (int i = act.findNext(ia); i <= ib; i = act.findNext(i + 1)) act.erase(i);
				++zi;
			}
			for (; oi < ones.size() && ones[oi].first.first == qi; ++oi) {
				int ia = ones[oi].second.first;
				int ib = ones[oi].second.second;
				
				int cou = 0;
				for (int i = act.findNext(ia); i <= ib && cou < 2; i = act.findNext(i + 1)) ++cou;
				
				if (cou <= 1) ones[oi].first.second.second = qi;
				else ones[oi].first.second.first = qi + 1;
			}
		}
	}
	for (int i = 0; i < ones.size(); ++i) {
		int ia = ones[i].first.second.first;
		int ib = ones[i].first.second.second;
		ones[i].first.first = (ia + ib) >> 1;
	}
	sort(ones.begin(), ones.end());

	// Answer queries
	VEBTree<18> act;
	act.init(one_bits);
	vector<int> state(n, 0);

	for (int qi = 0, zi = 0, oi = 0, ai = 0; qi < q; ++qi) {
		if (ai < qs.size() && qs[ai].first == qi) {
			int i = qs[ai].second;
			if (state[i] == 1) {
				cout << "NO\n";
			} else if (state[i] == -1) {
				cout << "YES\n";
			} else {
				cout << "N/A\n";
			}
			++ai;
		}
		if (zi < zeros.size() && zeros[zi].first == qi) {
			int ia = zeros[zi].second.first;
			int ib = zeros[zi].second.second;
			for (int i = act.findNext(ia); i <= ib; i = act.findNext(i)) {
				act.erase(i);
				state[i] = 1;
			}
			++zi;
		}
		for (; oi < ones.size() && ones[oi].first.first == qi; ++oi) {
			int ia = ones[oi].second.first;
			int ib = ones[oi].second.second;
			for (int i = act.findNext(ia); i <= ib; i = act.findNext(i)) {
				act.erase(i);
				state[i] = -1;
			}
		}
	}
}