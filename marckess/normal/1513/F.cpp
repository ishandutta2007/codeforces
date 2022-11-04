#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 400005;
int n, a[MX], ma[MX], b[MX], mb[MX], qa[MX], qb[MX];
ll pre[MX], suf[MX], res, mn;
vi c;

void update (int i, ll k, ll ft[], int f) {
	while (i && i < MX) {
		ft[i] = min(ft[i], k);
		i += f * (i & -i);
	}
}

ll query (int i, ll ft[], int f) {
	ll res = 1e18;
	while (i && i < MX) {
		res = min(res, ft[i]);
		i -= f * (i & -i);
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		c.pb(a[i]);
	}
	forn (i, n) {
		cin >> b[i];
		c.pb(b[i]);
		res += abs(a[i] - b[i]);
	}
	
	sort(all(c));
	c.erase(unique(all(c)), c.end());
	
	forn (i, n) {
		ma[i] = upper_bound(all(c), a[i]) - c.begin();
		mb[i] = upper_bound(all(c), b[i]) - c.begin();
	}
	
	iota(qa, qa + n, 0);
	iota(qb, qb + n, 0);
	
	sort(qa, qa + n, [&] (int i, int j) { return a[i] < a[j]; });
	sort(qb, qb + n, [&] (int i, int j) { return b[i] < b[j]; });
	
	fill(pre, pre + MX, 1e18);
	fill(suf, suf + MX, 1e18);
	
	for (int i = 0, j = 0; i < n; i++) {
		int x = qa[i], y;
		
		while (j < n && b[y = qb[j]] <= a[x]) {
			update(ma[y], -b[y] - a[y] - abs(a[y] - b[y]), pre, 1);
			update(ma[y], -b[y] + a[y] - abs(a[y] - b[y]), suf, -1);
			
			j++;
		}
		
		mn = min({
			mn,
			query(mb[x], pre, 1) + a[x] + b[x] - abs(a[x] - b[x]),
			query(mb[x], suf, -1) + a[x] - b[x] - abs(a[x] - b[x]),
		});
	}
	
	fill(pre, pre + MX, 1e18);
	fill(suf, suf + MX, 1e18);
	
	for (int i = n - 1, j = n - 1; i >= 0; i--) {
		int x = qa[i], y;
		
		while (j >= 0 && b[y = qb[j]] >= a[x]) {
			update(ma[y], b[y] - a[y] - abs(a[y] - b[y]), pre, 1);
			update(ma[y], b[y] + a[y] - abs(a[y] - b[y]), suf, -1);
			
			j--;
		}
		
		mn = min({
			mn,
			query(mb[x], pre, 1) - a[x] + b[x] - abs(a[x] - b[x]),
			query(mb[x], suf, -1) - a[x] - b[x] - abs(a[x] - b[x]),
		});
	}
	
	cout << res + mn << endl;
    
	return 0;
}