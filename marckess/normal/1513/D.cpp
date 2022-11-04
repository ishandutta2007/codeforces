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

const int MX = 200005, mod = 1000000007;
int n, x, a[MX], izq[MX], der[MX];
int p[MX], mn[MX], mx[MX];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	a = parent(a), b = parent(b);
	
	if (a == b) return;
	
	p[a] = b;
	mn[b] = min(mn[b], mn[a]);
	mx[b] = max(mx[b], mx[a]);
}

void solve () {
	cin >> n >> x;
	forn (i, n)
		cin >> a[i];
	
	map<int, int> mp;
	forn (i, n) {
		map<int, int> act;
		act[a[i]] = i;
		
		for (auto it = mp.begin(); it != mp.end(); it++) {
			int x = __gcd(a[i], it->fi);
			
			if (act.count(x))
				act[x] = min(act[x], it->se);
			else
				act[x] = it->se;
		}
		
		mp = act;	
		izq[i] = mp.rbegin()->se;
	}
	
	mp.clear();
	for (int i = n - 1; i >= 0; i--) {
		map<int, int> act;
		act[a[i]] = i;
		
		for (auto it = mp.begin(); it != mp.end(); it++) {
			int x = __gcd(a[i], it->fi);
			
			if (act.count(x)) 
				act[x] = max(act[x], it->se);
			else
				act[x] = it->se;
		}
		
		mp = act;
		der[i] = mp.rbegin()->se;
	}
	
	vii v;
	forn (i, n)
		v.pb({a[i], i});
	
	forn (i, n)
		p[i] = mx[i] = mn[i] = i;
	
	ll res = 0;
	int comp = n;
	
	sort(all(v));
	for (ii &k : v) {
		if (k.fi >= x) {
			break;
		}
		
		int l = izq[k.se];
		int r = der[k.se];
		int cn = 1;
		
		while (1) {
			int t = parent(l);
			if (mx[t] >= r)
				break;
			
			cn++;
			join(mx[t], mx[t] + 1);
			comp--;
		}
		
		res += 1ll * k.fi * (cn - 1);
	}
			res += 1ll * x * (comp - 1);
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}