#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, q, a[MX];

ll mn[4 * MX], sum[4 * MX], lz[4 * MX];

void build (int i, int j, int pos) {
	if (i == j) {
		mn[pos] = sum[pos] = a[i];
		return;	
	}
	
	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m + 1, j, pos * 2 + 1);
	
	sum[pos] = sum[pos * 2] + sum[pos * 2 + 1];
	mn[pos] = min(mn[pos * 2], mn[pos * 2 + 1]);
}

void push (int i, int j, int pos) {
	if (i < j) {
		lz[pos * 2] = lz[pos];
		lz[pos * 2 + 1] = lz[pos];
	}
	
	sum[pos] = ll(j - i + 1) * lz[pos];
	mn[pos] = lz[pos];
	lz[pos] = 0;
}

void update (int i, int j, int pos, int a, int b, int k) {
	if (lz[pos]) push(i, j, pos);
	if (j < a || b < i) return;
	if (a <= i && j <= b) {
		lz[pos] = k;
		push(i, j, pos);
		return;
	}
	int m = (i + j) / 2;
	update(i, m, pos * 2, a, b, k);
	update(m + 1, j, pos * 2 + 1, a, b, k);
	
	sum[pos] = sum[pos * 2] + sum[pos * 2 + 1];
	mn[pos] = min(mn[pos * 2], mn[pos * 2 + 1]);
}

ll query (int i, int j, int pos, int a, int b) {
	if (lz[pos]) push(i, j, pos);
	if (j < a || b < i) return 0;
	if (a <= i && j <= b) return sum[pos];
	int m = (i + j) / 2;
	return query(i, m, pos * 2, a, b) + query(m + 1, j, pos * 2 + 1, a, b);
}

int find (int k) {
	int i = 1, j = n, pos = 1;
	
	while (i < j) {
		int m = (i + j) / 2;
		
		if (lz[pos]) push(i, j, pos);
		if (lz[pos * 2]) push(i, m, pos * 2);
		
		if (mn[pos * 2] <= k) {
			j = m;
			pos = pos * 2;
		} else {
			i = m + 1;
			pos = pos * 2 + 1;
		}
	}
	
	if (lz[pos]) push(i, j, pos);
	
	if (mn[pos] > k) return n + 1;
	return i;
}

int upper_bound (ll k) {
	int i = 1, j = n, pos = 1;
	
	if (sum[1] <= k) return n + 1;
	
	while (i < j) {
		int m = (i + j) / 2;
		
		if (lz[pos]) push(i, j, pos);
		if (lz[pos * 2]) push(i, m, pos * 2);
		
		if (sum[pos * 2] > k) {
			j = m;
			pos = pos * 2;
		} else {
			k -= sum[pos * 2];
			i = m + 1;
			pos = pos * 2 + 1;
		}
	}
	
	if (lz[pos]) push(i, j, pos);
	
	return i;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	build(1, n, 1);
	
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		
		if (t == 1) {
			int i = find(y);
			if (i <= x)
				update(1, n, 1, i, x, y);
		} else {
			int res = 0;
			
			while (x <= n) {
				ll z = y;
				
				if (x > 1)
					z += query(1, n, 1, 1, x - 1);
				
				int to = upper_bound(z) - 1;
				
				if (to >= x) {
					res += to - x + 1;
					y -= query(1, n, 1, x, to);
				}
				
				x = max(to + 1, find(y));
			}
			
			cout << res << endl;
		}
	}
	
	return 0;
}