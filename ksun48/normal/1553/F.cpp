#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

const int M = 301000;
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<ll> score(M, 0);
	FT ftcnt(M+1);
	FT ftsum(M+1);

	FT ftmult(M+1);
	ll ans = 0;
	for(int x : a){
		ans += x * ftcnt.query(M);
		ans -= ftmult.query(x+1);
		for(int v = 0; v < M; v += x){
			ans += ftsum.query(min(M, v+x)) - ftsum.query(v) - v * (ftcnt.query(min(M, v+x)) - ftcnt.query(v));
		}
		for(int v = x; v < M; v += x){
			ftmult.update(v, x);
		}
		ftcnt.update(x, 1);
		ftsum.update(x, x);
		cout << ans << ' ';
	}
	cout << '\n';
}