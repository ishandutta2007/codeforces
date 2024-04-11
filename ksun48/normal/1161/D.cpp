#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll modinv(ll a, ll m) {
	assert(m > 0);
	if (m == 1) return 0;
	a %= m;
	if (a < 0) a += m;
	assert(a != 0);
	if (a == 1) return 1;
	return m - modinv(m, a) * m / a;
}

template <int MOD_> struct modnum {
private:
	int v;
public:
	static const int MOD = MOD_;

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int () const { return v; }
	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum operator ~ () const {
		modnum res;
		res.v = modinv(v, MOD);
		return res;
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
		return *this *= (~o);
	}

	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

using num = modnum<998244353>;


int main(){
	string s;
	cin >> s;
	if(s == "1"){
		cout << 0 << '\n';
		return 0;
	}
	if(s.back() == '1'){
		cout << 0 << '\n';
		return 0;
	}
	s.pop_back();
	reverse(s.begin(), s.end());
	s.pop_back();
	num ans = 0;

	int n = s.size();
	{
		num val = 1;
		for(int i = 0; i <= n-1-i; i++){
			if((s[i] ^ s[n-1-i]) == ('0' ^ '1')){
				val = 0;
			} else if(s[i] == '?' && s[n-1-i] == '?'){
				val *= 2;
			} else {
				val *= 1;
			}
		}
		ans += val;
	}
	for(int i = 0; i < n; i++){
		string t = s;
		if(t[i] != '?') t[i] ^= ('0' ^ '1');
		vector<int> vis(n, 0);
		num z = 1;
		for(int b = n-1; b >= 0; b--){
			if(vis[b]) continue;
			int sum = 0;
			int nq = 0;
			//int nc = 0;
			int cur = b;
			int self_pair = 0;
			while(1){
				assert(!vis[cur]);
				vis[cur] = 1;
				//nc++;
				if(t[cur] == '?'){
					nq++;
				} else {
					sum ^= (t[cur] - '0');
				}
				if(cur == n-1-cur){
					self_pair = 1;
					break;
				}
				cur = n-1-cur;
				assert(!vis[cur]);
				vis[cur] = 1;
				//nc++;
				if(t[cur] == '?'){
					nq++;
				} else {
					sum ^= (t[cur] - '0');
				}
				if(cur >= i){
					break;
				}
				if(cur == i-1-cur){
					self_pair = 1;
					break;
				}
				cur = i-1-cur;
			}
			if(nq == 0 && !self_pair && sum == 1){
				z = 0;
			} else {
				for(int i = 0; i < nq; i++) z *= 2;
				if(nq > 0 && self_pair == 0) z /= 2;
			}
		}
		ans += z;
	}
	cout << int(ans) << '\n';
}