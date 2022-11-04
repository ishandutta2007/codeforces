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

const int MX = 100005;
int n, m, k;
ii a[MX];
vvi res;

void solve () {
	cin >> m >> k;
	
	int mx = 0;
	for (int i = 1; i <= k; i++) {
		cin >> a[i].fi;
		mx = max(mx, a[i].fi);
		a[i].se = i;
	}
	sort(a + 1, a + k + 1, greater<ii>());
	
	n = 1;
	while (n * n - (n / 2) * (n / 2) < m || n * ((n + 1) / 2) < mx)
		n++;
	
	res = vvi(n, vi(n));
	
	#define go { \
		while (ptr <= k && !a[ptr].fi) \
			ptr++; \
		if (ptr <= k) { \
			res[i][j] = a[ptr].se; \
			a[ptr].fi--; \
		} \
	}
	
	int ptr = 1;
	for (int i = 1; i < n; i += 2)
		for (int j = 0; j < n; j += 2)
			go
	
	for (int i = 0; i < n; i += 2)
		for (int j = 0; j < n; j += 2)
			go
	
	for (int i = 0; i < n; i += 2)
		for (int j = 1; j < n; j += 2)
			go
	
	cout << n << endl;
	for (vi &r : res) {
		for (int x : r)
			cout << x << " ";
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		
	int t;
	cin >> t;
	while (t--)
		solve();
 
	return 0;
}