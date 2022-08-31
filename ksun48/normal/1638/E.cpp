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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, Q;
	cin >> n >> Q;
	map<int,pair<int,int> > cur_intervals;
	cur_intervals[-1e9] = {-1e9, 0};
	cur_intervals[1e9] = {1e9, 0};
	cur_intervals[0] = {n-1, 1};

	vector<ll> color_value(n+1, 0);
	FT ft(n+1);
 
	auto insert_interval = [&](int x, int y, int c) {
		ft.update(x, -color_value[c]);
		ft.update(y+1, color_value[c]);
		cur_intervals[x] = {y, c};
	};
	auto delete_interval = [&](int x, int y, int c) {
		ft.update(x, color_value[c]);
		ft.update(y+1, -color_value[c]);
		cur_intervals.erase(x);
	};
	auto set_false = [&](int l, int r){
		while(true){
			auto f = cur_intervals.lower_bound(l);
			if(f != cur_intervals.end()){
				auto [x, y2] = *f;
				auto [y, c] = y2;
				if(max(l, x) <= min(r, y)){
					delete_interval(x, y, c);
					if(x < l) insert_interval(x, l-1, c);
					if(r < y) insert_interval(r+1, y, c);
					continue;
				}
			}
			if(f != cur_intervals.begin()){
				f = prev(f);
				auto [x, y2] = *f;
				auto [y, c] = y2;
				if(max(l, x) <= min(r, y)){
					delete_interval(x, y, c);
					if(x < l) insert_interval(x, l-1, c);
					if(r < y) insert_interval(r+1, y, c);
					continue;
				}
			}
			break;
		}
	};
	auto set_true = [&](int l, int r, int c){
		set_false(l, r);
		insert_interval(l, r, c);
	};
	for(int i = 0; i < Q; i++){
		string type;
		cin >> type;
		if(type == "Color"){
			int l, r, c;
			cin >> l >> r >> c;
			l--; r--;
			set_true(l, r, c);
		} else if(type == "Add"){
			int c, x;
			cin >> c >> x;
			color_value[c] += x;
		} else if(type == "Query"){
			int x;
			cin >> x;
			x--;
			int c = (*prev(cur_intervals.upper_bound(x))).second.second;
			cout << (color_value[c] + ft.query(x+1)) << '\n';
		}
	}
}