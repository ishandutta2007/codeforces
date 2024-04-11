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

const int MX = 100005;
int n, q;
ii d1[MX], d2[MX];
vii ini[MX], fin[MX];

struct Node {
	ll dp[2][2];
	vii ini;
	vii fin;
};
Node nulo;

ll dis (const ii &a, const ii &b) {
	return abs(a.fi - b.fi) + abs(a.se - b.se);
}

struct ST {
	Node st[4 * MX];
	
	Node merge (const Node &izq, const Node &der) {
		if (izq.ini[0].fi == -1) return der;
		if (der.ini[0].fi == -1) return izq;
		
		Node res;
		res.ini = izq.ini;
		res.fin = der.fin;
		
		forn (x, 2)
		forn (y, 2) {
			res.dp[x][y] = 1e18;
			
			forn (k, 2)
			forn (l, 2)
				res.dp[x][y] = min(
					res.dp[x][y],
					izq.dp[x][k] + dis(izq.fin[k], der.ini[l]) + der.dp[l][y]
				);
		}
		
		return res;
	}
	
	void build (int i, int j, int pos) {
		if (i == j) {
			ini[i] = st[pos].ini = {
				{d1[i - 1].fi + 1, d1[i - 1].se},
				{d2[i - 1].fi, d2[i - 1].se + 1},
			};
			
			fin[i] = st[pos].fin = {
				{d1[i].fi + 1, d1[i].se},
				{d2[i].fi, d2[i].se + 1},
			};
			
			memset(st[pos].dp, 0, sizeof(st[pos].dp));
			forn (x, 2)
			forn (y, 2)
				st[pos].dp[x][y] = dis(st[pos].ini[x], st[pos].fin[y]);
			
			return;
		}
		
		int m = (i + j) / 2;
		build(i, m, pos * 2);
		build(m + 1, j, pos * 2 + 1);
		
		st[pos] = merge(st[pos * 2], st[pos * 2 + 1]);
	}
	
	Node query (int i, int j, int pos, int a, int b) {
		if (b < i || j < a) return nulo;
		
		if (a <= i && j <= b) return st[pos];
		
		int m = (i + j) / 2;
		auto x = query(i, m, pos * 2, a, b);
		auto y = query(m + 1, j, pos * 2 + 1, a, b);
		return merge(x, y);
	}
}st;

void main_() {
	cin >> n;
	forr (i, 1, n - 1) {
		cin >> d1[i].fi >> d1[i].se >> d2[i].fi >> d2[i].se;
	}
	st.build(1, n, 1);
	
	cin >> q;
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		if (max(x1, y1) > max(x2, y2)) {
			swap(x1, x2);
			swap(y1, y2);
		}
		
		int x = max(x1, y1);
		int y = max(x2, y2);
		
		ii a = {x1, y1};
		ii b = {x2, y2};
		
		if (x == y) {
			cout << dis(a, b) << endl;
		} else if (x + 1 == y) {
			ll res = 1e18;
			
			forn (k, 2)
			forn (l, 2) {
				res = min(res, dis(a, fin[x][k]) + dis(fin[x][k], ini[y][l]) + dis(ini[y][l], b));
			}
			
			cout << res << endl;
		} else {
			Node t = st.query(1, n, 1, x + 1, y - 1);
			ll res = 1e18;
			
			forn (k, 2)
			forn (l, 2) {
				res = min(res, dis(a, t.ini[k]) + t.dp[k][l] + dis(t.fin[l], b));
			}
			
			cout << res << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	nulo.ini = nulo.fin = {{-1, -1}, {-1, -1}};
	
	int t = 1;
	//cin >> t;
	while (t--)
		main_();
	
	return 0;
}