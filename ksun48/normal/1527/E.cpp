#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

// Either globally or in a single class:
static char buf[230 << 20];
void* operator new(size_t s) {
	static size_t i = sizeof buf;
	assert(s < i);
	return (void*)&buf[i -= s];
}
void operator delete(void*) {}

const ll inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
	ll mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ll M = ll(1e15);
	vector<ll> dp(n+1, -M);
	dp[0] = 0;
	Node* tree = new Node(dp, 0, n+1);
	for(int c = 0; c < k; c++){
		for(int i = 0; i <= n; i++){
			tree->set(i, i+1, dp[i]);
		}
		vector<ll> newdp(n+1, -M);
		vector<int> last_occ(n+1, -1);
		for(int j = 1; j <= n; j++){
			int prv = last_occ[a[j-1]];
			last_occ[a[j-1]] = j-1;
			if(prv != -1){
				int cost = (j-1) - prv;
				tree->add(0, prv+1, -cost);
			}
			newdp[j] = tree->query(0, j);
		}
		dp = newdp;
	}
	cout << (-dp[n]) << '\n';
}