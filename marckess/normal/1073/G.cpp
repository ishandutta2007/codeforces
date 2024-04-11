#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, LMX = 19;

int st[MX][LMX];

void obtST (int a[], int n) {
	for (int i = 0; i < n; i++)
		st[i][0] = a[i];

	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 0; i + (1 << j) - 1 < n; i++)
			st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
}

int query (int i, int j) {
	int k = log2(j-i+1);
	return min(st[i][k], st[j-(1<<k)+1][k]);
}

int sa[MX], lcp[MX], inv[MX];

void countingSort (string &s, int ra[], int k) {
	int t_sa[MX] = {0}, c[MX] = {0};
    int sum, n = s.size(), mx = max(300, n);

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

void obtSA (string &s) {
	int t_ra[MX] = {0}, ra[MX] = {0};
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

void obtLCP (string &s) {
    int phi[MX], plcp[MX], n = s.size();

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

int n, q, acu[MX];
string s;

ll solve (vi &c) {
	ll res = 0, acu = 0;
	stack<ii> st;
	sort(all(c));

	for (int i = 1; i < c.size(); i++) {
		ll mn = query(c[i-1]+1, c[i]), cn = 1;
		
		while (st.size() && st.top().fi > mn) {
			acu -= (ll)st.top().fi * st.top().se;
			cn += st.top().se;
			st.pop();
		}

		acu += mn * cn;
		st.emplace(mn, cn);
		res += acu;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q >> s;

	s.pb('$');
	n++;

	obtSA(s);
	obtLCP(s);
	obtST(lcp, n);

	for (int i = 0; i < n; i++) inv[sa[i]] = i;

	while (q--) {
		int k, l;
		cin >> k >> l;

		vi a(k), b(l), c;

		for (int &x : a) {
			cin >> x;
			x--;
			c.pb(inv[x]);
			acu[x] = 1;
		}

		for (int &x : b) {
			cin >> x;
			x--;
			if (!acu[x]) c.pb(inv[x]);
			acu[x] += 2;
		}

		ll res = solve(c);
		c.clear();
		for (int x : a)
			if (acu[x] == 1)
				c.pb(inv[x]);
		res -= solve(c);

		c.clear();
		for (int x : b)
			if (acu[x] == 2) 
				c.pb(inv[x]);
		res -= solve(c);

		c.clear();
		for (int x : a)
			if (acu[x] == 3) {
				c.pb(inv[x]);
				res += n - 1 - x;
			}
		res += solve(c);

		cout << res << endl;

		for (int x : a) acu[x] = 0;
		for (int x : b) acu[x] = 0;
	}

	return 0;
}