#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <unordered_set>

const int P = 18;
const int N = 1<<P;
const int MOD = 998244353;
int add[2*N];
int mul[2*N];
int val[2*N];
std::unordered_set<long long> exs_bl;
std::unordered_set<long long> all_bl;
int h;

void push(int i, int ia, int ib) {
	// std::cout << "push(" << i << "): val[" << i << "]=" << val[i] << ", add[" << i << "]=" << add[i] << ", mul[" << i << "]=" << mul[i] << '\n';
	int le = 2 * i;
	int ri = le + 1;
	long long m = mul[i];
	int len = ib - ia + 1;
	if (m != 1) {
		val[i] = (val[i] * m) % MOD;
		if (len > 1) {
			add[le] = (add[le] * m) % MOD;
			add[ri] = (add[ri] * m) % MOD;
			mul[le] = (mul[le] * m) % MOD;
			mul[ri] = (mul[ri] * m) % MOD;
		}
		mul[i] = 1;
	}
	int a = add[i];
	if (a != 0) {
		val[i] = (val[i] + (long long)a * len) % MOD;
		if (len > 1) {
			add[le] += a;
			if (add[le] >= MOD) add[le] -= MOD;
			add[ri] += a;
			if (add[ri] >= MOD) add[ri] -= MOD;
		}
		add[i] = 0;
	}
}

void upd(int i) {
	val[i] = val[2*i] + val[2*i+1];
	if (val[i] >= MOD) val[i] -= MOD;
}

inline long long pack(int x, int i) {
	return x + ((long long)i << P);
}

void dfsApply(int x, bool ab, int ia, int ib, int i) {
	// std::cout << "dfsApply x=" << x << ", ia=" << ia << ", ib=" << ib << ", i=" << i << '\n';
	long long code = pack(x, i);
	if (! ab) {
		auto all_it = all_bl.find(code);
		if (all_it != all_bl.end()) {
			all_bl.erase(all_it);
			ab = true;
		}
	}
	if (ab) {
		// std::cout << "case 1\n";
		mul[i] = (mul[i] * 2);
		if (mul[i] >= MOD) mul[i] -= MOD;
		add[i] = (add[i] * 2);
		if (add[i] >= MOD) add[i] -= MOD;
		push(i, ia, ib);
	} else {
		auto exs_it = exs_bl.find(code);
		if (exs_it == exs_bl.end()) {
			// std::cout << "case 2\n";
			++add[i];
			if (add[i] >= MOD) add[i] -= MOD;
			push(i, ia, ib);
		} else {
			// std::cout << "case 3\n";
			exs_bl.erase(exs_it);
			push(i, ia, ib);
			int mid = (ia + ib) >> 1;
			dfsApply(x, false, ia, mid, 2 * i);
			dfsApply(x, false, mid + 1, ib, 2 * i + 1);
			upd(i);
		}
	}
	// std::cout << "value: " << val[i] << '\n';
}

void apply(int a, int b, int x, bool ab = false, int ia = 0, int ib = h-1, int i = 1) {
	push(i, ia, ib);
	if (b < ia || ib < a) return;

	long long code = pack(x, i);

	if (all_bl.find(code) != all_bl.end()) ab = true;
	if (a <=ia && ib<= b) {
		dfsApply(x, ab, ia, ib, i);
		all_bl.insert(code);
	} else {
		int le = 2 * i;
		int ri = le + 1;
		int mid = (ia + ib) >> 1;
		apply(a, b, x, ab, ia, mid, le);
		apply(a, b, x, ab, mid + 1, ib, ri);

		if (! ab) {
			exs_bl.insert(code);
			/*
			long long ri_code = pack(x, ri);
			auto le_it = all_bl.find(pack(x, le));
			auto ri_it = all_bl.find(ri_code);
			if (le_it != all_bl.end() && ri_it != all_bl.end()) {
				all_bl.erase(le_it);
				all_bl.erase(all_bl.find(ri_code));
				all_bl.insert(code);
			} else {
				exs_bl.insert(code);
			}
			*/
		}

		upd(i);
	}
}

int calc(int a, int b, int ia = 0, int ib = h-1, int i = 1) {
	if (b < ia || ib < a) return 0;
	if (a <=ia && ib<= b) {
		push(i, ia, ib);
		return val[i];
	}

	push(i, ia, ib);
	int mid = (ia + ib) >> 1;
	int res = 0;
	res += calc(a, b, ia, mid, 2 * i);
	res += calc(a, b, mid + 1, ib, 2 * i + 1);
	if (res >= MOD) res -= MOD;
	return res;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;

	h = 1;
	while(h < n) h <<= 1;

	for (int i = 1; i < 2 * h; ++i) mul[i] = 1;
	exs_bl.reserve(12000000);
	all_bl.reserve(12000000);

	for (int i = 0; i < q; ++i) {
		int t, a, b;
		std::cin >> t >> a >> b;
		--a; --b;
		if (t == 1) {
			int x;
			std::cin >> x;
			apply(a, b, x);
		} else {
			std::cout << calc(a, b) << ' ';
		}
	}
	std::cout << '\n';
}