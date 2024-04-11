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


const int MAXN = 1000000;
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	ll ans = 1;
	vector<vector<int> > ins(MAXN+1), del(MAXN+1);
	for(int i = 0; i < n; i++){
		int y, x1, x2;
		cin >> y >> x1 >> x2;
		ins[x1].push_back(y);
		del[x2].push_back(y);
		ans--;
		if(x1 == 0) ans++;
		if(x2 == MAXN) ans++;
	}
	vector<vector<int> > pos(MAXN+1), neg(MAXN+1);
	for(int i = 0; i < m; i++){
		int x, y1, y2;
		cin >> x >> y1 >> y2;
		pos[x].push_back(y2+1);
		neg[x].push_back(y1);
		ans--;
		if(y1 == 0) ans++;
		if(y2 == MAXN) ans++;
	}

	FT ft(MAXN+2);
	for(int j = 0; j <= MAXN; j++){
		for(int a : ins[j]){
			ft.update(a, 1);
		}
		for(int r : pos[j]){
			ans += ft.query(r);
		}
		for(int r : neg[j]){
			ans -= ft.query(r);
		}
		for(int a : del[j]){
			ft.update(a, -1);
		}
	}
	cout << ans << '\n';
}