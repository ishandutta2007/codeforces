#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1000005, mod = 998244353;
int n, ft[MX], dp[MX], res;
string a, l, r, s, t;
vi x, y;

int query (int i) {
	int sum = 0;
	while (i) {
		sum += ft[i];
		sum %= mod;
		i -= i & -i;
	}
	return sum;
}

int query (int i, int j) {
	int d = query(j) - query(i-1);
	return MOD(d, mod);
}

void update (int i, int k) {
	while (i < n+1) {
		ft[i] += k;
		ft[i] %= mod;
		i += i & -i;
	}
}

void obtZF (string s, vi &zf) {
    int n = s.size();
    zf.resize(n);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            zf[i] = min (r - i + 1, zf[i - l]);
        while (i + zf[i] < n && s[zf[i]] == s[i + zf[i]])
            zf[i]++;
        if (i + zf[i] - 1 > r)
            l = i, r = i + zf[i] - 1;
    }
}


int izq (int i) {
	int f = x[l.size()+i];

	if (f >= l.size()) return i+l.size();
	if (l.size() + i + f == x.size()) return n+1;
	if (s[l.size()+i+f] > s[f]) return i + l.size();
	return i + l.size() + 1;
}

int der (int i) {
	int f = y[r.size()+i];

	if (f >= r.size()) return min(i + (int)r.size(), n);
	if (r.size() + i + f == y.size()) return n;
	if (t[r.size()+i+f] < t[f]) return min(i + (int)r.size(), n);
	return min(i + (int)r.size() - 1, n);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> l >> r;

	n = a.size();
	s = l + a;
	t = r + a;

	obtZF(s, x);
	obtZF(t, y);

	dp[n] = 1;
	update(n, 1);

	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == '0') { 
			dp[i] = dp[i+1] * (l == "0");
			if(i) update(i, dp[i]);
			continue;
		}

		int l = izq(i), r = der(i);
		if (l > r) { dp[i] = 0; continue; }

		dp[i] = query(l, r);
		if(i) update(i, dp[i]);
	}

	cout << MOD(dp[0], mod) << endl;

	return 0;
}