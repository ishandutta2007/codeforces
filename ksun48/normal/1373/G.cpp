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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, k, m;
	cin >> n >> k >> m;
	set<pair<int,int> > cur;
	k--;
	Node segtree(0, 2*n+1);
	for(int i = 0; i <= 2*n; i++){
		segtree.set(i, i+1, i - 2*n);
	}
	multiset<int> rows;
	auto upd = [&](int row, int dir) -> void {
		if(dir == 1){
			rows.insert(row);
		} else {
			rows.erase(rows.find(row));
		}
		segtree.add(0, row+1, dir);
	};
	rows.insert(n-1);
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		if(cur.count({x, y})){
			cur.erase({x, y});
			upd(y + abs(x - k), -1);
		} else {
			cur.insert({x, y});
			upd(y + abs(x - k), 1);
		}
		int v = *rows.rbegin();
		int ans = max(0, n + segtree.query(0, v+1));
		cout << ans << '\n';
	}
}