#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll modPow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if (b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}


struct MultSegTree {
	int h = 1;
	vector<ll> val;
	vector<ll> mult;

	void init(int n) {
		while(h < n) h <<= 1;
		val.resize(2*h, 1);
		mult.resize(2*h, 1);
	}

	void push(int i, int ia, int ib) {
		if (mult[i] != 1) {
			val[i] = (val[i] * modPow(mult[i], ib - ia + 1)) % MOD;
			if (i < h) {
				mult[2*i] = (mult[2*i] * mult[i]) % MOD;
				mult[2*i+1] = (mult[2*i+1] * mult[i]) % MOD;
			}
			mult[i] = 1;
		}
	}
	void update(int i) {
		val[i] = (val[2*i] * val[2*i+1]) % MOD;
	}

	ll recQuery(int a, int b, int ia, int ib, int i) {
		push(i, ia, ib);
		if (ib < a || b < ia) return 1;
		if (a <=ia && ib<= b) {
			return val[i];
		} else {
			int mid = (ia + ib) >> 1;
			ll res = 1;
			res *= recQuery(a, b, ia, mid, 2*i);
			res *= recQuery(a, b, mid+1, ib, 2*i+1);
			return res % MOD;
		}
	}

	void recMult(int a, int b, ll v, int ia, int ib, int i) {
		push(i, ia, ib);
		if (ib < a || b < ia) return;
		if (a <=ia && ib<= b) {
			mult[i] = (mult[i] * v) % MOD;
			push(i, ia, ib);
		} else {
			int mid = (ia + ib) >> 1;
			recMult(a, b, v, ia, mid, 2*i);
			recMult(a, b, v, mid+1, ib, 2*i+1);
			update(i);
		}
	}

	ll query(int a, int b) {
		return recQuery(a, b, 0, h-1, 1);
	}
	void multVal(int a, int b, ll v) {
		recMult(a, b, v, 0, h-1, 1);
	}
};

struct BoolTree {
	int h = 1;
	vector<bool> val;
	vector<bool> add;

	void init(int n) {
		while(h < n) h <<= 1;
		val.resize(2*h, 0);
		add.resize(2*h, 0);
	}

	void update(int i) {
		if (val[2*i] || val[2*i+1]) val[i] = true;
	}

	bool recQuery(int a, int b, int ia, int ib, int i) {
		if (ib < a || b < ia) return 0;
		if (add[i]) return 1;
		if (a <=ia && ib<= b) return val[i];
		
		int mid = (ia + ib) >> 1;
		if (recQuery(a, b, ia, mid, 2*i)) return true;
		if (recQuery(a, b, mid+1, ib, 2*i+1)) return true;
		return false;
	}

	void recAdd(int a, int b, int ia, int ib, int i) {
		if (ib < a || b < ia) return;
		if (a <=ia && ib<= b) {
			add[i] = true;
			val[i] = true;
		} else {
			int mid = (ia + ib) >> 1;
			recAdd(a, b, ia, mid, 2*i);
			recAdd(a, b, mid+1, ib, 2*i+1);
			update(i);
		}
	}

	bool query(int a, int b) {
		return recQuery(a, b, 0, h-1, 1);
	}
	void addVal(int a, int b) {
		recAdd(a, b, 0, h-1, 1);
	}
};

const int X = 301;
int divs[X];
vector<int> primes;
vector<int> invs;

vector<BoolTree> exs;
MultSegTree mults;

vector<bool> factor(int v) {
	vector<bool> res(primes.size(), 0);
	for (int i = 0; i < primes.size(); ++i) {
		if (v % primes[i] == 0) res[i] = true;
	}
	return res;
}

void makeChange(int a, int b, int v) {
	mults.multVal(a, b, v);

	vector<bool> pd = factor(v);
	for (int j = 0; j < primes.size(); ++j) {
		if (pd[j]) exs[j].addVal(a, b);
	}

	// 1 call to factor (62 moduloes)
	// 1 call to mults.multVal (32 modpows), each 64 moduloes
	// 62 calls to exs.addVal (32 boolean operations)
	// -> around 5000 work, most from multVal
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Linear sieve
	for (int v = 0; v < X; ++v) divs[v] = -1;
	for (int v = 2; v < X; ++v) {
		if (divs[v] == -1) {
			divs[v] = primes.size();
			primes.push_back(v);
		}
		for (int j = 0; j <= divs[v]; ++j) {
			int t = v * (primes[j]);
			if (t >= X) break;
			divs[t] = j;
		}
	}
	
	int pc = primes.size();
	invs.resize(pc);
	for (int i = 0; i < pc; ++i) {
		invs[i] = ((primes[i] - 1) * modPow(primes[i], MOD-2)) % MOD;
	}
	
	// solve
	int n, q;
	cin >> n >> q;
	
	exs.resize(pc);
	for (int i = 0; i < pc; ++i) exs[i].init(n);
	mults.init(n);

	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		makeChange(i, i, v);
	}

	for (int qi = 0; qi < q; ++qi) {
		string op;
		cin >> op;
		if (op == "TOTIENT") {
			int a, b;
			cin >> a >> b;
			--a; --b;

			ll res = mults.query(a, b);
			for (int j = 0; j < pc; ++j) {
				if (exs[j].query(a, b)) {
					res = (res * invs[j]) % MOD;
				}
			}
			cout << res << '\n';

			// 1 mults query, 62 exs queries
		} else {
			int a, b, v;
			cin >> a >> b >> v;
			--a; --b;
			makeChange(a, b, v);
		}
	}
}