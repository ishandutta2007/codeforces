#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int mod = (int)1e9 + 7;

int64_t extGcd(int64_t a, int64_t b, int64_t& x, int64_t& y) { 
	if (!a) {
		x = 0;
		y = 1;
		return b;
	}
	int64_t x1, y1;
	int64_t d = extGcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

inline int addMod(int a, int b, int m = mod) {
	return ((int64_t)a + b) % m;
}

inline int mulMod(int a, int b, int m = mod) {
	return ((int64_t)a * b) % m;
}

inline int divMod(int a, int b, int m = mod) {
	int64_t x, y;
	int64_t g = extGcd(b, m, x, y);
	if (g != 1) {
		cerr << "Bad gcd!" << endl;
		for (;;);
	}
	x = (x % m + m) % m;
	return mulMod(a, x, m);
}

const int factRange = 1000000;
int fact[factRange];

inline void precalcFactorials() {
	fact[0] = 1;
	for (int i = 1; i < factRange; i++) {
		fact[i] = mulMod(fact[i-1], i);
	}
}

inline int F(int n) {
	return (n < 0) ? 0 : fact[n];
}

inline int C(int k, int n) {
	return divMod(F(n), mulMod(F(n-k), F(k)));
}

int main() {
	ios_base::sync_with_stdio(false);
	string s; 
	cin >> s;
	int len = s.size();
	precalcFactorials();
	vector<int> opnLeft(len), clsRight(len);
	opnLeft[0] = (s[0] == '(') ? 1 : 0;
	for (int i = 1; i < len; i++) {
		opnLeft[i] = opnLeft[i-1] + ((s[i] == '(') ? 1 : 0);
	}
	clsRight[len-1] = (s[len-1] == ')') ? 1 : 0;
	for (int i = len-2; i >= 0; i--) {
		clsRight[i] = clsRight[i+1] + ((s[i] == ')') ? 1 : 0);
	}
	int res = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] != '(' || clsRight[i] == 0) {
			continue;
		}
		int add = C(opnLeft[i], opnLeft[i] + clsRight[i] - 1);
		res = addMod(res, add);
	}
	cout << res << endl;
	return 0;
}