
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.

ll modpow(ll a, ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

typedef vector<ll> vl;
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, mod >> s)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}

vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = modpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

const int N = 3e5 + 5;
int a[N], b[5];
vector<vl> ve;
vl poly[5];

vl solve(int l, int r) {
    if(l == r) return ve[l];
    int m = (l + r) / 2;
    return conv(solve(l, m), solve(m + 1, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<int, int> cnt;
    int n, k;
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    rep(i, 0, k) {
        cin >> b[i];
        ve.clear();
        for(auto &p : cnt) {
            if(p.first >= b[i]) continue;
            if(p.second >= 2) {
                ve.push_back({1, 2, 1});
            }else {
                ve.push_back({1, 2});
            }
        }
        if(!ve.empty()) {
            poly[i] = solve(0, sz(ve) - 1);
        }else {
            poly[i].assign(1, 1);
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int Q;
        cin >> Q;
        Q /= 2;
        ll s = 0;
        rep(i, 0, k) {
            if(Q - b[i] - 1 >= 0 && Q - b[i] - 1 < sz(poly[i])) {
                s += poly[i][Q - b[i] - 1];
            }
        }
        s %= mod;
        cout << s << '\n';
    }
}