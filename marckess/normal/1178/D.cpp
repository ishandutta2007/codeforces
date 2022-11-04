#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n;
bitset<2005> bs;

void solve (int n) {
	vi adj[1005];
	int m = 0;
	set<ii> st;

	m = n;
	while (!bs[m])
		m++;
	m = m - n;
	
	for (int i = 0; i < n; i++) {
		adj[i].pb((i + 1) % n);
	}
	for (int i = 0; i < m; i++) {
		adj[i].pb(n / 2 + i);
	}

	cout << n + m << endl;
	for (int u = 0; u < n; u++)
		for (int v : adj[u])
			cout << u + 1 << " " << v + 1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= 2000; i++)
		if (bs[i])
			for (int j = i * i; j <= 2000; j += i)
				bs[j] = 0;

	cin >> n;
	solve(n);	

	return 0;
}