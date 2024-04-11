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
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; i++){
		cin >> p[i];
		p[i]--;
	}
	vector<int> invp(n);
	for(int i = 0; i < n; i++){
		invp[p[i]] = i;
	}
	vector<int> q(n);
	for(int i = 0; i < n; i++){
		cin >> q[i];
		q[i]--;
	}
	vector<int> s(n, 0); // large
	vector<int> e(n, n); // small
	// elements at least x to be large

	vector<int> init(n+1, 0);
	Node* tr = new Node(init, 0, n+1);
	int cur = n;
	for(int i = 0; i < n; i++){
		// add bomb to q[i];
		// segtree add q[i]
		while(tr->query(0, n+1) == 0){
			cur--;
			tr->add(0, invp[cur]+1, 1);
		}
		s[i] = cur;
		tr->add(0, q[i]+1, -1);
	}
	for(int i = 0; i < n; i++){
		cout << s[i] + 1 << ' ';
	}
	cout << '\n';
}