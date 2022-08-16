#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 100010;
 
const int MOD = 998244353;
 
struct mod_int {
	int val;
 
	mod_int(long long v = 0) {
		if (v < 0)
			v = v % MOD + MOD;
 
		if (v >= MOD)
			v %= MOD;
 
		val = v;
	}
 
	static int mod_inv(int a, int m = MOD) {
		// https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
		int g = m, r = a, x = 0, y = 1;
 
		while (r != 0) {
			int q = g / r;
			g %= r; swap(g, r);
			x -= q * y; swap(x, y);
		}
 
		return x < 0 ? x + m : x;
	}
 
	explicit operator int() const {
		return val;
	}
 
	mod_int& operator+=(const mod_int& other) {
		val += other.val;
		if (val >= MOD) val -= MOD;
		return *this;
	}
 
	mod_int& operator-=(const mod_int& other) {
		val -= other.val;
		if (val < 0) val += MOD;
		return *this;
	}
 
	static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
		return x % m;
	}
 
	mod_int& operator*=(const mod_int& other) {
		val = fast_mod((uint64_t)val * other.val);
		return *this;
	}
 
	mod_int& operator/=(const mod_int& other) {
		return *this *= other.inv();
	}
 
	friend mod_int operator+(const mod_int& a, const mod_int& b) { return mod_int(a) += b; }
	friend mod_int operator-(const mod_int& a, const mod_int& b) { return mod_int(a) -= b; }
	friend mod_int operator*(const mod_int& a, const mod_int& b) { return mod_int(a) *= b; }
	friend mod_int operator/(const mod_int& a, const mod_int& b) { return mod_int(a) /= b; }
 
	mod_int& operator++() {
		val = val == MOD - 1 ? 0 : val + 1;
		return *this;
	}
 
	mod_int& operator--() {
		val = val == 0 ? MOD - 1 : val - 1;
		return *this;
	}
 
	mod_int operator++(int) { mod_int before = *this; ++* this; return before; }
	mod_int operator--(int) { mod_int before = *this; --* this; return before; }
 
	mod_int operator-() const {
		return val == 0 ? 0 : MOD - val;
	}
 
	bool operator==(const mod_int& other) const { return val == other.val; }
	bool operator!=(const mod_int& other) const { return val != other.val; }
 
	mod_int inv() const {
		return mod_inv(val);
	}
 
	mod_int pow(long long p) const {
		assert(p >= 0);
		mod_int a = *this, result = 1;
 
		while (p > 0) {
			if (p & 1)
				result *= a;
 
			a *= a;
			p >>= 1;
		}
 
		return result;
	}
 
	friend ostream& operator<<(ostream& stream, const mod_int& m) {
		return stream << m.val;
	}
};
 
namespace NTT {
	vector<mod_int> roots = { 0, 1 };
	vector<int> bit_reverse;
	int max_size = -1;
	mod_int root;
 
	bool is_power_of_two(int n) {
		return (n & (n - 1)) == 0;
	}
 
	int round_up_power_two(int n) {
		assert(n > 0);
 
		while (n & (n - 1))
			n = (n | (n - 1)) + 1;
 
		return n;
	}
 
	// Given n (a power of two), finds k such that n == 1 << k.
	int get_length(int n) {
		assert(is_power_of_two(n));
		return __builtin_ctz(n);
	}
 
	// Rearranges the indices to be sorted by lowest bit first, then second lowest, etc., rather than highest bit first.
	// This makes even-odd div-conquer much easier.
	void bit_reorder(int n, vector<mod_int>& values) {
		if ((int)bit_reverse.size() != n) {
			bit_reverse.assign(n, 0);
			int length = get_length(n);
 
			for (int i = 0; i < n; i++)
				bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
		}
 
		for (int i = 0; i < n; i++)
			if (i < bit_reverse[i])
				swap(values[i], values[bit_reverse[i]]);
	}
 
	void find_root() {
		int order = MOD - 1;
		max_size = 1;
 
		while (order % 2 == 0) {
			order /= 2;
			max_size *= 2;
		}
 
		root = 2;
 
		// Find a max_size-th primitive root of MOD.
		while (!(root.pow(max_size) == 1 && root.pow(max_size / 2) != 1))
			root++;
	}
 
