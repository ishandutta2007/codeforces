//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

using namespace std;

//~ #include <ext/pb_ds/assoc_container.hpp>
//~ #include <ext/pb_ds/tree_policy.hpp>
//~ using namespace __gnu_pbds;
//~ template <typename T>
//~ using ordered_set =
	//~ tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#ifdef LOCAL
mt19937 rng(unsigned(69));
#else
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif
#define rand rng

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

struct node{
  node *l, *r, *p;
  int size,val,sum;
  bool flip;
  node(int _val): l(0), r(0), p(0), val(_val){}
  void update(){
  }
  void touch(){
  }
  void touch_path(){
    if(p) p->touch_path();
    touch();
  }
  node*& get_child(bool right){
    return right ? r : l;
  }
  static void add_child(node* x, node* q, bool right){
    if(x) x->get_child(right) = q;
    if(q) q->p = x;
  }
  inline bool is_right(){
    return p && p->r == this;
  }
  void rotate(){
    if(!p) return;
    node *oldp = p;
    bool right = is_right();
    add_child(p->p, this, p->is_right());
    add_child(oldp, get_child(!right), right);
    add_child(this, oldp, !right);
    oldp->update();
    update();
  }
  void splay_(){
    while(p){
      if(is_right() ^ p->is_right())
        rotate();
      else
        p->rotate();
      rotate();
    }
  }
  void splay(){ //dla nieodwracalych splay'ow zastapic przez splay_
    touch_path();
    splay_();
  }
  void set_val(int nval){
    val = nval;
    update();
  }
  void reverse(){
    flip = !flip;
  }
  node* get_first(){
    node* res = this;
    while(1){
      res->touch();
      if(!res->l) break;
      res = res->l;
    }
    res->splay_();
    return res;
  }
  node* remove() {
    if(l) l->p = nullptr;
    if(r) r->p = nullptr;
    node* root = join(l, r);
    l = r = nullptr;
    return root;
  }
  static node* join(node* a, node* b){
    if(!a) return b;
    while(1){
      a->touch();
      if(!a->r) break;
      a = a->r;
    }
    a->splay_();
    add_child(a, b, true);
    a->update();
    return a;
  }
  ~node(){ delete l; delete r; }
};

struct SegTree {
	vi data;
	int base;

	SegTree() {}
	SegTree(int n) : base(1) {
		while (base < n + 2) { base *= 2; }
		data.resize(base * 2);
	}

	void Set(int v, int x) {
		//~ debug() << imie("Set") << imie(v) << imie(x);
		v += base;
		while (v) {
			data[v] = max(data[v], x);
			v /= 2;
		}
	}

	int GetMax(int L, int R) {
		if (L > R) { return 0; }
		L += base; R += base;
		int ans = max(data[L], data[R]);
		while (L / 2 != R / 2) {
			if (L % 2 == 0) { ans = max(ans, data[L + 1]); }
			if (R % 2 == 1) { ans = max(ans, data[R - 1]); }
			L /= 2; R /= 2;
		}
		return ans;
	}
};

//~ struct ContraSegTree {
	//~ struct Node {
		//~ ll sum;
		//~ ll minpref;
		//~ ll minsuf;
		//~ ll minin;

		//~ Node() : sum(0), minpref(0), minsuf(0), minin(0) {}
		//~ Node(ll a, ll b, ll c, ll d)
			//~ : sum(a), minpref(b), minsuf(c), minin(d) {}

		//~ Node Join(const Node &rhs) const {
			//~ return
				//~ {sum + rhs.sum,
				 //~ min(minpref, sum + rhs.minpref),
				 //~ min(minsuf + rhs.sum, rhs.minsuf),
				 //~ min({minin, rhs.minin, minsuf + rhs.minpref})};
		//~ }
	//~ };

	//~ vector<Node> data;
	//~ int base;

	//~ ContraSegTree() {}
	//~ ContraSegTree(int n) : base(1) {
		//~ while (base < n + 2) { base *= 2; }
		//~ data.resize(base * 2);
	//~ }

	//~ void Add(int v, int val) {
		//~ v += base;
		//~ data[v].sum += val;
		//~ data[v].minpref = max<ll>(0, data[v].sum);
		//~ data[v].minsuf = data[v].minin = data[v].minpref;

		//~ v /= 2;
		//~ while (v) {
			//~ data[v] = data[v*2].Join(data[v*2+1]);
		//~ }
	//~ }

	//~ ll GetMin() const {
		//~ return data[1].minin;
	//~ }
