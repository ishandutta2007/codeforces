#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int mod;
int a[N];

int add(int x,int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int mul(int x,int y) {
	return (long long) x * y % mod;
}

int power(int x,int y) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}

pair<int, int> extgcd(int a,int b) {
	if (b == 0) {
		return make_pair(1, 0);
	}
	pair<int, int> nxt = extgcd(b, a % b);
	return make_pair(nxt.second, nxt.first - a / b * nxt.second);
}

int inv(int x) {
	int ans = extgcd(x, mod).first % mod;
	if (ans < 0) {
		ans += mod;
	}
	return ans;
}

int t[N << 2], lz[N << 2];

#define md ((l + r) >> 1)
void push(int v,int l,int r) {
	if (lz[v] != 1) {
		t[v] = mul(t[v], lz[v]);
		if (l < r) {
			lz[v << 1] = mul(lz[v << 1], lz[v]);
			lz[v << 1 | 1] = mul(lz[v << 1 | 1], lz[v]);
		}
		lz[v] = 1;
	}
}

void upd(int v,int l,int r,int p,int val) {
	push(v, l, r);
	if (p > r || p < l) {
		return;
	}
	if (l == r) {
		t[v] = val;
		return;
	}
	upd(v << 1, l, md, p, val);
	upd(v << 1 | 1, md + 1, r, p, val);
	t[v] = add(t[v << 1], t[v << 1 | 1]);
}

void mul(int v,int l,int r,int L,int R,int val) {
	push(v, l, r);
	if (L > r || R < l) {
		return;
	}
	if (L <= l && R >= r) {
		lz[v] = val;
		push(v, l, r);
		return;
	}
	mul(v << 1, l, md, L, R, val);
	mul(v << 1 | 1, md + 1, r, L, R, val);
	t[v] = add(t[v << 1], t[v << 1 | 1]);
}

int get(int v,int l,int r,int L,int R) {
	push(v, l, r);
	if (L > r || R < l) {
		return 0;
	}
	if (L <= l && R >= r) {
		return t[v];
	} 
	return add(get(v << 1, l, md, L, R), get(v << 1 | 1, md + 1, r, L, R));
}

int n;
int f[N], f2[15][N];

void upd(int p,int val) {
	for (; p <= n; p += p & -p) {
		f[p] = mul(f[p], val);
	}
}

int get(int p) {
	int ans = 1;
	for (; p > 0; p -= p & -p) {
		ans = mul(ans, f[p]);
	}
	return ans;
}

void add(int id,int p,int val) {
	for (; p <= n; p += p & -p) {
		f2[id][p] += val;
	}
}

int get(int id,int p) {
	int ans = 0;
	for (; p > 0; p -= p & -p) {
		ans += f2[id][p];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> mod;
	int nw = mod;
	vector<int> pr;
	for (int i = 2; i * i <= nw; ++i) {
		if (nw % i == 0) {
			pr.push_back(i);
			while (nw % i == 0) {
				nw /= i;
			}
		}
	}
	if (nw > 1) {
		pr.push_back(nw);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i] = 1;
	} 
	for (int i = 1; i <= n; ++i) {
		upd(1, 1, n, i, a[i] % mod);
		int x = a[i];
		for (int j = 0; j < (int) pr.size(); ++j) {
			int cnt = 0;
			while (x % pr[j] == 0) {
				x /= pr[j];
				++cnt;
			}
			add(j, i, cnt);
			add(j, i + 1, -cnt);
		}
		x %= mod;
		upd(i, x);
		upd(i + 1, inv(x));
	}
	int q;
	cin >> q;
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			mul(1, 1, n, l, r, x);
			for (int i = 0; i < (int) pr.size(); ++i) {
				int cnt = 0;
				while (x % pr[i] == 0) {
					x /= pr[i];
					++cnt;
				}
				add(i, l, cnt);
				add(i, r + 1, -cnt);
			}
			x %= mod;
			upd(l, x);
			upd(r + 1, inv(x));
		} else if (op == 2) {
			int p, x; 
			cin >> p >> x;
			int val = 1;
			for (int i = 0; i < (int) pr.size(); ++i) {
				int cnt = 0;
				while (x % pr[i] == 0) {
					x /= pr[i];
					++cnt;
				}
				add(i, p, -cnt);
				add(i, p + 1, cnt);
				val = mul(val, power(pr[i], get(i, p)));
			}
			x %= mod;
			upd(p, inv(x));
			upd(p + 1, x);
			val = mul(val, get(p));
			upd(1, 1, n, p, val);
		} else {
			int l, r; 
			cin >> l >> r;
			cout << get(1, 1, n, l, r) << '\n';
		}
	}
}