	void prepare_roots(int n) {
		if (max_size < 0)
			find_root();
 
		assert(n <= max_size);
 
		if ((int)roots.size() >= n)
			return;
 
		int length = get_length(roots.size());
		roots.resize(n);
 
		// The roots array is set up such that for a given power of two n >= 2, roots[n / 2] through roots[n - 1] are
		// the first half of the n-th primitive roots of MOD.
		while (1 << length < n) {
			// z is a 2^(length + 1)-th primitive root of MOD.
			mod_int z = root.pow(max_size >> (length + 1));
 
			for (int i = 1 << (length - 1); i < 1 << length; i++) {
				roots[2 * i] = roots[i];
				roots[2 * i + 1] = roots[i] * z;
			}
 
			length++;
		}
	}
 
	void fft_iterative(int N, vector<mod_int>& values) {
		assert(is_power_of_two(N));
		prepare_roots(N);
		bit_reorder(N, values);
 
		for (int n = 1; n < N; n *= 2)
			for (int start = 0; start < N; start += 2 * n)
				for (int i = 0; i < n; i++) {
					mod_int even = values[start + i];
					mod_int odd = values[start + n + i] * roots[n + i];
					values[start + n + i] = even - odd;
					values[start + i] = even + odd;
				}
	}
 
	const int FFT_CUTOFF = 150;
 
	vector<mod_int> mod_multiply(vector<mod_int> left, vector<mod_int> right) {
		int n = left.size();
		int m = right.size();
 
		// Brute force when either n or m is small enough.
		if (min(n, m) < FFT_CUTOFF) {
			constexpr uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t)MOD * MOD;
			vector<uint64_t> result(n + m - 1);
 
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					result[i + j] += (uint64_t)((int)left[i]) * ((int)right[j]);
 
					if (result[i + j] > ULL_BOUND)
						result[i + j] %= MOD;
				}
 
			for (uint64_t& x : result)
				if (x >= MOD)
					x %= MOD;
 
			return vector<mod_int>(result.begin(), result.end());
		}
 
		int N = round_up_power_two(n + m - 1);
		left.resize(N);
		right.resize(N);
 
		bool equal = left == right;
		fft_iterative(N, left);
 
		if (equal)
			right = left;
		else
			fft_iterative(N, right);
 
		mod_int inv_N = mod_int(N).inv();
 
		for (int i = 0; i < N; i++)
			left[i] *= right[i] * inv_N;
 
		reverse(left.begin() + 1, left.end());
		fft_iterative(N, left);
		left.resize(n + m - 1);
		return left;
	}
 
}
 
using poly = vector<mod_int>;
 
vector<mod_int> inv, factorial, inv_factorial;
 
void prepare_factorials(int maximum) {
	inv.assign(maximum + 1, 1);
 
	// Make sure MOD is prime, which is necessary for the inverse algorithm below.
	for (int p = 2; p * p <= MOD; p++)
		assert(MOD % p != 0);
 
	for (int i = 2; i <= maximum; i++)
		inv[i] = inv[MOD % i] * (MOD - MOD / i);
 
	factorial.resize(maximum + 1);
	inv_factorial.resize(maximum + 1);
	factorial[0] = inv_factorial[0] = 1;
 
	for (int i = 1; i <= maximum; i++) {
		factorial[i] = i * factorial[i - 1];
		inv_factorial[i] = inv[i] * inv_factorial[i - 1];
	}
}
 
// Given p(0), p(1), ..., p(d), which defines a polynomial p(x) of degree d,
// compute p(shift), p(shift + 1), ..., p(shift + d),
// provided that d << MOD.
poly poly_normal_shift(const poly& v, int d, mod_int shift)
{
	if (int(shift) <= d) // speical case: overlap
	{
		auto tmp = poly_normal_shift(v, d, d + 1);
		poly res(d + 1);
		for (int i = 0; i <= d; ++i)
		{
			if (int(shift + i) <= d) res[i] = v[int(shift + i)];
			else res[i] = tmp[int(shift + i) - (d + 1)];
		}
		return res;
	}
	if (int(shift) >= MOD - d) // special case: overlap
	{
		auto tmp = poly_normal_shift(v, d, MOD - d - 1);
		poly res(d + 1);
		for (int i = 0; i <= d; ++i)
		{
			if (int(shift + i) <= d) res[i] = v[int(shift + i)];
			else res[i] = tmp[int(shift + i) - (MOD - d - 1)];
		}
		return res;
	}
	// common case
	poly lhs(d + 1), rhs(2 * d + 1);
	for (int i = 0; i <= d; ++i)
	{
		lhs[i] = v[i] * inv_factorial[i] * inv_factorial[d - i];
		if ((d - i) % 2 == 1) lhs[i] = -lhs[i];
	}
	for (int i = 0; i <= 2 * d; ++i)
	{
		rhs[i] = (shift + i - d).inv();
	}
	auto tmp = NTT::mod_multiply(lhs, rhs);
	poly res(tmp.begin() + d, tmp.begin() + 2 * d + 1);
	mod_int prod = 1;
	for (int i = 0; i <= d; ++i) prod *= shift - i;
	for (int i = 0; i <= d; ++i)
	{
		res[i] *= prod;
		prod = prod / (shift + i - d) * (shift + i + 1);
	}
	return res;
}
 
