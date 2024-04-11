#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], q[MX], s[30], mn[MX], mx[MX];
set<int> izq, der;

int ant (set<int> &st, int x) {
	auto it = st.lower_bound(x);
	it--;
	return *it;
}

int sig (set<int> &st, int x) {
	auto it = st.upper_bound(x);
	return *it;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	iota(q, q+n, 1);
	sort(q, q+n, [&] (int i, int j) {
		return a[i] > a[j];
	});
	
	izq.insert(0);
	der.insert(n+1);

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 30; j++)
			if (a[i] & (1 << j)) s[j] = i;
			else mn[i] = max(mn[i], s[j]);
	
	fill(s, s+30, n+1);
	fill(mx, mx+MX, n+1);
	for (int i = n; i > 0; i--)
		for (int j = 0; j < 30; j++)
			if (a[i] & (1 << j)) s[j] = i;
			else mx[i] = min(mx[i], s[j]);
	
	ll res = 0;
	
	for (int i=0, x=0, y=0; i < n; i++) {
		while (x<n && a[q[x]] >= a[q[i]]) izq.insert(q[x++]);
		while (y<n && a[q[y]] > a[q[i]]) der.insert(q[y++]);
		
		ll a = ant(izq,q[i])+1;
		ll b = sig(der,q[i])-1;
		
		if (b >= mx[q[i]]) res += (q[i] - a + 1) * (b - mx[q[i]] + 1);
		if (mn[q[i]] >= a) res += (mn[q[i]] - a + 1) * (b - q[i] + 1);
		if (mn[q[i]] >= a && b >= mx[q[i]]) res -= (mn[q[i]] - a + 1) * (b - mx[q[i]] + 1);
	}
	
	cout << res << endl;
	
	return 0;
}