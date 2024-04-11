#include <iostream>
#include <vector>
#include <bitset>
#include <set>
#include <tuple>
using namespace std;

const int M = 2000;
const int N = 2000;

bool works(const bitset<M>& a, const bitset<M>& b) {
	return abs((int)(a.count() - b.count())) < (a ^ b).count();
}
pair<int, int> get(const bitset<M>& a, const bitset<M>& b) {
	bitset<M> x = a & (~b);
	bitset<M> y = (~a) & b;
	return {x._Find_first(), y._Find_first()};
}

bitset<M> prefs[M+1];
bitset<M> bts[N];
set<pair<int, int>> act;
vector<pair<int, int>> valid;

void remove(int i) {
	int cou = bts[i].count();
	pair<int, int> ap = {cou, i};
	act.erase(ap);

	auto it = act.lower_bound(ap);
	int x = -1, y = -1;
	if (it != act.end()) x = (*it).second;
	if (it != act.begin()) {
		--it;
		y = (*it).second;
	}
	if (x != -1 && y != -1) {
		if (works(bts[x], bts[y])) valid.push_back({x, y});
	}
}
void add(int i) {
	int cou = bts[i].count();
	pair<int, int> ap = {cou, i};

	auto it = act.lower_bound(ap);
	if (it != act.end()) {
		int j = (*it).second;
		if (works(bts[i], bts[j])) valid.push_back({i, j});
	}
	if (it != act.begin()) {
		--it;
		int j = (*it).second;
		if (works(bts[i], bts[j])) valid.push_back({i, j});
	}

	act.insert(ap);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// n: number of bitsets
	// m: number of bits in each set
	int n, m, q;
	cin >> n >> m >> q;

	for (int i = 1; i <= m; ++i) {
		prefs[i] = prefs[i-1];
		prefs[i][i-1] = 1;
	}
	for (int i = 0; i < n; ++i) add(i);

	// Two bitstrings form a rectangle iff neither is a subset of the other
	// How to maintain whether this property holds?
	// Sort bitstrings by size. it is enough to compare back-to-back ones.
	for (int qi = 0; qi < q; ++qi) {
		int i, l, r;
		cin >> i >> l >> r;
		
		remove(i-1);
		bts[i-1] ^= prefs[r] ^ prefs[l-1];
		add(i-1);

		bool found = false;
		while(!found && !valid.empty()) {
			int x1, x2;
			tie(x1, x2) = valid.back();

			if (works(bts[x1], bts[x2])) {
				int y1, y2;
				tie(y1, y2) = get(bts[x1], bts[x2]);
				if (x1 > x2) swap(x1, x2);
				if (y1 > y2) swap(y1, y2);
				found = true;

				cout << x1+1 << ' ' << y1+1 << ' ' << x2+1 << ' ' << y2+1 << '\n';
			} else {
				valid.pop_back();
			}
		}
		if (! found) cout << "-1\n";
	}
}