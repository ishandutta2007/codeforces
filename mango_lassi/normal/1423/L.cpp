#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 1000;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}
template<class T>
T rand() {
	return uniform_int_distribution<T>()(rng);
}

const int M = 1000;
const int N = 64;
bitset<M> masks[N];

void init() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (rand(0, 1)) masks[i][j] = 1;
		}
	}
}

ull mapBitset(bitset<M> b) {
	ull res = 0;
	for (int i = 0; i < N; ++i) {
		if ((b & masks[i]).count() & 1) res |= (1ull << i);
	}
	return res;
}
ull readBits() {
	bitset<M> bits;
	int k;
	cin >> k;
	for (int j = 0; j < k; ++j) {
		int x;
		cin >> x;
		bits[x-1] = 1;
	}
	return mapBitset(bits);
}

template<class T>
int search(const vector<pair<T, int>>& vec, T tar) {
	int low = 0;
	int high = vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid].first >= tar) high = mid;
		else low = mid + 1;
	}
	return (low < vec.size() && vec[low].first == tar ? vec[low].second : INF);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	init();

	int n, m, q;
	cin >> n >> m >> q;

	int as = (2*m / 3);
	int bs = m - as;
	vector<ull> vecs1(as), vecs2(bs);

	for (int i = 0; i < m; ++i) {
		ull res = readBits();
		if (i < as) vecs1[i] = res;
		else vecs2[i - as] = res;
	}
	
	
	vector<pair<ull, int>> offs;
	for (int h = 0; h < (1 << as); ++h) {
		ull cur = 0;
		int cou = 0;
		for (int j = 0; j < as; ++j) {
			if (h & (1 << j)) {
				cur ^= vecs1[j];
				++cou;
			}
		}
		offs.push_back({cur, cou});
	}
	sort(offs.begin(), offs.end());

	for (int i = 1; i < offs.size(); ++i) {
		if (offs[i].first == offs[i-1].first) offs[i].second = offs[i-1].second;
	}
	offs.erase(unique(offs.begin(), offs.end()), offs.end());

	for (int qi = 0; qi < q; ++qi) {
		auto base = readBits();
		int res = m + 1;
		for (int h = 0; h < (1 << bs); ++h) {
			auto cur = base;
			int cou = 0;
			for (int j = 0; j < bs; ++j) {
				if (h & (1 << j)) {
					cur ^= vecs2[j];
					++cou;
				}
			}
			res = min(res, cou + search(offs, cur));
		}
		if (res > m) res = -1;
		cout << res << '\n';
	}
}