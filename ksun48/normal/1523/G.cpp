#include <bits/stdc++.h>
using namespace std;

const int Z = int(2e5);

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

const int SZ = 1<<17;
template<class T> struct node {
	T val = Z; node<T>* c[2];
	node() { c[0] = c[1] = NULL; }
	void upd(int ind, T v, int L = 0, int R = SZ-1) { // add v
		if (L == ind && R == ind) { val = min(val, v); return; }
		int M = (L+R)/2;
		if (ind <= M) {
			if (!c[0]) c[0] = new node();
			c[0]->upd(ind,v,L,M);
		} else {
			if (!c[1]) c[1] = new node();
			c[1]->upd(ind,v,M+1,R);
		}
		val = Z; F0R(i,2) if (c[i]) val = min(val, c[i]->val);
	}
	T query(int lo, int hi, int L = 0, int R = SZ-1) { // query sum of segment
		if (hi < L || R < lo) return Z;
		if (lo <= L && R <= hi) return val;
		int M = (L+R)/2; T res = Z;
		if (c[0]) res = min(res, c[0]->query(lo,hi,L,M));
		if (c[1]) res = min(res, c[1]->query(lo,hi,M+1,R));
		return res;
	}
	void UPD(int ind, node* c0, node* c1, int L = 0, int R = SZ-1) { // for 2D segtree
		if (L != R) {
			int M = (L+R)/2;
			if (ind <= M) {
				if (!c[0]) c[0] = new node();
				c[0]->UPD(ind,c0?c0->c[0]:NULL,c1?c1->c[0]:NULL,L,M);
			} else {
				if (!c[1]) c[1] = new node();
				c[1]->UPD(ind,c0?c0->c[1]:NULL,c1?c1->c[1]:NULL,M+1,R);
			}
		} 
		val = min((c0?c0->val:Z), (c1?c1->val:Z));
	}
};

template<class T> struct Node {
	node<T> seg; Node* c[2];
	Node() { c[0] = c[1] = NULL; }
	void upd(int x, int y, T v, int L = 0, int R = SZ-1) { // add v
		if (L == x && R == x) { seg.upd(y,v); return; }
		int M = (L+R)/2;
		if (x <= M) {
			if (!c[0]) c[0] = new Node();
			c[0]->upd(x,y,v,L,M);
		} else {
			if (!c[1]) c[1] = new Node();
			c[1]->upd(x,y,v,M+1,R);
		}
		seg.upd(y,v); // only for addition
		// seg.UPD(y,c[0]?&c[0]->seg:NULL,c[1]?&c[1]->seg:NULL);
	}
	T query(int x1, int x2, int y1, int y2, int L = 0, int R = SZ-1) { // query sum of rectangle
		if (x1 <= L && R <= x2) return seg.query(y1,y2);
		if (x2 < L || R < x1) return Z;
		int M = (L+R)/2; T res = Z;
		if (c[0]) res = min(res, c[0]->query(x1,x2,y1,y2,L,M));
		if (c[1]) res = min(res, c[1]->query(x1,x2,y1,y2,M+1,R));
		return res;
	}
};

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

const int R = 100000;

using B = bitset<R>;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> l(m), r(m);
	for(int i = 0; i < m; i++){
		cin >> l[i] >> r[i];
		l[i]--;
		r[i]--;
	}
	vector<vector<int> > which(n+1);
	for(int i = 0; i < m; i++) which[r[i] - l[i] + 1].push_back(i);
	Node<int> tree;
	vector<int> pr;
	for(int L = n; L >= 1; L--){
		for(int x : which[L]){
			tree.upd(l[x], r[x], x);
		}
		int ans = 0;
		y_combinator(
			[&](auto self, int s, int e) -> void {
				if(e-s+1 < L) return;
				int x = tree.query(s, e, s, e); // get best
				if(x == Z) return;
				ans += r[x] - l[x] + 1;
				self(s, l[x] -1);
				self(r[x] + 1, e);
			}
		)(0, n-1);
		pr.push_back(ans);
	}
	reverse(pr.begin(), pr.end());
	for(int x : pr) cout << x << '\n';
}