// Given p(0), p(step), ..., p(step * d), which defines a polynomial p(x) of degree d,
// compute p(shift), p(shift + step), ..., p(shift + step * d).
poly poly_shift(const poly& v, int d, mod_int step, mod_int shift)
{
	return poly_normal_shift(v, d, shift / step);
}
 
// Given two linear functions p(x) and q(x), define
//   r_B(z) = p(z + 1) * q(z + 2) * q(z + 3) * ... * q(z + B) +
//            p(z + 1) * p(z + 2) * q(z + 3) * ... * q(z + B) +
//            ... +
//            p(z + 1) * p(z + 2) * p(z + 3) * ... * p(z + B),
//   p_B(z) = p(z + 1) * p(z + 2) * p(z + 3) * ... * p(z + B),
//   q_B(z) = q(z + 1) * q(z + 2) * q(z + 3) * ... * q(z + B).
// Return
//    r_block(0), r_block(step), ..., r_block(step * block),
//    p_block(0), p_block(step), ..., p_block(step * block),
//    q_block(0), q_block(step), ..., q_block(step * block).
tuple<poly, poly, poly> solve(const function<mod_int(mod_int)>& p, const function<mod_int(mod_int)>& q, int block, mod_int step)
{
	if (block == 1)
	{
		auto resr = { p(1), p(step + 1) };
		auto resp = { p(1), p(step + 1) };
		auto resq = { q(1), q(step + 1) };
		return { resr, resp, resq };
	}
 
	int B = (block + 1) / 2;
	auto [R00, P00, Q00] = solve(p, q, B, step);
 
	auto R10 = poly_shift(R00, B, step, step * B);
	auto R01 = poly_shift(R00, B, step, B);
	auto R11 = poly_shift(R00, B, step, step * B + B);
 
	auto P10 = poly_shift(P00, B, step, step * B);
	auto P01 = poly_shift(P00, B, step, B);
	auto P11 = poly_shift(P00, B, step, step * B + B);
 
	auto Q10 = poly_shift(Q00, B, step, step * B);
	auto Q01 = poly_shift(Q00, B, step, B);
	auto Q11 = poly_shift(Q00, B, step, step * B + B);
 
	poly resr(2 * B + 1), resp(2 * B + 1), resq(2 * B + 1);
	for (int i = 0; i <= B; ++i)
	{
		resr[i] = R00[i] * Q01[i] + P00[i] * R01[i];
		resr[i + B] = R10[i] * Q11[i] + P10[i] * R11[i];
		resp[i] = P00[i] * P01[i];
		resp[i + B] = P10[i] * P11[i];
		resq[i] = Q00[i] * Q01[i];
		resq[i + B] = Q10[i] * Q11[i];
	}
 
	if (block % 2 == 1)
	{
		for (int i = 0; i <= B; ++i)
		{
			resr[i] -= P00[i] * P01[i];
			if (i) resr[i + B] -= P10[i] * P11[i];
		}
		resr.pop_back();
		resp.pop_back();
		resq.pop_back();
		for (int i = 0; i <= block; ++i)
		{
			resr[i] /= q(i * step + block + 1);
			resp[i] /= p(i * step + block + 1);
			resq[i] /= q(i * step + block + 1);
		}
	}
 
	return { resr, resp, resq };
}
 
