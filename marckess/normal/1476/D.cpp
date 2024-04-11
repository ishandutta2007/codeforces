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

const int MX = 1000005;
int n, p[MX], sz[MX];
string s;

ll parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	a = parent(a), b = parent(b);
	if (a == b) return;
	sz[b] += sz[a];
	p[a] = b;
}

void solve () {
	cin >> n >> s;
	
	iota(p + 0, p + 2 * (n + 5), 0);
	fill(sz + 0, sz + 2 * (n + 5), 1);
	
	for (int i = 0; i <= n; i++) {
		if (i < n && s[i] == 'R') join(2 * i, 2 * (i + 1) + 1);
		if (i < n && s[i] == 'L') join(2 * i + 1, 2 * (i + 1));
		
		if (i && s[i - 1] == 'L') join(2 * i, 2 * (i - 1) + 1);
		if (i && s[i - 1] == 'R') join(2 * i + 1, 2 * (i - 1));
	}
	
	for (int i = 0; i <= n; i++)
		cout << sz[parent(2 * i)] << " ";
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