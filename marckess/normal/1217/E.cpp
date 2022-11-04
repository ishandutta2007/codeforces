#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, q, op, l, r;
int a[2*MX][10], b[2*MX][10], res[10][2];

inline void add (int p, int i, int x) {
	if (x == -1) return;

	int &s = (p == -1 ? res[i][0] : a[p][i]);
	int &t = (p == -1 ? res[i][1] : b[p][i]);

	if (s == -1 || x < s) {
		t = s;
		s = x;
	} else if (t == -1 || x < t) {
		t = x;
	}
}

void update (int p, int x) {
	string s = to_string(x);
	reverse(all(s));

	p += n;
	memset(a[p], -1, sizeof(a[p]));
	memset(b[p], -1, sizeof(b[p]));

	for (int i = 0; i < s.size(); i++)
		if (s[i] != '0')
			a[p][i] = x;

 	for (; p > 1; p >>= 1) {
 		memset(a[p >> 1], -1, sizeof(a[p >> 1]));
		memset(b[p >> 1], -1, sizeof(b[p >> 1]));

 		forn (i, 10) {
 			add(p >> 1, i, a[p][i]);
 			add(p >> 1, i, b[p][i]);
 			add(p >> 1, i, a[p^1][i]);
 			add(p >> 1, i, b[p^1][i]);
 		}
 	}
}

void query (int l, int r) {
	memset(res, -1, sizeof(res));

	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) {
			forn(i, 10) {
				add(-1, i, a[l][i]);
				add(-1, i, b[l][i]);
			}
			l++;
		}
		if (r & 1) {
			r--;
			forn(i, 10) {
				add(-1, i, a[r][i]);
				add(-1, i, b[r][i]);
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(a, -1, sizeof(a));
	memset(b, -1, sizeof(b));
 
	scanf("%d%d", &n, &q);

	forn(i, n) {
		int x;
		scanf("%d", &x);
		update(i, x);
	}

	while (q--) {
		scanf("%d%d%d", &op, &l, &r);

		if (op == 1) {
			update(l - 1, r);
		} else {
			query(l - 1, r);
			int mn = int(2e9) + 5;

			forn (i, 10)
				if (res[i][1] != -1)
					mn = min(mn, res[i][0] + res[i][1]);
			if (mn != int(2e9) + 5) printf("%d\n", mn);
			else printf("-1\n");
		}
	} 

	return 0;
}