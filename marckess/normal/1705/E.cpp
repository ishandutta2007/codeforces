#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

const int MX = 200005, lim = 20;

struct Node {
	ll ned, nex;
	int sz;
};

Node merge (Node izq, Node der) {
	if (izq.nex >= der.ned) {
		izq.nex -= der.ned;
		der.nex++;
		der.ned = 1 << min(der.sz, lim);
	}

	der.nex += izq.nex / der.ned;
	der.ned -= izq.nex % der.ned;
	
	Node res;
	res.ned = izq.ned;
	if (der.ned) {
		res.ned += (der.ned - 1) * (1ll << min(izq.sz, lim));
	}
	res.ned = min(res.ned, 1ll << lim);
	res.nex = der.nex;
	res.sz = izq.sz + der.sz;
	
	return res;
}

struct ST {
	Node st[4 * MX];
	
	void update (int i, int j, int pos, int a, int k) {
		if (a < i || j < a) return;
		
		if (i == j) {
			st[pos].nex = k / 2;
			st[pos].ned = 2 - k % 2;
			st[pos].sz = 1;
			return;
		}
		
		int m = (i + j) / 2;
		update(i, m, pos * 2, a, k);
		update(m + 1, j, pos * 2 + 1, a, k);
		
		st[pos] = merge(st[pos * 2], st[pos * 2 + 1]);
	}
	
	Node query (int i, int j, int pos, int a) {
		if (j <= a) return st[pos];
		
		int m = (i + j) / 2;
		
		Node x = query(i, m, pos * 2, a);
		if (a <= m) return x;
		
		Node y = query(m + 1, j, pos * 2 + 1, a);
		return merge(x, y);
	}
}st;

int n, q, a[MX], cn[MX], k, l;
multiset<int> mst;

void main_() {
	cin >> n >> q;
	forr (i, 1, n) {
		cin >> a[i];
		cn[a[i]]++;
		mst.insert(a[i]);
	}
	
	forr (i, 1, 2e5)
		st.update(1, 2e5, 1, i, cn[i]);
	
	while (q--) {
		cin >> k >> l;
		
		st.update(1, 2e5, 1, a[k], --cn[a[k]]);
		mst.erase(mst.find(a[k]));
		
		a[k] = l;
		st.update(1, 2e5, 1, a[k], ++cn[a[k]]);
		mst.insert(a[k]);
		
		int mx = *mst.rbegin();
		auto res = st.query(1, 2e5, 1, mx);
		
		int nex = res.nex;
		while (nex) {
			mx++;
			nex /= 2;
		}
		cout << mx << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}