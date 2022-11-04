#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, q, p[MX], f[MX];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	p[parent(a)] = parent(b);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	iota(p, p+MX, 0);
	memset(f, -1, sizeof(f));

	cin >> n >> m >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (f[x] != -1) {
			join(f[x], y);
		} else {
			f[x] = y;
		}
	}

	int res = -1;
	for (int i = 1; i <= m; i++)
		if (parent(i) == i)
			res++;
		
	for (int i = 1; i <= n; i++)
		if (f[i] == -1)
			res++;

	cout << res << endl;

	return 0;
}