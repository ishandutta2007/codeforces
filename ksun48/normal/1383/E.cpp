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

using num = modnum<int(1e9) + 7>;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	string s;
	cin >> s;
	int n = (int)s.size();
	num ans;
	if(s == string(n, '0')){
		cout << n << '\n';
		return 0;
	}
	{
		int i = 0;
		int j = n-1;
		while(s[i] == '0') i++;
		while(s[j] == '0') j--;
		ans = num(i+1) * num(n-j);
		s = s.substr(i+1, j+1 - i);
	}
	int cnt = 0;
	vector<int> what;
	for(char z : s){
		if(z == '0'){
			cnt++;
		} else {
			what.push_back(cnt);
			cnt = 0;
		}
	}


	n = (int)what.size();
	vector<int> last_bigger(n);
	vector<int> stk;
	for(int j = 0; j < n; j++){
		while(!stk.empty() && what[stk.back()] <= what[j]){
			stk.pop_back();
		}
		if(stk.empty()){
			last_bigger[j] = -1;
		} else {
			last_bigger[j] = stk.back();
		}
		stk.push_back(j);
	}
	vector<num> val(n+1, 0);
	vector<num> psum(n+2, 0);
	val[0] = 1;
	psum[1] = 1;
	for(int i = 0; i < n; i++){
		val[i+1] = 0;
		int z = i-1;
		for(int b = 0; b <= what[i]; b++){
			while(z >= 0 && what[z] < b){
				z = last_bigger[z];
			}
			val[i+1] += psum[i+1] - psum[z+1];
		}
		psum[i+2] = psum[i+1] + val[i+1];
	}
	ans *= psum[n+1];
	cout << ans << '\n';
}