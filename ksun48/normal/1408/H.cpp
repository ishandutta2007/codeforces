#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = 0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<vector<int> > where(n+1);
	for(int i = 0; i < n; i++){
		where[a[i]].push_back(i);
	}
	int nd = 0;
	for(int i = 1; i <= n; i++){
		if(!where[i].empty()){
			where[i].insert(where[i].begin(), -1);
			where[i].insert(where[i].end(), n);
			nd++;
		}
	}
	Node* segtree = new Node(0, n+1);

	vector<int> zeros = where[0];
	int m = (int)zeros.size() / 2;
	int maxval = 0;
	vector<vector<int> > ins_where(m);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j + 1 < (int)where[i].size(); j++){
			int v1 = lower_bound(zeros.begin(), zeros.end(), where[i][j]) - zeros.begin();
			int v2 = lower_bound(zeros.begin(), zeros.end(), where[i][j+1]) - zeros.begin();
			if(v1 >= m || v2 < (int)zeros.size() - m) continue;
			ins_where[v1].push_back(v2 - ((int)zeros.size() - m));
		}
	}
	segtree->set(0, m, 0);
	for(int j = 0; j < m; j++){
		segtree->add(j, m, 1);
	}
	int cval = 0;
	for(int j = 0; j < m; j++){
		for(int r : ins_where[j]){
			cval += 1;
			segtree->add(r, m, -1);
		}
		maxval = max(maxval, cval + segtree->query(0, m));
		cval -= 1;
	}
	cout << min(m, m - (maxval - nd)) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}