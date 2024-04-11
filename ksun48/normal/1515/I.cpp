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

const ll M = ll(1e17);
const int B = 18;

const ll INF = 2 * M;

const int NO = int(1e9);

struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
	ll madd = 0;
	ll val;
	// Node(int _lo,int _hi):lo(_lo),hi(_hi), val(INF){}
	Node(int _lo, int _hi, bool hello) : lo(_lo), hi(_hi) {
		val = INF;
		madd = 0;
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid, hello); r = new Node(mid, hi, hello);
		}
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return 2 * INF;
		if (L <= lo && hi <= R) return val;
		push();
		return min(l->query(L, R), r->query(L, R));
	}
	int leftmost(int L, int R, ll bound){
		if(R <= lo || hi <= L) return NO;
		if(L <= lo && hi <= R){
			if(val <= bound){
				if(lo + 1 == hi) return lo;
				push();
				int v = l->leftmost(L, R, bound);
				if(v != NO) return v;
				v = r->leftmost(L, R, bound);
				assert(v != NO);
				return v;
			} else {
				return NO;
			}
		} else {
			push();
			int v = l->leftmost(L, R, bound);
			if(v != NO) return v;
			v = r->leftmost(L, R, bound);
			return v;
		}
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = min(l->val, r->val);
		}
	}
	void push() {
		// if (!l) {
		// 	int mid = lo + (hi - lo)/2;
		// 	l = new Node(lo, mid); r = new Node(mid, hi);
		// }
		if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};


int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<ll> cnt0(n), wgt(n), val(n);
	vector<int> idx(n);
	vector<int> type(n);
	{
		vector<int> ord(n);
		vector<ll> _cnt(n), _wgt(n), _val(n);
		for(int i = 0; i < n; i++){
			cin >> _cnt[i] >> _wgt[i] >> _val[i];
			_val[i] = -_val[i];
		}
		for(int i = 0; i < n; i++) ord[i] = i;
		sort(ord.begin(), ord.end(), [&](int x, int y){
			return tie(_val[x], _wgt[x]) < tie(_val[y], _wgt[y]);
		});
		for(int i = 0; i < n; i++){
			cnt0[i] = _cnt[ord[i]];
			wgt[i] = _wgt[ord[i]];
			val[i] = -_val[ord[i]];
			idx[ord[i]] = i;
		}
	}
	for(int i = 0; i < n; i++){
		for(int b = 0; b < B; b++){
			if((1 << b) <= wgt[i]) type[i] = b;
		}
	}
	vector<ll> cnt(n, 0);
	vector<FT> val_ft(B, FT(n));
	vector<FT> wgt_ft(B, FT(n));
	vector<Node*> min_suff(B);
	for(int i = 0; i < B; i++){
		min_suff[i] = new Node(0, n, true);
	}
	auto upd = [&](int loc, ll del){
		for(int b = type[loc] + 1; b < B; b++){
			val_ft[b].update(loc, del * val[loc]);
			wgt_ft[b].update(loc, del * wgt[loc]);
		}
		for(int b = type[loc] + 1; b < B; b++){
			min_suff[b]->add(loc+1, n, del * wgt[loc]);
		}
		if((cnt[loc] == 0) && (cnt[loc] + del > 0)){
			min_suff[type[loc]]->add(loc, loc+1, wgt[loc] - INF);
		}
		if((cnt[loc] > 0) && (cnt[loc] + del == 0)){
			min_suff[type[loc]]->add(loc, loc+1, -(wgt[loc] - INF));
		}
		cnt[loc] += del;
	};
	for(int i = 0; i < n; i++){
		upd(i, cnt0[i]);
	}
	// cerr << "init ";
	// for(int i = 0; i < n; i++){
	// 	cerr << min_suff[2]->query(i, i+1) << ' ';
	// }
	// cerr << '\n';
	while(q--){
		int t;
		cin >> t;
		if(t == 1 || t == 2){
			ll k;
			int d;
			cin >> k >> d;
			d--;
			d = idx[d];
			if(t == 2) k = -k;
			upd(d, k);
			// for(int i = 0; i < n; i++){
			// 	cerr << cnt[i] << 'x' << wgt[i] << ' ' << val[i] << '\n';
			// }
		} else if(t == 3){
			ll c;
			cin >> c;
			ll ans = 0;
			int cur = 0;
			while(cur < n && c > 0){
				// cerr << "now " << cur << ' ' << c << '\n';
				int ctype = -1;
				for(int b = 0; b < B; b++){
					if((1 << b) <= c) ctype = b;
				}
				// cerr << "hi1" << '\n';
				ll pref_wgt_query = wgt_ft[ctype].query(cur);
				int lb = -1;
				if(ctype < (B-1)){
					int id = min_suff[ctype]->leftmost(cur, n, c + pref_wgt_query);
					if(id != NO){
						assert(id < n);
						assert(cnt[id] > 0);
						lb = id;
					}
				}
				// cerr << "hi2" << '\n';
				// cerr << lb << '\n';
				if(lb == -1){
					lb = wgt_ft[ctype].lower_bound(pref_wgt_query + c + 1);
				}
				c -= wgt_ft[ctype].query(lb) - pref_wgt_query;
				ans += val_ft[ctype].query(lb) - val_ft[ctype].query(cur);
				if(lb < n){
					assert(cnt[lb] > 0);
					ll take = min(cnt[lb], c / wgt[lb]);
					ans += take * val[lb];
					c -= take * wgt[lb];
					lb++;
				}
				cur = lb;
			}
			cout << ans << '\n';
		} else assert(false);
	}
}