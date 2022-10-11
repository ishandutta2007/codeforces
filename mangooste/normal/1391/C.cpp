#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T, T mod, class BIG = long long>
struct modular {
	T val;
	modular() {}
	template<class C> modular(C x) : val((x % mod + mod) % mod) {}
	modular& operator = (modular a) { val = a.val; return *this; }
	modular& operator += (modular a) { val += a.val; if (val >= mod) a -= mod; return *this; }
	modular& operator -= (modular a) { val -= a.val; if (val < 0) val += mod; return *this; }
	modular& operator *= (modular a) { val = BIG(val) * a.val % mod; return *this; }
	modular& operator /= (modular a) { val = BIG(val) * power(a, mod - 2) % mod; return *this; }
	modular operator + (modular a) { BIG res = val + a.val; return res - mod * (res >= mod); }
	modular operator - (modular a) { BIG res = val - a.val; return res + mod * (res < 0); }
	modular operator * (modular a) { return (BIG) val * a.val % mod; }
	modular operator / (modular a) { return (BIG) val * power(a, mod - 2) % mod; }
	friend modular power(modular a, BIG pw) { modular res = 1; while (pw) { if (pw % 2) res *= a; a *= a; pw /= 2; } return res; }
	friend ostream& operator << (ostream &out, modular a) { return out << a.val; }
	friend istream& operator >> (istream &in, modular &a) { BIG x; in >> x; a = modular(x); return in; }
};

using mint = modular<int, 1000000007>;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	mint fact = 1;
	for (int i = 2; i <= n; i++) fact *= i;
	cout << fact - power((mint) 2, n - 1) << '\n';
}