#include <iostream>

const int B = 32;

struct XRE {
	int bits[B];
	long long value;
	
	XRE() {
		for (int i = 0; i < B; ++i) {
			bits[i] = 0;
		}
		value = 0;
	}

	XRE(int i) {
		for (int k = 0; k < B; ++k) {
			bits[k] = i & 1;
			i >>= 1;
		}
	}

	void make(const XRE& left, const XRE& right) {
		value = left.value + right.value;
		for (int i = 0; i < B; ++i) {
			bits[i] = left.bits[i] + right.bits[i];
		}
	}

	void xorit(int val, int len) {
		for (int i = 0; i < B; ++i) {
			if (val & 1) {
				bits[i] = len - bits[i];
			}
			val >>= 1;
		}
		sum();
	}

	long long sum() {
		value = 0;
		long long mult = 1;
		for (int i = 0; i < B; ++i) {
			value += bits[i] * mult;
			mult <<= 1;
		}
	}

	void print() {
		for (int k = 0; k < B; ++k) {
			std::cout << bits[k] << " ";
		}
		std::cout << "\n";
	}
};

const int N = 1e5;
XRE sums[4 * N];
int xorer[4 * N];

void push(int i, int s, int e) {
	if (xorer[i]) {
		sums[i].xorit(xorer[i], e - s + 1);
		if (s != e) {
			xorer[2 * i] ^= xorer[i];
			xorer[2 * i + 1] ^=xorer[i];
		}
		xorer[i] = 0;
	}
}

long long sum(int i, int s, int e, int is, int ie) {
	if (e < is || s > ie) return 0;
	push(i, s, e);
	if (is <= s && e <= ie) return sums[i].value;
	int mid = (s + e) / 2;
	return sum(2 * i, s, mid, is, ie) + sum(2 * i + 1, mid+1, e, is, ie);
}

void doit(int i, int s, int e, int is, int ie, int x) {
	if (e < is || s > ie) {
		push(i, s, e);
	} else if (is <= s && e <= ie) {
		xorer[i] ^= x;
		push(i, s, e);
	} else {
		push(i, s, e);
		int mid = (s+e)/2;
		doit(2 * i, s, mid, is, ie, x);
		doit(2 * i + 1, mid+1, e, is, ie, x);
		sums[i].make(sums[2 * i], sums[2 * i + 1]);
	}
}

void test(int i, int s, int e) {
	push(i,s,e);
	sums[i].print();
	if (s != e) {
		test(2 * i, s, (s + e) / 2);
		test(2 * i + 1, (s+ e) / 2 + 1, e);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	std::cin >> n;
	int high = 1;
	while(high < n) {
		high <<= 1;
	}
	--high;
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		doit(1, 0, high, i, i, v);
	}
	int q;
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int s, e;
			std::cin >> s >> e;
			std::cout << sum(1, 0, high, s-1, e-1) << "\n";
		} else {
			int s, e, x;
			std::cin >> s >> e >> x;
			doit(1, 0, high, s-1, e-1, x);
		}
	}
}