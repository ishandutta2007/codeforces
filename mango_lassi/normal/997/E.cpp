#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <assert.h>

const int N = 1<<17;
const int INF = 1e7;
typedef long long ll;

// I think I did this the sameway fjzz2002 did it, see his explanation at
// https://codeforces.com/blog/entry/60357?#comment-441928

// Each node X stores 3 values, MAX, MIN and ADD. F(X) = MAX - MIN - ADD.
std::pair<int, ll> max_max[2*N]; // max MAX in interval, count
std::pair<int, ll> min_min[2*N]; // min MIN in interval, count
int max_min[2*N]; // max MIN in interval
int min_max[2*N]; // min MAX in interval
std::pair<int, ll> min_f[2*N]; // min function value in interval, count
std::pair<int, ll> min_h[2*N]; // min function value in interval over entire history, count

int add_v[2*N]; // Val to add to sum
int add_m[2*N]; // Minimum value the add has had
int add_c[2*N]; // How long has the add-value been its minimum value in history

int s_max[2*N]; // What the MAX value for all nodes in this node's subtree should be set to
int s_min[2*N]; // What the MIN value for all nodes in this node's subtree should be set to
int value[N];

// Advance a time step. Used for historic values.
inline void advanceStep() {
	if (add_v[1] == add_m[1]) ++add_c[1];
}

// Push changes down the tree
void push(int i, int ia, int ib) {
	int left = 2 * i;
	int right = 2 * i + 1;

	// Set max
	int v = s_max[i];
	if (v != -1) {
		max_max[i].first = v;
		min_max[i] = v;
		if (i < N) {
			s_max[left] = v;
			s_max[right] = v;
		}
		s_max[i] = -1;
	}

	// Set min
	v = s_min[i];
	if (v != -1) {
		min_min[i].first = v;
		max_min[i] = v;
		if (i < N) {
			s_min[left] = v;
			s_min[right] = v;
		}
		s_min[i] = -1;
	}
	
	// Add
	if (add_v[i] != 0 || add_m[i] != 0 || add_c[i] != 0) {
		// std::cout << "push [" << ia << "," << ib << "]: add_v[i]=" << add_v[i] << ", add_m[i]=" << add_m[i] << ", add_c[i]=" << add_c[i] << ", min_f[i]={" << min_f[i].first << "," << min_f[i].second << "}, min_h[i]={" << min_h[i].first << "," << min_h[i].second << "}\n";
		// Update history minimum
		int offer = min_f[i].first + add_m[i];
		ll cou = (ll)add_c[i] * min_f[i].second;
		if (offer < min_h[i].first) {
			min_h[i] = {offer, cou};
		} else if (offer == min_h[i].first) {
			min_h[i].second += cou;
		}
		// Update current value
		min_f[i].first += add_v[i];
		// Push to children
		if (i < N) {
			for (auto t : {left, right}) {
				// Push history minimum add
				offer = add_v[t] + add_m[i];
				if (offer < add_m[t]) {
					add_m[t] = offer;
					add_c[t] = add_c[i];
				} else if (offer == add_m[t]) {
					add_c[t] += add_c[i];
				}
				// Push current add
				add_v[t] += add_v[i];
			}
		}
		// Clear
		add_v[i] = 0;
		add_m[i] = 0;
		add_c[i] = 0;
		// std::cout << "\t--> min_f[i]={" << min_f[i].first << "," << min_f[i].second << "}, min_h[i]={" << min_h[i].first << "," << min_h[i].second << "}\n";
	}
}

std::pair<int, ll> combine(std::pair<int, ll> a, std::pair<int, ll> b, bool larger) {
	if (a.first == b.first) return {a.first, a.second + b.second};
	if (larger) return std::max(a, b);
	else return std::min(a, b);
}

// Update the values stored in the current node
void update(int i) {
	assert(i < N);
	int left = 2 * i;
	int right = 2 * i + 1;
	
	max_max[i] = combine(max_max[left], max_max[right], true);
	max_min[i] = std::max(max_min[left], max_min[right]);
	
	min_min[i] = combine(min_min[left], min_min[right], false);
	min_max[i] = std::min(min_max[left], min_max[right]);
	
	min_f[i] = combine(min_f[left], min_f[right], false);
	min_h[i] = combine(min_h[left], min_h[right], false);
}

// Add a value to all indices in the interval
void addInt(int a, int b, int v, int ia = 0, int ib = N-1, int i = 1) {
	// std::cout << "addInt(" << a << ' ' << b << ' ' << v << ' ' << ia << ' ' << ib << ")\n";
	if (b < ia || ib < a) {
		push(i,ia,ib);
		return;
	}
	if (a<= ia && ib <=b) {
		// std::cout << "add " << v << " to [" << ia << "," << ib << "]\n";
		add_v[i] += v;
		if (add_m[i] > add_v[i]) {
			add_m[i] = add_v[i];
			add_c[i] = 0;
		}
		push(i,ia,ib);
		// std::cout << "value: " << min_f[i].first << '\n';
	} else {
		push(i,ia,ib);
		int mid = (ia + ib) >> 1;
		addInt(a, b, v, ia, mid, 2*i);
		addInt(a, b, v, mid+1, ib, 2*i+1);
		update(i);
	}
}