// For 0 <= k <= n / block, compute the sum of the following block terms:
//   p(1) * p(2) * ... * p((k - 1) * block) * p((k - 1) * block + 1) * q((k - 1) * block + 2) * q((k - 1) * block + 3) * ... * q(k * block) * q(k * block + 1) * ... * q(n),
//   p(1) * p(2) * ... * p((k - 1) * block) * p((k - 1) * block + 1) * p((k - 1) * block + 2) * q((k - 1) * block + 3) * ... * q(k * block) * q(k * block + 1) * ... * q(n),
//   ... +
//   p(1) * p(2) * ... * p((k - 1) * block) * p((k - 1) * block + 1) * p((k - 1) * block + 2) * p((k - 1) * block + 3) * ... * p(k * block) * q(k * block + 1) * ... * q(n).
// provided that p(x) and q(x) are linear functions.
// Moreover, 
//   The function computes p(1) * p(2) * ... p(k * block) for every 0 <= k <= n / block.
//   The function computes q(k * block + 1) * ... * q(n) for every 0 <= k <= n / block.
void prefix_block_sum(const function<mod_int(mod_int)>& p, const function<mod_int(mod_int)>& q, int n, int block, poly& prefix_product_p, poly& suffix_product_q, poly& prefix_sum_pq)
{
	poly pos;
	for (int i = 0; i + block <= n; i += block) pos.push_back(i);
	auto [valr, valp, valq] = solve(p, q, block, block);
 
	while (valp.size() > pos.size()) valp.pop_back();
	prefix_product_p = { 1 };
	for (int i = 0; i < pos.size(); ++i)
		prefix_product_p.push_back(prefix_product_p.back() * valp[i]);
 
	while (valq.size() > pos.size()) valq.pop_back();
	poly prefix_product_q = { 1 };
	for (int i = 0; i < pos.size(); ++i)
		prefix_product_q.push_back(prefix_product_q.back() * valq[i]);
	mod_int prod = prefix_product_q.back();
	for (int i = n / block * block + 1; i <= n; ++i) prod *= q(i);
	suffix_product_q = prefix_product_q;
	for (auto& x : suffix_product_q) x = prod / x;
	suffix_product_q.push_back(1); // for k = n / block + 1, default set the suffix product to 1.
 
	while (valr.size() > pos.size()) valr.pop_back();
	prefix_sum_pq = { 0 };
	for (int i = 0; i < pos.size(); ++i)
		prefix_sum_pq.push_back(prefix_sum_pq.back() + prefix_product_p[i] * valr[i] * suffix_product_q[i + 1]);
}
 
struct magic_show
{
	int n, block;
	function<mod_int(mod_int)> P, Q;
	poly prefix_product_P, suffix_product_Q, prefix_sum_PQ;
	magic_show(int n, int block, const function<mod_int(mod_int)>& p, const function<mod_int(mod_int)>& q) : n(n), block(block), P(p), Q(q)
	{
		prefix_block_sum(P, Q, n, block, prefix_product_P, suffix_product_Q, prefix_sum_PQ);
	}
 
	// Compute the magic value of x, which is
	//            P(1)   P(1) * P(2)         P(1) * P(2) * ... * P(x - 1) 
	//  -2 *  1 + ---- + ----------- + ... + ---------------------------- .
	//            Q(1)   Q(1) * Q(2)         Q(1) * Q(2) * ... * Q(x - 1) 
	mod_int magic(int x)
	{
		static mod_int suf_prod[MAXN];
		x--;
		mod_int res = 0;
		if (x >= 1)
		{
			int id = x / block;
			int st = id * block;
			res += prefix_sum_PQ[id];
			if (st != x)
			{
				suf_prod[block] = suffix_product_Q[id + 1];
				for (int i = block - 1; i >= 1; --i)
				{
					suf_prod[i] = suf_prod[i + 1];
					if (st + i + 1 <= n)
						suf_prod[i] *= Q(st + i + 1);
				}
				mod_int pre = prefix_product_P[id];
				for (int i = 1; st + i <= x; ++i)
				{
					pre *= P(st + i);
					res += pre * suf_prod[i];
				}
			}
			res /= suffix_product_Q[0];
		}
		res = (res + 1) * (-2);
		return res;
	}
};
 
void solve()
{
	int m;
	scanf("%d", &m);
	if (m == 1)
	{
		puts("0");
		return;
	}
	vector<int> a(m);
	int n = 0;
	for (auto& x : a)
	{
		scanf("%d", &x);
		n += x;
	}
	int block = sqrt(n - 1);
	while (block * block < n - 1) block++;
	prepare_factorials(block);
	auto P = [&](mod_int x) { return mod_int(2 * n) - x; };
	auto Q = [&](mod_int x) { return mod_int(n) - x; };
	magic_show show(n - 1, block, P, Q);
 
	mod_int res = 0;
	for (auto x : a)
		res += show.magic(x);
	res -= show.magic(n);
	printf("%d\n", int(res));
}
 
int main()
{
	solve();
	return 0;
}