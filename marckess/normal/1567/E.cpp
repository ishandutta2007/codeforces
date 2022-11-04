
// Problem : E. Non-Decreasing Dilemma
// Contest : Codeforces - Codeforces Round #742 (Div. 2)
// URL : https://codeforces.com/contest/1567/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;

struct Node {
	ll res;
	int pre, suf, beg, end;
	bool all;
};

ll add (ll x) {
	return x * (x + 1) / 2;
}

struct ST {
	Node st[4 * MX];
	
	Node merge (Node a, Node b) {
		if (!a.pre) return b;
		if (!b.pre) return a;
		
		Node c;
		c.res = a.res + b.res;
		c.beg = a.beg;
		c.end = b.end;
		
		c.all = a.all && b.all && a.end <= b.beg;
		if (a.all && a.end <= b.beg) {
			c.pre = a.pre + b.pre;
		} else {
			c.pre = a.pre;
		}
		
		if (b.all && a.end <= b.beg) {
			c.suf = a.suf + b.suf;
		} else {
			c.suf = b.suf;
		}
		
		if (a.end <= b.beg) {
			if (!a.all && !b.all) {
				c.res += add(a.suf + b.pre);
			}
		} else {
			if (!a.all) {
				c.res += add(a.suf);
			}
			if (!b.all) {
				c.res += add(b.pre);
			}
		}
		
		return c;
	}
	
	void update (int i, int j, int pos, int a, int k) {
		if (a < i || j < a) return;
		
		if (a <= i && j <= a) {
			st[pos] = {0, 1, 1, k, k, 1};
			return;
		}
		
		int m = (i + j) / 2;
		update(i, m, pos * 2, a, k);
		update(m + 1, j, pos * 2 + 1, a, k);
		
		st[pos] = merge(st[pos * 2], st[pos * 2 + 1]);
	}
	
	Node query (int i, int j, int pos, int a, int b) {
		if (b < i || j < a) return {0, 0, 0, 0, 0, 0};
		
		if (a <= i && j <= b) return st[pos];
		
		int m = (i + j) / 2;
		auto x = query(i, m, pos * 2, a, b);
		auto y = query(m + 1, j, pos * 2 + 1, a, b);
		
		return merge(x, y);
	}
}st;

int n, q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		
		st.update(1, n, 1, i, a);
	}
	
	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;
		
		if (t == 1) st.update(1, n, 1, l, r);
		else {
			auto res = st.query(1, n, 1, l, r);
			cout << res.res + add(res.pre) + int(!res.all) * add(res.suf) << endl;
		}
	}
	
	return 0;
}