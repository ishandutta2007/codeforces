
// Problem : E. Equilibrium
// Contest : Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1556/problem/E
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

const int MX = 100005;
int n, q, a[MX], b[MX];

struct Node {
	ll sum, pmx, pmn;
}st[4 * MX];

Node merge (const Node& a, const Node &b) {
	Node res;
	res.sum = a.sum + b.sum;
	res.pmx = max(a.pmx, a.sum + b.pmx);
	res.pmn = min(a.pmn, a.sum + b.pmn); 
	return res;
}

void build (int i, int j, int pos) {
	if (i == j) {
		st[pos] = {
			b[i] - a[i],
			b[i] - a[i],
			b[i] - a[i]
		};
		return;
	}
	
	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m + 1, j, pos * 2 + 1);
	st[pos] = merge(st[pos * 2], st[pos * 2 + 1]);
}

Node query (int i, int j, int pos, int a, int b) {
	if (b < i || j < a) return {0, 0, 0};
	if (a <= i && j <= b) return st[pos];
	
	int m = (i + j) / 2;
	return merge(
		query(i, m, pos * 2, a, b),
		query(m + 1, j, pos * 2 + 1, a, b)
	); 
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	
	build(1, n, 1);
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		Node res = query(1, n, 1, l, r);
		
		if (res.sum || res.pmn < 0) {
			cout << -1 << endl;
		} else {
			cout << res.pmx << endl;
		}
	}
	
	return 0;
}