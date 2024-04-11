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

struct Node {
	ll izq, der, sum, mx;
};

Node merge (const Node &a, const Node &b) {
	Node res;
	res.izq = max(a.izq, a.sum + b.izq);
	res.der = max(a.der + b.sum, b.der);
	res.sum = a.sum + b.sum;
	res.mx = max({a.mx, b.mx, a.der + b.izq});
	return res;
}

int n, q, a[(1 << 18) + 5];

vector<Node> dfs (int i, int j, int lvl) {
	if (lvl == -1) {
		Node res;
		res.izq = max(0, a[i]);
		res.der = max(0, a[i]);
		res.sum = a[i];
		res.mx = max(0, a[i]);
		return {res};
	}
	
	int m = (i + j) / 2;
	auto izq = dfs(i, m, lvl - 1);
	auto der = dfs(m + 1, j, lvl - 1);
	
	vector<Node> res(izq.size() << 1);
	forn (i, izq.size()) {
		res[i] = merge(izq[i], der[i]);
		res[i ^ (1 << lvl)] = merge(der[i], izq[i]);
	}
	
	return res;
}

void main_() {
	cin >> n;
	forr (i, 1, (1 << n))
		cin >> a[i];
	
	auto res = dfs(1, 1 << n, n - 1);
	
	int off = 0;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		off ^= 1 << k;
		
		cout << res[off].mx << endl;
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