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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005, LG = 20, SQ = 225;
 
int sa[MX], lcp[MX], f[MX];
 
int t_sa[MX] = {0}, c[MX] = {0};
void countingSort (string &s, int ra[], int k) {
    int sum, n = s.size(), mx = max(300, n);
    memset(t_sa, 0, sizeof(t_sa));
    memset(c, 0, sizeof(c));
 
    for (int i = 0; i < n; i++)
        c[i+k<n?ra[i+k]:0]++;
 
    for (int i = sum = 0; i < mx; i++) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
 
    for (int i = 0; i < n; i++)
        t_sa[c[sa[i]+k<n?ra[sa[i]+k]:0]++] = sa[i];
 
    for (int i = 0; i < n; i++) sa[i] = t_sa[i];
}
 
int t_ra[MX] = {0}, ra[MX] = {0};
void obtSA (string &s) {
    int r, n = s.size();
 
    for (int i = 0; i < n; i++) ra[i] = s[i];
    for (int i = 0; i < n; i++) sa[i] = i;
 
    for (int k = 1; k < n; k <<= 1) {
        countingSort(s, ra, k);
        countingSort(s, ra, 0);
 
        t_ra[s[0]] = r = 0;
 
        for (int i = 1; i < n; i++)
            if (ra[sa[i]] == ra[sa[i-1]] && ra[sa[i]+k] == ra[sa[i-1]+k])
                t_ra[sa[i]] = r;
            else
                t_ra[sa[i]] = ++r;
 
        for (int i = 0; i < n; i++) ra[i] = t_ra[i];
        if (ra[sa[n-1]] == n-1) break;
    }
}
 
int phi[MX], plcp[MX];
void obtLCP (string &s) {
    int n = s.size();
 
    phi[sa[0]] = -1;
    for (int i = 1; i < n; i++) phi[sa[i]] = sa[i-1];
 
    for (int i = 0, l = 0; i < n; i++) {
        if (phi[i] == -1) {
            plcp[i] = 0;
            continue;
        }
 
        while (s[i+l] == s[phi[i]+l]) l++;
 
        plcp[i] = l;
        l = max(l-1, 0);
    }
 
    for (int i = 0; i < n; i++) lcp[i] = plcp[sa[i]];
}
 
int M[MX][LG], logTable[MX];
 
void pre(int n, int A[]) {
	for (int i = 2; i <= n; i++)
		logTable[i] = logTable[i >> 1] + 1;
	
	for (int i = 0; i < n; i++)
    	M[i][0] = A[i];
 
  	for(int j = 1; (1 << j) <= n; j++)
    	for(int i = 0; i + (1 << j) - 1 < n; i++)
			M[i][j] = min(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]);
}
 
int query (int i, int j) {
	if (i > j) return 1e9;
	int k = logTable[j - i + 1];
	return min(M[i][k], M[j - (1 << k) + 1][k]);
}

int q, m;
string s, t[MX];
vi a, b, sz;
vvi qr;
ii st[MX], res[MX];

void build () {
	for (int i = 2 * m - 1; i; i--) {
		if (i >= m) st[i] = {0, -(i - m)};
		else st[i] = max(st[i << 1], st[(i << 1) | 1]);
	}
}

void update (int i, int k) {
	for (st[i += m].fi += k; i > 1; i >>= 1)
		st[i >> 1] = max(st[i], st[i ^ 1]);
}

ii query_mx (int a, int b) {
	ii res(-1, -1);
	for (a += m, b += m; a <= b; a >>= 1, b >>= 1) {
		if (a & 1) res = max(res, st[a++]);
		if (~b & 1) res = max(res, st[b--]);
	}
	return res;
}

int lower_bound (int u, int len) {
	int i = 0, j = u, rep = 20;
	
	while (rep--) {
		int m = (i + j) / 2;
		if (query(m + 1, u) >= len) j = m;
		else i = m;
	}
	
	j = lower_bound(all(b), j) - b.begin();
	
	return j;
}

int upper_bound (int u, int len) {
	int i = u, j = int(s.size()) - 1, rep = 20;
	
	while (rep--) {
		int m = (i + j + 1) / 2;
		if (query(u + 1, m) >= len) i = m;
		else j = m;
	}
	
	i = upper_bound(all(b), i) - b.begin();
	i--;
	
	return i;
}


int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s >> m;
	forn (i, m) {
		cin >> t[i];
		sz.pb(s.size() + 1);
		s += '#' + t[i];
	}
	s += char('#' - 1);
	
	obtSA(s);
	obtLCP(s);
	pre(s.size(), lcp);
	
	forn (i, s.size()) {
		f[sa[i]] = i;
		
		int t = upper_bound(all(sz), sa[i]) - sz.begin();
		t--;
		
		if (t >= 0 && s[sa[i]] != '#') {
			a.pb(t);
			b.pb(i);
		}
	}
	
	cin >> q;
	
	forn (i, q) {
		int l, r, pl, pr;
		cin >> l >> r >> pl >> pr;
		l--, r--, pl--, pr--;
		
		int ini = pl;
		int len = pr - pl + 1;
		
		pl = lower_bound(f[ini], len);
		pr = upper_bound(f[ini], len);
		
		if (pl <= pr)
			qr.pb({pl, pr, l, r, i});
		else
			res[i] = {0, -l};
	}
	
	sort(all(qr), [&] (const vi &a, const vi &b) {
		int blo_a = a[0] / SQ, blo_b = b[0] / SQ;
		if (blo_a ^ blo_b) return blo_a < blo_b;
		if (blo_a & 1) return a[1] > b[1];
		return a[1] < b[1];
	});
	
	build();
	
	int l = 0, r = -1;
	
	for (vi &q : qr) {
		while (r < q[1]) update(a[++r], 1);
		while (r > q[1]) update(a[r--], -1);
		while (l < q[0]) update(a[l++], -1);
		while (l > q[0]) update(a[--l], 1);
		
		res[q[4]] = query_mx(q[2], q[3]);
	}
	
	forn (i, q)
		cout << -res[i].se + 1 << " " << res[i].fi << endl;

	return 0;
}