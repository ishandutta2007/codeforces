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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, SQ = 320;
int n, m, q, ult;
ll a[MX], b[MX], x[MX], y[MX];
ll mn[SQ], mx[SQ], sum[SQ], off[SQ], pre[MX], tot, acu, ini;

void update (int blo) {
	sum[blo] = 0;
	
	for (int i = blo * SQ; i < (blo + 1) * SQ && i < m - 1; i++) {
		y[i] += off[blo];
		
		mx[blo] = y[i];
		sum[blo] += y[i];
		
		pre[i] = y[i];
		if (blo * SQ < i)
			pre[i] += pre[i - 1];
	}
	
	mn[blo] = y[blo * SQ];
	off[blo] = 0;
}

ll query () {
	ll res = ini * (n + m - 1) + acu, s = tot - sum[ult];
	int j = ult;
	
	for (int i = n - 2; i >= 0; i--) {
		while (j >= 0 && x[i] < mn[j] + off[j]) {
			j--;
			if (j >= 0) s -= sum[j];
		}
		
		ll o = j >= 0 ? off[j] : 0;
		if (j == ult && mx[j] + o < x[i]) {
			res += tot;
			res += x[i] * (n - 1 - i);
		} else if (j >= 0) {
			int l = j * SQ, r = min((j + 1) * SQ - 1, m - 2);
			
			while (l < r) {
				int m = (l + r + 1) / 2;
				if (y[m] + o <= x[i]) l = m;
				else r = m - 1; 
			}
			
			res += s + pre[l] + o * (l - j * SQ + 1);
			res += x[i] * ((n - 1 - i) + (m - 2 - l));
		} else {
			res += x[i] * ((n - 1 - i) + (m - 1));
		}
	}
	
	return res;
}

void main_() {
	cin >> n >> m >> q;
	forn (i, n) cin >> a[i];
	forn (i, m) cin >> b[i];
	
	forn (i, n - 1) x[i] = a[i + 1] - a[i];
	forn (i, m - 1) y[i] = b[i + 1] - b[i];
	
	ini = a[0] + b[0];
	
	forn (i, m)
		if (i * SQ < m - 1) {
			update(i);
			ult = i;
		} else break;
		
	forn (i, m - 1) {
		tot += y[i];
		acu += y[i] * (m - 1 - i);
	}
	
	while (q--) {
		int op, k, d;
		cin >> op >> k >> d;
		
		if (op == 1) {
			forn (i, min(k, n - 1))
				x[n - 2 - i] += d;
			
			if (k == n)
				ini += d;
		} else {
			int k_ = min(k, m - 1);
			tot += d * k_;
			acu += 1ll * d * k_ * (k_ + 1) / 2;
			
			int j = m - 1 - k_, blo = j / SQ;
			for (int i = j; i < (blo + 1) * SQ && i < m - 1; i++)
				y[i] += d;
			update(blo);
			
			for (int i = blo + 1; i <= ult; i++) {
				off[i] += d;
				sum[i] += d * min(SQ, (m - 1) - i * SQ);
			}
			
			if (k == m)
				ini += d;
		}
		
		cout << query() << endl;
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