//~ };

const int kMaxN = 2e5;

SegTree segtree;
node *unrated[kMaxN];
int n, m;
ll dist_root[kMaxN];
int parent[kMaxN];
int init_up[kMaxN];
int cur_dn[kMaxN];
vector<pii> children[kMaxN];
bool is_init[kMaxN];

int preorder[kMaxN], postorder[kMaxN];
int curpre;


void InitPath(int root) {
	unrated[root] = new node(root);
	node *cur = unrated[root];
	int curver = cur_dn[root];
	is_init[root] = true;
	while (curver) {
		is_init[curver] = true;
		node *nxt = new node(curver);
		unrated[curver] = nxt;
		node::add_child(cur, nxt, true);
		nxt->splay_();
		cur = nxt;
		curver = cur_dn[curver];
	}
}

void DfsTree(int v) {
	preorder[v] = curpre++;
	if (!is_init[v]) {
		InitPath(v);
	}
	for (auto [s, c] : children[v]) {
		dist_root[s] = dist_root[v] + c;
		DfsTree(s);
	}
	postorder[v] = curpre;
}

vector<pll> intervals;

ll FindLastDn(int p) {
	//~ debug() << imie(p) << imie(preorder[p]) << imie(postorder[p]);
	int ans = segtree.GetMax(preorder[p] + 1, postorder[p] - 1);
	if (ans == 0) {
		return -1e18;
	} else {
		return ans;
	}
}

void FindPath(int dest, int starttm) {
	node *tree = unrated[dest];
	tree->splay_();
	debug() << imie(dest) << imie(starttm);

	while (true) {
		tree = tree->get_first();
		int top = tree->val;
		debug() << imie(top);
		if (top == 1) { break; }

		int pnt = parent[top];
		debug() << imie(pnt);

		ll last_train = max<ll>(0, FindLastDn(pnt) + dist_root[pnt]);
		ll need_change = starttm + dist_root[pnt];
		debug() << imie(last_train) << imie(need_change);
		intervals.emplace_back(last_train + 1, need_change);

		node *tpnt = unrated[pnt];
		tpnt->splay_();
		assert(tpnt->r);
		tpnt->r->p = nullptr;
		tpnt->r = nullptr;
		node::add_child(tpnt, tree, true);
		tree = tpnt;
		tree->splay_();
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n >> m;
	segtree = SegTree(n + 1);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		parent[v] = u;
		cur_dn[u] = v;
		children[u].emplace_back(v, c);
	}

	DfsTree(1);

	for (int i = 0; i < m; ++i) {
		int dest, start;
		cin >> dest >> start;
		FindPath(dest, start);
		segtree.Set(preorder[dest], start);
	}

	sort(ALL(intervals), [&](const pii &lhs, const pii &rhs) {
		return lhs.nd < rhs.nd;
	});
	debug() << imie(intervals);
	cerr << SZ(intervals) << "\n";

	auto CanHave = [&](int sz) {
		vector<pii> queries(intervals.begin(), intervals.begin() + sz);
		sort(ALL(queries));

		int cur_tm = 0;
		multiset<int> cur_ends;
		for (auto &&[start_tm, end_tm] : queries) {
			while (!cur_ends.empty() && cur_tm < start_tm) {
				if (*cur_ends.begin() < cur_tm) {
					return false;
				}
				cur_ends.erase(cur_ends.begin());
				++cur_tm;
			}
			if (cur_ends.empty()) {
				cur_tm = start_tm;
			}
			cur_ends.insert(end_tm);
		}
		while (!cur_ends.empty()) {
			if (*cur_ends.begin() < cur_tm) {
				return false;
			}
			cur_ends.erase(cur_ends.begin());
			++cur_tm;
		}
		return true;
	};

	int L = 0, R = SZ(intervals) + 1;
	const double coef = 0.2;
	while (R - L > 1) {
		int mid = coef * L + (1 - coef) * R;
		if (mid == L) { ++mid; }
		if (mid == R) { --mid; }
		if (CanHave(mid)) {
			L = mid;
		} else {
			R = mid;
		}
	}

	if (L == SZ(intervals)) {
		cout << "-1 " << SZ(intervals) << "\n";
		return 0;
	}

	int ans = intervals[R - 1].nd;
	int nchanges = R;
	while (nchanges > 0 && intervals[nchanges - 1].nd >= ans) {
		--nchanges;
	}
	cout << ans << " " << nchanges << "\n";
}