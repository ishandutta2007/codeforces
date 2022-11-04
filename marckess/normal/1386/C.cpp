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

const int MX = 200005;
int n, m, q, mn[MX], u[MX], v[MX];
int p[MX], f[MX], rk[MX];

struct Data {
	int p, u, a, b, inc, isp;
};
stack<Data> save;
int cp;

void init () {
	while (save.size()) save.pop();
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		f[i] = 0;
		rk[i] = 0;
	}
}

ii parent (int a) {
	int c = 0;
	while (a != p[a]) {
		c ^= f[a];
		a = p[a];
	}
	return {a, c};
}

bool join (int a, int b, int g) {
	ii pa = parent(a), pb = parent(b);
	
	if (pa.fi == pb.fi) {
		if (pa.se == pb.se) return 0;
		
		save.push({pa.fi, pb.fi, a, b, 0, g});
		cp += g;
		return 1;
	}
	
	if (rk[pa.fi] < rk[pb.fi]) swap(pa, pb);
	
	save.push({pa.fi, pb.fi, a, b, rk[pa.fi] == rk[pb.fi], g});
	cp += g;
	
	p[pb.fi] = pa.fi;
	f[pb.fi] = 1 ^ pa.se ^ pb.se;
	rk[pa.fi] += rk[pa.fi] == rk[pb.fi];
	
	return 1;
}

ii pop (const Data &d) {
	cp -= d.isp;
	p[d.u] = d.u;
	f[d.u] = 0;
	rk[d.p] -= d.inc;
	return {d.a, d.b};
}

void pop () {
	vii a, b;
	
	if (!cp) {
		while (save.size()) {
			a.pb(pop(save.top()));
			save.pop();
		}
	} else if (!save.top().isp) {
		do {
			if (save.top().isp) a.pb(pop(save.top()));
			else b.pb(pop(save.top()));
			save.pop();
		} while (cp && a.size() != b.size());
	
		reverse(all(a));
		reverse(all(b));
	}
	
	for (ii &p : b) join(p.fi, p.se, 0);
	for (ii &p : a) join(p.fi, p.se, 1);
	
	pop(save.top());
	save.pop();
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;
	init();
	
	int f = 1;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i];
		f &= join(u[i], v[i], 0);
	}
	
	if (f) {
		while (q--) {
			int l, r;
			cin >> l >> r;
			cout << "NO" << endl;
		}
		return 0;
	}
	
	init();
	for (int i = 1, j = 1; i <= m; i++) {
		while (join(u[j], v[j], 0)) {
			j++;
			if (j > m) j = 1;
		}
		
		mn[i] = j;
		pop();
		
		if (i == m) {
			while (join(u[j], v[j], 0)) {
				j++;
				if (j > m) j = 1;
			}
			mn[m + 1] = j;
		}
	}
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (mn[r + 1] >= r + 1) cout << "YES" << endl;
		else if (l > mn[r + 1]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}