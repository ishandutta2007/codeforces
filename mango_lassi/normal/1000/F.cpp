#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const int N = 5 * (int)1e5;
const int Q = 5 * (int)1e5;

int best_next[4 * N];
int best_val[4 * N];
int h = 1;

bool active[N];
int next_val[N];
int next_el[N];
int val[N];

int ans[Q];

void update(int i) {
	int le = 2 * i;
	int ri = 2 * i + 1;
	if (best_next[le] < best_next[ri]) std::swap(le, ri);
	best_next[i] = best_next[le];
	best_val[i] = best_val[le];
}

void set(int i) {
	i += h;
	while(i > 1) {
		i >>= 1;
		update(i);
	}
}
std::pair<int, int> get(int a, int b, int ia = 0, int ib = h-1, int i = 1) {
	if (b < ia || ib < a) return {0, -1};
	if (a <=ia && ib<= b) return {best_next[i], best_val[i]};
	int mid = (ia + ib) >> 1;
	return std::max(get(a, b, ia, mid, 2*i), get(a, b, mid+1, ib, 2*i+1));
} 

int main() {
	int n;
	std::cin >> n;
	while(h < n) h <<= 1;

	for (int i = 0; i < n; ++i) {
		std::cin >> val[i];
		--val[i];
	}
	for (int i = n-1; i >= 0; --i) {
		if (next_val[val[i]] == 0) {
			next_el[i] = n;
		} else {
			next_el[i] = next_val[val[i]];
		}
		next_val[val[i]] = i;
		active[i] = true;
	}
	for (int i = 0; i < n; ++i) {
		if(active[i]) {
			best_next[i + h] = next_el[i];
		} else {
			best_next[i + h] = 0;
		}
		best_val[i + h] = val[i];
		if (next_el[i] != N) active[next_el[i]] = false;
	}

	for (int i = h-1; i > 0; --i) {
		update(i);
	}

	int q;
	std::cin >> q;
	std::vector<std::pair<std::pair<int, int>, int>> queries;
	for (int i = 0; i < q; ++i) {
		int a, b;
		std::cin >> a >> b;
		--a; --b;
		queries.push_back({{a, b}, i});
	}
	std::sort(queries.begin(), queries.end());
	int start = 0;
	for (int j = 0; j < queries.size(); ++j) {
		int a = queries[j].first.first;
		int b = queries[j].first.second;
		int i = queries[j].second;
		while(start < a) {
			active[start] = false;
			best_next[start + h] = 0;
			set(start);
			int ne = next_el[start];
			if (ne != N) {
				active[ne] = true;
				best_next[ne + h] = next_el[ne];
				set(ne);
			}
			++start;
		}

		/*
		std::cout << i << ' ' << a << ' ' << b << '\n';
		for (int x = 0; x < n; ++x) std::cout << active[x]; std::cout << '\n';
		for (int x = h; x < h+n; ++x) std::cout << best_next[x] << ' '; std::cout << '\n';
		*/
		std::pair<int, int> ret = get(a, b);
		// std::cout << "Query " << i << ": " << ret.first << ' ' << ret.second << '\n';
		if (ret.first > b) {
			ans[i] = ret.second + 1;
		} else {
			ans[i] = 0;
		}
	}
	for (int i = 0; i < q; ++i) std::cout << ans[i] << '\n';
}