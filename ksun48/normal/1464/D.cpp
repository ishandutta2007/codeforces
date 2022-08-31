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

void solve(){
	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; i++){
		cin >> p[i];
		p[i]--;
	}
	vector<int> vis(n);
	vector<int> perms;
	for(int i = 0; i < n; i++){
		if(vis[i]) continue;
		int len = 0;
		int cur = i;
		while(!vis[cur]){
			vis[cur] = 1;
			cur = p[cur];
			len++;
		}
		perms.push_back(len);
	}
	sort(perms.begin(), perms.end());
	num ans = 1;
	int best = n;

	auto threes = [&](int a, int b, int c) -> int {
		int r = (a + b + b);
		assert(r % 3 == 0);
		r /= 3;
		int cost = 0;
		if(b > r){
			cost += b-r;
			b -= cost;
			a += 2*cost;
		}
		return cost + (a + b - r);
	};
	auto solve = [&](int extra) -> void {
		int cost = 0;
		vector<int> freq(5, 0);
		for(int len : perms){
			if(len <= 4){
				freq[len]++;
			} else {
				cost += (len - 2) / 3;
				freq[3] += (len - 2) / 3;
				len -= (len - 2) / 3 * 3;
				freq[len]++;
				assert(len <= 4);
			}
		}
		if(freq[4] >= 1){
			freq[3] += (freq[4] - 1);
			freq[1] += (freq[4] - 1);
			cost += (freq[4] - 1);
			freq[4] = 1;
		}
		if(extra == 0 || extra == 2){
			freq[3] += freq[4];
			freq[1] += freq[4];
			cost += freq[4];
			if(extra == 0){
				best = min(best, cost + threes(freq[1], freq[2], freq[3]));
			} else {
				if(freq[2] >= 1) best = min(best, cost + threes(freq[1], freq[2]-1, freq[3]));
				if(freq[1] >= 2) best = min(best, cost + 1 + threes(freq[1]-2, freq[2], freq[3]));
			}
		} else if(extra == 4){
			if(freq[4]){
				best = min(best, cost + threes(freq[1], freq[2], freq[3]));
			}
			{
				freq[3] += freq[4];
				freq[1] += freq[4];
				cost += freq[4];
				freq[4] = 0;
				if(freq[3] && freq[1]){
					best = min(best, cost + 1 + threes(freq[1]-1, freq[2], freq[3]-1));
				}
				if(freq[2] >= 2){
					best = min(best, cost + threes(freq[1], freq[2] - 2, freq[3]));
				}
				if(freq[2] >= 1 && freq[1] >= 2){
					best = min(best, cost + 1 + threes(freq[1]-2, freq[2] - 1, freq[3]));
				}
				if(freq[1] >= 4){
					best = min(best, cost + 2 + threes(freq[1]-4, freq[2], freq[3]));
				}
				if(freq[3] > 0){
					freq[3]--; freq[2]++; freq[1]++; cost++;
					if(freq[3] && freq[1]){
						best = min(best, cost + 1 + threes(freq[1]-1, freq[2], freq[3]-1));
					}
					if(freq[2] >= 2){
						best = min(best, cost + threes(freq[1], freq[2] - 2, freq[3]));
					}
					if(freq[2] >= 1 && freq[1] >= 2){
						best = min(best, cost + 1 + threes(freq[1]-2, freq[2] - 1, freq[3]));
					}
					if(freq[1] >= 4){
						best = min(best, cost + 2 + threes(freq[1]-4, freq[2], freq[3]));
					}
				}
			}
		}
	};
	if(n % 3 == 0){
		ans = pow(num(3), n/3);
		solve(0);
	} else if(n % 3 == 2){
		ans = pow(num(3), (n-2)/3) * 2;		
		solve(2);
	} else if(n % 3 == 1){
		ans = pow(num(3), (n-4)/3) * 4;
		solve(4);
	}
	// cout << "TEST: ";
	// for(int len : perms) cout << len << ' ';
	// cout << '\n';
	cout << ans << ' ' << best << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}