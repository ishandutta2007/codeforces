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

const int MX = 100005;
int n, deg[MX], in[MX], a[MX], q[MX];
ll res;

void solve () {
	cin >> n;
	
	res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		deg[i] = 0;
		in[i] = 1;
		q[i - 1] = i;
		res += a[i];
	}
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
	}
	
	sort(q, q + n, [&] (int i, int j) {
		return a[i] > a[j];
	});
	
	for (int i = 0, j = 0; i < n - 1; i++) {
		cout << res << " ";
		
		while (j < n && in[q[j]] >= deg[q[j]])
			j++;
		
		if (j < n) {
			res += a[q[j]];
			in[q[j]]++;
		}
	}
	
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}