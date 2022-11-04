// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 400005;
int n, m, q, p[MX], sz[MX];
ll acu[MX], s, res[MX];
vvi a, e, in;

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

ll sum (int a, int b) {
	if (a > b) return 0;
	if (a) return acu[b] - acu[a - 1];
	return acu[b];
}

void join (int a, int b) {
	a = parent(a), b = parent(b);
	
	s -= sum(a - sz[a] + 1, a);
	s -= sum(b - sz[b] + 1, b);
	
	sz[b] += sz[a];
	p[a] = b;
	
	s += sum(b - sz[b] + 1, b);
}

void main_() {
	cin >> n >> m >> q;
	
	forn (i, n) {
		int x;
		cin >> x;
		a.pb({x, 1});
	}
	
	forn (i, m) {
		int x;
		cin >> x;
		a.pb({x, 0});
	}
	
	sort(all(a));
	
	forn (i, a.size()) {
		acu[i] = a[i][0];
		
		if (i) {
			acu[i] += acu[i - 1];
			e.pb({a[i][0] - a[i - 1][0], i - 1, i});
		}
		
		p[i] = i;
		sz[i] = a[i][1];
		s += a[i][0] * a[i][1];
	}
	sort(all(e));
	
	forn (i, q) {
		int k;
		cin >> k;
		in.pb({k, i});
	}
	sort(all(in));
	
	int j = 0;
	for (vi v : in) {
		while (j < (int)e.size() && e[j][0] <= v[0]) {
			join(e[j][1], e[j][2]);
			j++;
		}
		
		res[v[1]] = s;
	}
	
	forn (i, q)
		cout << res[i] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}