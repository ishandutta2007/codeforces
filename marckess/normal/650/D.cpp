#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 400005, mod = 1e9+9;

struct ST {
	int mx[8*MX];
	ll cn[8*MX];

	void init (int i, int j, int pos) {
		mx[pos] = -1, cn[pos] = 0;

		if (i < j) {
			int m = (i+j)/2;
			init(i, m, pos*2);
			init(m+1, j, pos*2+1);
		}
	}

	void update (int i, int j, int pos, int x, int k, int y) {
		if (x < i || j < x)
			return;

		if (i == j) {
			if (k > mx[pos]) {
				mx[pos] = k;
				cn[pos] = y;
			} else if (k == mx[pos]) {
				cn[pos] += y;
				if (cn[pos] > mod)
					cn[pos] -= mod;
			}
			return;
		}

		int m = (i+j)/2;
		update(i, m, pos*2, x, k, y);
		update(m+1, j, pos*2+1, x, k, y);

		mx[pos] = max(mx[pos*2], mx[pos*2+1]);
		cn[pos] = cn[pos*2] * (mx[pos] == mx[pos*2]) + cn[pos*2+1] * (mx[pos] == mx[pos*2+1]);
		if (cn[pos] > mod)
			cn[pos] -= mod;
	}

	ii query (int i, int j, int pos, int x) {
		if (x <= i)
			return {-1, 0};

		if (j < x)
			return {mx[pos], cn[pos]};

		int m = (i+j)/2;
		ii a = query(i, m, pos*2, x);
		ii b = query(m+1, j, pos*2+1, x);

		ii c(max(a.fi, b.fi), 0);
		c.se = a.se * (a.fi == c.fi) + b.se * (b.fi == c.fi);
		if (c.se > mod)
			c.se -= mod;
		return c;
	}
}st;

int n, m, h[MX], a[MX], b[MX], res[MX], mx;
ll cn = 0;
vi con, q[MX];
ii rec[MX];
bitset<MX> nec;

#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
	
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
    	cin >> h[i];
    	con.push_back(h[i]);
    }

    for (int i = 0; i < m; i++) {
    	cin >> a[i] >> b[i];
    	q[--a[i]].push_back(i);
    	con.push_back(b[i]);
    }

    sort(ALL(con));
    con.erase(unique(ALL(con)), con.end());

    for (int i = 0; i < n; i++)
    	h[i] = find(con, h[i]);
    
    for (int i = 0; i < m; i++)
    	b[i] = find(con, b[i]);

    //De izquierda a derecha
    st.init(1, con.size()+1, 1);
    st.update(1, con.size()+1, 1, 1, 0, 1);
    for (int i = 0; i < n; i++) {
    	for (int x : q[i])
    		res[x] = st.query(1, con.size() + 1, 1, b[x]+2).fi + 1;

    	rec[i] = st.query(1, con.size()+1, 1, h[i]+2);
    	mx = max(mx, ++rec[i].fi);
    	if (rec[i].se <= 0) {
    		cout << rec[i].se << endl;
    		return -1;
    	}
    	st.update(1, con.size()+1, 1, h[i]+2, rec[i].fi, rec[i].se);
    }

    for (int i = 0; i < n; i++)
    	if (rec[i].fi == mx) {
    		cn += rec[i].se;
    		if (cn > mod)
    			cn -= mod;
    	}

    //De derecha a izquierda
    st.init(1, con.size()+1, 1);
    st.update(1, con.size()+1, 1, 1, 0, 1);
    for (int i = n - 1; i >= 0; i--) {
    	for (int x : q[i])
    		res[x] += st.query(1, con.size()+1, 1, con.size() + 1 - b[x]).fi;

    	ii aux = st.query(1, con.size()+1, 1, con.size() + 1 - h[i]);
    	rec[i].fi += aux.fi, rec[i].se *= aux.se, rec[i].se %= mod;
    	if (aux.se <= 0) {
    		cout << aux.se << endl;
    		return -2;
    	}
    	if (rec[i].se <= 0) {
    		cout << rec[i].se << endl;
    		return -3;
    	}
    	st.update(1, con.size()+1, 1, con.size() + 1 - h[i], aux.fi+1, aux.se);
    }

    for (int i = 0; i < n; i++)
    	if (rec[i].fi == mx && rec[i].se == cn)
    		nec[i] = 1;

    for (int i = 0; i < m; i++)
    	cout << max(res[i], mx - nec[a[i]]) << endl;

    return 0;
}