#include <bits/stdc++.h>
using namespace std;


template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}

public:

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

using num = modnum<998244353>;

vector<num> fact, ifact;

void init(){
	int N = 510000;
	fact = {1};
	for(int i = 1; i < N; i++) fact.push_back(i * fact[i-1]);
	ifact.resize(N);
	ifact.back() = 1 / fact.back();
	for(int i = N - 1; i > 0; i--) ifact[i-1] = i * ifact[i];
}

num ncr(int n, int k){
	if(k < 0 || k > n) return 0;
	return fact[n] * ifact[k] * ifact[n-k];
}


int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	init();
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 0; i < n; i++){
		if(i & 1){
			if(s[i] != '?'){
				s[i] ^= 'b';
				s[i] ^= 'w';
			}
		}
	}
	vector<pair<int,int> > queries;
	{
		int q = 0;
		int c = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '?'){
				q++;
			} else if(s[i] == 'b'){
				c++;
			} else if(s[i] == 'w'){
				c--;
			} else assert(false);
		}
		queries.push_back({q, c});
		for(int _ = 0; _ < m; _++){
			int a;
			cin >> a;
			char b;
			cin >> b;
			a--;
			if(a & 1){
				if(b != '?'){
					b ^= 'b';
					b ^= 'w';
				}
			}
			if(s[a] == '?'){
				q--;
			} else if(s[a] == 'b'){
				c--;
			} else if(s[a] == 'w'){
				c++;
			} else assert(false);
			s[a] = b;
			if(s[a] == '?'){
				q++;
			} else if(s[a] == 'b'){
				c++;
			} else if(s[a] == 'w'){
				c--;
			} else assert(false);
			queries.push_back({q, c});
		}
	}
	num i2 = 1 / num(2);
	num i4 = 1 / num(4);
	int pq = -1;
	int pk = -1;
	num pval = 0;
	for(auto& x : queries){
		int q, c;
		tie(q, c) = x;
		if(q == 0) continue;
		assert(q > 0);
		int k = min(q, (q-c) / 2);
		if(k < 0) k = -1;
		num psum = 0;
		num msum = 0;
		psum += pow(num(2), q) * i4 * (c-q);
		psum += (q > 0) ? (pow(num(2), q-1) * q * i2) : 0;
		msum += (q == 0) ? (num(c-q) * i4) : 0;
		msum += (q == 1) ? (-num(1) * i2) : 0;
		num s1 = 0;
		num s2 = 0;
		if(pq == -1 || q <= 2 || pq <= 2 || k <= 2 || pk <= 2){
			pval = 0;
			for(int i = 0; i <= k; i++) pval += ncr(q, i);
			pq = q;
			pk = k;
		} else {
			while(pq < q){
				pval = pval + pval - ncr(pq, pk);
				pq += 1;
			}
			while(pq > q){
				pval = (pval + ncr(pq-1, pk)) * i2;
				pq -= 1;
			}
			while(pk > k){
				pval -= ncr(pq, pk);
				pk--;
			}
			while(pk < k){
				pk++;
				pval += ncr(pq, pk);
			}
			assert(pq == q && pk == k);
		}
		s2 = pval;
		s1 = (s2 - ncr(q-1, k)) * i2;
		psum -= s1 * q;
		psum += s2 * i2 * (q - c);
		msum += ncr(q-1, k) * i2 * (q-c) * ((k & 1) ? -1 : 1);
		msum += ncr(q-2, k-1) * q * ((k & 1) ? 1 : -1);
		if(q == 1 && 1 <= k) msum += 1;
		int sign = ((c - q) % 4 == 0) ? 1 : -1;
		num tsum = (psum + msum * sign) * i2;
		num tot = pow(num(2), q-1);
		num prob = tsum / tot;
		cout << prob << '\n';
	}
}