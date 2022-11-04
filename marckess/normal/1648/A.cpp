// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, m;
vvi c;

void main_() {
	cin >> n >> m;
	c = vvi(n, vi(m));
	
	forn (i, n)
		forn (j, m)
			cin >> c[i][j];
	
	ll res = 0;
	map<int, ll> cn, dis;
	forn (i, n)
		forn (j, m) {
			res += i * cn[c[i][j]] - dis[c[i][j]];
			cn[c[i][j]]++;
			dis[c[i][j]] += i;
		}
	
	cn.clear();
	dis.clear();
	forn (j, m)
		forn (i, n) {
			res += j * cn[c[i][j]] - dis[c[i][j]];
			cn[c[i][j]]++;
			dis[c[i][j]] += j;
		}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}