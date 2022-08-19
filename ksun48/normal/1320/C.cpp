#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = 2e12;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
	ll mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vector<ll>& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, ll x) {
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

const int MAXN = 1.1e6;
vector<pair<int,ll> > monsters[MAXN];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<ll> wcost(MAXN, -inf);

	vector<ll> bcost(MAXN, -inf);
	int n, m, p;
	cin >> n >> m >> p;
	for(int i = 0; i < n; i++){
		int a;
		ll c;
		cin >> a >> c;
		a--;
		wcost[a] = max(wcost[a], -c);
	}
	for(int i = 0; i < m; i++){
		int b;
		ll c;
		cin >> b >> c;
		b--;
		bcost[b] = max(bcost[b], -c);
	}
	Node segtree(wcost, 0, MAXN);
	for(int i = 0; i < p; i++){
		int x, y;
		ll z;
		cin >> x >> y >> z;
		monsters[y].push_back({x, z});
	}
	ll best = -inf;
	for(int i = 0; i < MAXN; i++){
		for(pair<int,ll> a : monsters[i]){
			segtree.add(a.first, MAXN, a.second);
		}
		ll cost = segtree.query(0, MAXN);
		cost += ll(bcost[i]);
		best = max(best, cost);
	}
	cout << best << '\n';
}