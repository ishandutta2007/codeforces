#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

template<ULL M>
struct static_modint {
	ULL x;
	static_modint(ULL val = 0) : x(val) {}

	static_modint operator-() const { if (x == 0) return 0; else return M - x; }
	static_modint& operator+=(static_modint r) { x += r.x; if (x >= M) x -= M; return *this; }
	static_modint operator+(static_modint r) const { static_modint res = x; return res += r; }
	static_modint& operator-=(static_modint r) { x += M - r.x; if (x >= M) x -= M; return *this; }
	static_modint operator-(static_modint r) const { static_modint res = x; return res -= r; }
	static_modint& operator*=(static_modint r) { x = x * r.x % M; return *this; }
	static_modint operator*(static_modint r) const { return static_modint(x * r.x % M); }
	static_modint operator^(ULL r) const {
		if (r == 0) return static_modint(1);
		static_modint res = (*this * *this) ^ (r / 2);
		if (r % 2) res *= *this;
		return res;
	}
	static_modint& operator^=(ULL r) { return *this = *this ^ r; }
	static_modint& operator/=(static_modint r) { *this *= r ^ (M - 1); return *this; }
	static_modint operator/(static_modint r) const { return *this * (r ^ (M - 2)); }
	ULL& operator*() { return x; }
	const ULL& operator*() const { return x; }
	bool operator==(static_modint r) const { return x == r; }
	bool operator!=(static_modint r) const { return x != r; }
};

const ULL M = 998244353;
using MLL = static_modint<998244353>;

int N;
int A[300000];

const int Z = 300000;
MLL F[Z + 1];
MLL I[Z + 1];
MLL iF[Z + 1];

MLL C(int n, int r) { return F[n] * iF[r] * iF[n - r]; }

int main() {
	cin >> N;
	rep(i, N * 2) cin >> A[i];

	F[0] = I[1] = iF[0] = 1;
	for (int i = 1; i <= Z; i++) F[i] = F[i - 1] * i;
	for (int i = 2; i <= Z; i++) I[i] = -(MLL(M / i) * I[M % i]);
	for (int i = 1; i <= Z; i++) iF[i] = iF[i - 1] * I[i];

	sort(A, A + N * 2);

	MLL ans = 0;

	rep(i, N) {
		ans += -MLL(A[i]);
		ans += MLL(A[N + i]);
	}

	ans *= C(2 * N, N);
	cout << *ans << endl;

	return 0;
}