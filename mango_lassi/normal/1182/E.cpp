#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MOD = 1e9 + 7;

constexpr int bLog(ll v) { return v ? 63 - __builtin_clzll(v) : 0; }
template<class T>
T itPow(const T& a, ll d, T r = 1) {
        for (ll b = 1ll << bLog(d); b > 0; b /= 2) {
                r = r*r;
                if (d & b) r = r*a;
        }
        return r;
}

// Assumes the modulo is a prime
template<int P=MOD>
struct ModNum {
	int v;

	ModNum(int val) : v(val % P) {}
	ModNum operator+(const ModNum& rhs) const {
		int res = v + rhs.v;
		return (res >= P ? res-P : res);
	}
	ModNum& operator+=(const ModNum& rhs) {
		v += rhs.v;
		v = (v >= P ? v-P : v);
		return *this;
	}
	ModNum operator-(const ModNum& rhs) const {
		int res = v - rhs.v;
		return (res < 0 ? res+P : res);
	}
	ModNum operator*(const ModNum& rhs) const {
		return ((ll)v * rhs.v) % P;
	}
	ModNum inv() const {
		return itPow(*this, P-2);
	}
	ModNum operator/(const ModNum& rhs) const {
		return (*this) * rhs.inv();
	}
	operator int() const { return v; }
};

// Assumes 0 and 1 are 0,1 for T
template<class T=ll>
struct Matrix {
	vector<T> mat;
	int h, w;

	Matrix(int height, int width) : h(height), w(width), mat(height*width, 0) {}

	const T& operator()(int y, int x) const {
		return mat[x+y*w];
	}
	T& operator()(int y, int x) {
		return mat[x+y*w];
	}
	static Matrix ident(int n) {
		Matrix res(n, n);
		for (int i = 0; i < n; ++i) res(i, i) = 1;
		return res;
	}
	Matrix& operator+=(const Matrix& rhs) {
		assert(h == rhs.h && w == rhs.w);
		for (int i = 0; i < w*h; ++i) mat[i] += rhs.mat[i];
	}
	Matrix operator*(const Matrix& rhs) const {
		assert(w == rhs.h);
		Matrix res(h, rhs.w);
		for (int i = 0; i < w; ++i) {
			int b1 = i * rhs.w;
			for (int y = 0; y < res.h; ++y) {
				T mult = mat[i + y * w];
				int b2 = y * res.w;
				for (int x = 0; x < res.w; ++x) {
					res.mat[b2 + x] += mult * rhs.mat[b1 + x];
				}
			}
		}
		return res;
	}
};

// Baby-step Giant-step algorithm for discrete logarithm ( https://en.wikipedia.org/wiki/Baby-step_giant-step )
template<int P = MOD>
struct BabyGiantStep {
	gp_hash_table<int, int> vals;
	int ord = P-1;
	int ias;

	// O(P/k). Finds smallest t>0 s.t. a^t = b. If none exists, returns -1.
	int ask(int b) {
		for (int bi = 0; bi <= ord; bi += vals.size()) {
			auto it = vals.find(b);
			if (it != vals.end()) {
				return bi + it->second;
			}
			b = ((ll)b * ias) % P; // Giant step
		}
		return -1;
	}

	// O(k). Must have 0 < a < P.
	BabyGiantStep(int a, int k = sqrt(P))  {
		int mult = 1;
		for (int i = 1; i <= k; ++i) {
			mult = ((ll)mult * a) % P;
			vals[mult] = i;
			if (mult == 1) break;
		}
		ias = itPow<ModNum<P>>(mult, P-2);
		ord = ask(1);
	}
};

int main() {
	// Build transition matrix
	Matrix<ModNum<MOD-1>> mat(5, 5);
	mat(1, 0) = 1;
	mat(2, 1) = 1;
	mat(0, 2) = 1;
	mat(1, 2) = 1;
	mat(2, 2) = 1;
	mat(3, 2) = 1;
	mat(3, 3) = 1;
	mat(4, 3) = 1;
	mat(4, 4) = 1;

	ll n;
	int f1, f2, f3, c;
	cin >> n >> f1 >> f2 >> f3 >> c;

	const int GEN = 5;
	BabyGiantStep<MOD> step(GEN);

	Matrix<ModNum<MOD-1>> vec(1, 5);
	vec(0,0) = step.ask(f1);
	vec(0,1) = step.ask(f2);
	vec(0,2) = step.ask(f3);
	vec(0,3) = 2*step.ask(c);
	vec(0,4) = 2*step.ask(c);

	auto pw = itPow(mat, n-3, mat.ident(5));
	vec = vec * pw;
	cout << itPow<ModNum<MOD>>(GEN, (int)vec(0, 2)) << '\n';
}