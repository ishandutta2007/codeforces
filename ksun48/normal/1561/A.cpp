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
	int lo, hi, mset = inf, madd = 0, val = -inf;
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

int solve(vector<int> a){
	int n = (int)a.size();
	bool sorted = true;
	for(int i = 0; i < n; i++) if(a[i] != i) sorted = false;
	if(sorted){
		return 0;
	}
	for(int i = 0; i+1 < n; i += 2){
		if(a[i] > a[i+1]) swap(a[i], a[i+1]);
	}
	vector<int> loc(n);
	for(int i = 0; i < n; i++) loc[a[i]] = i;
	vector<int> r(n+1, 0);
	for(int i = 0; i <= n; i++) r[i] = n-i;
	Node segtree(r, 0, n+2);
	int ans = 0;
	int min1 = n;
	int max0 = n-1;
	for(int i = n-1; i > 0; i--){
		segtree.add(loc[i]+1, n+2, 1);
		segtree.add(0, loc[i]+1, -1);
		min1 = min(min1, loc[i]);
		while(a[max0] >= i) max0--;
		ans = max(ans, segtree.query(min1, max0+1));
	}
	return 1 + max(ans - 1, 0);
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int& x : a){
			cin >> x;
			x--;
		}
		int ans = solve(a);
		cout << ans << '\n';
	}
}