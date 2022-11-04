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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, SQ = 2155;

struct query {
	int l, r, k, q, i;
	bool operator < (const query &ot) const {
		if ((l / SQ) ^ (ot.l / SQ)) return l < ot.l;
		if ((r / SQ) ^ (ot.r / SQ)) return r < ot.r;
		return q < ot.q;
	}
};

int n, m, a[MX], b[MX], res[MX], p[MX], x[MX], y[MX];
int ant[MX + 1], sig[MX], cn[MX], occ[MX];
vector<query> vq;

void insert (int u, int izq, int der) {
	ant[u] = izq;
	sig[u] = der;
	sig[izq] = u;
	ant[der] = u;
}

void erase (int u, int izq, int der) {
	sig[izq] = der;
	ant[der] = izq;
}

void add (int k) {
	int u = occ[k]++;
	
	if (!cn[u + 1]) insert(u + 1, u, sig[u]);
	cn[u + 1]++;
	
	cn[u]--;
	if (!cn[u]) erase(u, ant[u], sig[u]);
}

void remove (int k) {
	int u = occ[k]--;
	
	if (!cn[u - 1]) insert(u - 1, ant[u], u);
	cn[u - 1]++;
	
	cn[u]--;
	if (!cn[u]) erase(u, ant[u], sig[u]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	
	for (int i = 1, last = 0; i <= m; i++) {
		int op;
		cin >> op;
		
		if (op == 1) {
			int l, r, k;
			cin >> l >> r >> k;
			vq.pb({l, r, k, last, i});
		} else {
			cin >> p[i] >> x[i];
			y[i] = b[p[i]];
			b[p[i]] = x[i];
			last = i;
		}
	}
	
	sort(all(vq));
	
	cn[0] = MX;
	sig[0] = MX;
	
	for (int i = 1; i <= n; i++)
		b[i] = a[i];
	
	int i = 1, j = 0, k = 0;
	for (auto &q : vq) {
		while (q.l < i) add(b[--i]);
		while (j < q.r) add(b[++j]);
		while (q.l > i) remove(b[i++]);
		while (j > q.r) remove(b[j--]);
		while (k < q.q) {
			k++;
			if (p[k]) {
				if (i <= p[k] && p[k] <= j) {
					remove(b[p[k]]);
					add(b[p[k]] = x[k]);
			    } else b[p[k]] = x[k];
			}
		}
		while (k > q.q) {
			if (p[k]) {
				if (i <= p[k] && p[k] <= j) {
					remove(b[p[k]]);
					add(b[p[k]] = y[k]);
				} else b[p[k]] = y[k];
			}
			k--;
		}
		
		res[q.i] = 1e9;
		
		int l = sig[0], r = l, act = cn[l];
		
		do {
			while (act < q.k && sig[r] < MX) {
				r = sig[r];
				act += cn[r];
			}
			
			if (act >= q.k)
				res[q.i] = min(res[q.i], r - l);
			
			act -= cn[l];
			l = sig[l];
		} while (l < MX);
		
		if (res[q.i] == 1e9) res[q.i] = -1;
	}
	
	for (int i = 1; i <= m; i++)
		if (!p[i])
			cout << res[i] << endl;
	
	return 0;
}