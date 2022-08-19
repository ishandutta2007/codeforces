#include <bits/stdc++.h>
using namespace std;

void qssert(bool x){
	if(!x){
		cout << 0 << '\n';
		exit(0);
	}
}

vector<int> solve(vector<int> base_set, vector<vector<int> > conditions){
	if(conditions.size() == 0) return base_set;
	int qq = 0;
	for(int j = 0; j < conditions.size(); j++){
		if(conditions[j].size() > conditions[qq].size()) qq = j;
	}
	vector<vector<int> > stuff = {conditions[qq]};
	bool done = false;
	while(!done){
		done = true;
		vector<int> where(100, -1);
		for(int i = 0; i < stuff.size(); i++){
			for(int a : stuff[i]) where[a] = i;
		}
		for(int b = 0; b < conditions.size(); b++){
			vector<int> freq(stuff.size(), 0);
			int nowhere = 0;
			for(int x : conditions[b]){
				if(where[x] == -1){
					nowhere++;
				} else {
					freq[where[x]]++;
				}
			}
			if(nowhere == int(conditions[b].size())) continue; // set outside bounds
			if(nowhere > 0){
				// can deduce something
				qssert(freq.front() != int(stuff.front().size()) || freq.back() != int(stuff.back().size()));
				int side = -1;
				if(stuff.size() == 1){
					side = 0; // wlog
				} else if(freq.front() == stuff.front().size() || freq.back() == 0){
					side = 0;
				} else if(freq.front() == 0 || freq.back() == stuff.back().size()){
					side = 1;
				} else {
					qssert(false);
				}
				vector<int> outside;
				for(int x : conditions[b]){
					if(where[x] == -1) outside.push_back(x);
				}
				if(side == 0){
					stuff.insert(stuff.begin(), outside);
				} else if(side == 1){
					stuff.insert(stuff.end(), outside);
				}
				done = false;
				break;
			} else {
				int num_partials = 0;
				int num_overlap = 0;
				for(int i = 0; i < freq.size(); i++){
					if(0 < freq[i] && freq[i] < stuff[i].size()) num_partials++;
					if(0 < freq[i]) num_overlap++;
				}
				if(num_partials == 0){
					// this is completely useless?
					conditions.erase(conditions.begin() + b);
					done = false;
					break;
				}
				if(num_overlap == 1){
					//completely inside segment
					continue;
				}
				// inside segments
				/*cout << "STUFF:" << endl;
				cout << ">>>>>>>>>>" << endl;
				for(auto v : stuff){
					for(auto w : v){
						cout << w << ' ';
					}
					cout << '\n';
				}
				cout << ">>>>>>>>>>" << endl;
				for(int a : conditions[b]){
					cout << a << ' ';
				}
				cout << endl;
				for(int x : freq){
					cout << x << ' ';
				}
				cout << endl;*/
				int z = -1;
				for(int i = 0; i < freq.size(); i++){
					if(0 < freq[i] && freq[i] < stuff[i].size()) z = i;
				}
				//cout << "z " << z << endl;
				qssert(z != -1);
				int has_left = (z > 0) && (freq[z-1] > 0);
				int has_right = (z + 1 < freq.size()) && (freq[z+1] > 0);
				//cout << has_left << " " << has_right << endl;
				qssert(!has_left || !has_right);
				vector<int> common;
				vector<int> others;
				
				vector<int> q(100, 0);
				for(int v = 0; v < 100; v++){
					if(where[v] == z){
						q[v] = 1;
					}
				}
				for(int x : conditions[b]){
					if(where[x] == z){
						common.push_back(x);
						q[x] = 0;
					}
				}
				for(int v = 0; v < 100; v++){
					if(q[v] == 1) others.push_back(v);
				}
				qssert(common.size() && others.size());
				stuff.erase(stuff.begin() + z);
				if(has_left){
					stuff.insert(stuff.begin() + z, others);
					stuff.insert(stuff.begin() + z, common);
				} else if(has_right){
					stuff.insert(stuff.begin() + z, common);
					stuff.insert(stuff.begin() + z, others);
				}
				done = false;
				break;
			}
		}
	}
	vector<int> where(100, -1);
	for(int i = 0; i < stuff.size(); i++){
		for(int a : stuff[i]) where[a] = i;
	}
	vector<int> outside_elements;
	for(int x : base_set){
		if(where[x] == -1) outside_elements.push_back(x);
	}
	vector<vector<vector<int> > > new_conditions(stuff.size());
	vector<vector<int> > outside_conditions;
	for(int i = 0; i < conditions.size(); i++){
		qssert(conditions[i].size() > 0);
		int z = where[conditions[i][0]];
		for(int r : conditions[i]){
			qssert(z == where[r]);
		}
		if(z == -1){
			outside_conditions.push_back(conditions[i]);
		} else {
			new_conditions[z].push_back(conditions[i]);
		}
	}
	vector<int> ans = solve(outside_elements, outside_conditions);
	for(int i = 0; i < stuff.size(); i++){
		vector<int> z = solve(stuff[i], new_conditions[i]);
		ans.insert(ans.end(), z.begin(), z.end());
	}
	return ans;
}

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

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