// Set MAX element for all values in [a...b] to max(current MAX, v)
void setIntMax(int a, int b, int v, int ia = 0, int ib = N-1, int i = 1) {
	// std::cout << "setIntMax(" << a << ' ' << b << ' ' << v << ' ' << ia << ' ' << ib << "):\n";
	// std::cout << "\tmin_max[i]: " << min_max[i] << " max_max[i].first: " << max_max[i].first << '\n';
	if (b < ia || ib < a || min_max[i]  >= v) {
		push(i,ia,ib);
		return;
	}
	if (a<= ia && ib <=b && min_max[i] == max_max[i].first) {
		// std::cout << "set MAX " << v << " to [" << ia << "," << ib << "]\n";
		s_max[i] = v;
		addInt(a, b, (v - max_max[i].first), ia, ib, i);
	} else {
		push(i,ia,ib);	
		int mid = (ia + ib) >> 1;
		setIntMax(a, b, v, ia, mid, 2*i);
		setIntMax(a, b, v, mid+1, ib, 2*i+1);
		update(i);
	}
}

// Set MIN element for all values in [a...b] to max(current MIN, v)
void setIntMin(int a, int b, int v, int ia = 0, int ib = N-1, int i = 1) {
	// std::cout << "setIntMin(" << a << ' ' << b << ' ' << v << ' ' << ia << ' ' << ib << "):\n";
	// std::cout << "\tmax_min[i]: " << max_min[i] << " min_min[i].first: " << min_min[i].first << '\n';
	if (b < ia || ib < a || max_min[i]  <= v) {
		push(i,ia,ib);
		return;
	}
	if (a<= ia && ib <=b && max_min[i] == min_min[i].first) {
		// std::cout << "set MIN " << v << " to [" << ia << "," << ib << "]\n";
		s_min[i] = v;
		addInt(a, b, -(v - min_min[i].first), ia, ib, i);
	} else {
		push(i,ia,ib);	
		int mid = (ia + ib) >> 1;
		setIntMin(a, b, v, ia, mid, 2*i);
		setIntMin(a, b, v, mid+1, ib, 2*i+1);
		update(i);
	}
}

// Say k time steps have advanced. Among all n*k F(X) values the array has had,
// returns the minimum, and how many of those F(X) values are equal to the minimum.
std::pair<int, ll> getHist(int a, int b, int ia = 0, int ib = N-1, int i = 1) {
	// std::cout << "getHist(" << a << ' ' << b << ' ' << ia << ' ' << ib << ' ' << i << "):\n";
	push(i,ia,ib);
	if (b < ia || ib < a) return {INF, (ll)0};
	if (a<= ia && ib <=b) {
		// std::cout << "found {" << min_h[i].first << "," << min_h[i].second << "}\n";
		return min_h[i];
	}
	int mid = (ia + ib) >> 1;
	auto lr = getHist(a, b, ia, mid, 2*i);
	auto rr = getHist(a, b, mid+1, ib, 2*i+1);
	return combine(lr, rr, false);
}

int main() {
	// Take input
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> value[i];
	}
	
	int q;
	std::cin >> q;
	std::vector<std::pair<std::pair<int, int>, int>> queries (q);
	std::vector<ll> answers (q);
	for (int i = 0; i < q; ++i) {
		int a, b;
		std::cin >> a >> b;
		--a; --b;
		queries[i] = {{b, a}, i};
	}
	sort(queries.begin(), queries.end());
	for (int i = 0; i < q; ++i) std::swap(queries[i].first.first, queries[i].first.second);
	
	// Initialize the segment tree
	for (int i = N; i < 2 * N; ++i) {
		max_max[i] = {value[i-N], 1};
		min_max[i] = value[i-N];
		min_min[i] = {value[i-N], 1};
		max_min[i] = value[i-N];
		min_f[i] = {1, 1};
		min_h[i] = {0, 0};
	}
	for (int i = N-1; i > 0; --i) {
		update(i);
	}
	for (int i = 1; i < 2 * N; ++i) {
		s_max[i] = -1;
		s_min[i] = -1;
	}

	// Calculate the answers
	int j = 0;
	for (int i = 0; i < n; ++i) {

		setIntMax(0, i, value[i]);
		setIntMin(0, i, value[i]);
		addInt(0, i, -1);
		advanceStep();

		/*
		std::cout << "histories:\n";
		for (int j = 0; j < n; ++j) {
			auto tmp = getHist(j, j);
			std::cout << tmp.first << ' ' << tmp.second << '\n';
		}
		*/

		while((j < queries.size()) && (queries[j].first.second <= i)) {
			int a = queries[j].first.first;
			int ind = queries[j].second;
			ll ans = getHist(a, i).second;
			// std::cout << "[" << a << "," << i << "]: " << ans << '\n';
			answers[ind] = ans;
			++j;
		}
	}

	// Print the answers
	for (auto it : answers) std::cout << it << ' '; std::cout << '\n';
}