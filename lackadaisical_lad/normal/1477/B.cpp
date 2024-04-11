#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, val = 0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vector<int>& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = l->val + r->val;
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R) + r->query(L, R);
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = x, val = x * (hi - lo);
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = l->val + r->val;
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
	}
};

void solve() {
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = t[i] - '0';
    Node *tr = new Node(v, 0, v.size());

    vector<int> l(q), r(q);
    for (int i = 0; i < q; i++)
        cin >> l[i] >> r[i];
    for (int i = q - 1; i >= 0; i--) {
        l[i]--;
        auto s = tr->query(l[i], r[i]);
        if (r[i] - l[i] == s * 2) {
            cout << "NO\n";
            return;
        }
        tr->set(l[i], r[i], s * 2 < r[i] - l[i] ? 0 : 1);
    }
    string res;
    for (int i = 0; i < n; i++)
        res += char(tr->query(i, i + 1) + '0');
    if (res == s)
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}