using num = modnum<998244353>;

vector<num> fact, ifact;

void init(){
	int N = 1100000;
	fact = {1};
	for(int i = 1; i < N; i++) fact.push_back(i * fact[i-1]);
	ifact.resize(N);
	ifact.back() = 1 / fact.back();
	for(int i = N - 1; i > 0; i--) ifact[i-1] = i * ifact[i];
}

num ncr(int n, int k){
	if(k < 0 || k > n) return 0;
	return fact[n] * ifact[k] * ifact[n-k];
}


int main(){
	init();
	int n, m;
	cin >> n >> m;
	vector<vector<int> > conditions;
	conditions.resize(m);
	for(int i = 0; i < m; i++){
		int k;
		cin >> k;
		vector<int> a(k);
		for(int j = 0; j < k; j++){
			cin >> a[j];
			a[j]--;
		}
		conditions[i] = a;	
	}
	vector<int> base_set(n);
	for(int i = 0; i < n; i++) base_set[i] = i;
	vector<int> ans = solve(base_set, conditions);
	vector<int> q(n);
	for(int i = 0; i < n; i++){
		q[ans[i]] = i;
	}
	vector<pair<int,int> > p;
	for(int i = 0; i < m; i++){
		vector<int> z;
		for(int x : conditions[i]){
			z.push_back(q[x]);
		}
		sort(z.begin(), z.end());
		if(z.back() - z.front() != (int)z.size() - 1){
			cout << 0 << '\n';
			exit(0);
		}
		p.push_back({z.front(), z.back()+1});
	}

	num ways = 1;
	y_combinator(
		[&](auto self, int a, int b, vector<pair<int,int> > z) -> void {
			vector<int> cuts;
			for(int x = a; x <= b; x++){
				bool cut = true;
				for(auto [l, r] : z){
					if(l == a && r == b) continue;
					if(l < x && x < r){
						cut = false;
					}
				}
				if(cut) cuts.push_back(x);
			}
			if(cuts.size() > 2){
				ways *= fact[(int)cuts.size() - 1];
			} else if(a+1 == b){
				return;
			} else {
				int maxl = -1;
				for(auto [l, r] : z){
					if(l == a && r != b) maxl = max(maxl, r);
				}
				qssert(maxl != -1);
				cuts = {a, maxl, b};
				while(true){
					bool did = false;
					for(auto [l, r] : z){
						for(int x : cuts){
							if(l < x && x < r){
								vector<int> new_cuts = cuts;
								new_cuts.push_back(l);
								new_cuts.push_back(r);
								sort(new_cuts.begin(), new_cuts.end());
								new_cuts.resize(unique(new_cuts.begin(), new_cuts.end()) - new_cuts.begin());
								if(new_cuts.size() > cuts.size()){
									cuts = new_cuts;
									did = true;
								}
							}
						}
					}
					if(!did) break;
				}
				ways *= 2;
			}
			for(int j = 0; j + 1 < (int)cuts.size(); j++){
				vector<pair<int,int> > newz;
				for(auto [l, r] : z){
					if(cuts[j] <= l && r <= cuts[j+1]){
						newz.push_back({l, r});
					}
				}
				self(cuts[j], cuts[j+1], newz);
			}
		}
	)(0, n, p);
	cout << ways << '\n';
}