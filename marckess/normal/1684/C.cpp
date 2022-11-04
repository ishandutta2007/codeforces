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
vvi a, b;
map<vi, vi> mp;

void main_() {
	cin >> n >> m;
	a = vvi(n, vi(m));
	
	forn (i, n)
	forn (j, m)
		cin >> a[i][j];
	
	b = a;
	forn (i, n)
		sort(all(b[i]));
	
	mp.clear();
	forn (j, m) {
		vi v;
		forn (i, n)
			v.pb(b[i][j]);
		mp[v].pb(j);
	}
	
	forn (j, m) {
		int f = 1;
		forn (i, n)
			f &= a[i][j] == b[i][j];
		if (f) continue;
		
		vi v;
		forn (i, n)
			v.pb(a[i][j]);
		
		for (int k : mp[v]) {
			int h = 1;
			
			forn (i, n)
				h &= a[i][j] == a[i][k];
			
			if (h) continue;
			
			forn (i, n)
				swap(a[i][j], a[i][k]);
				
			if (a != b) {
				cout << -1 << endl;
				return;
			}
			
			cout << j + 1 << " " << k + 1 << endl;
			return;
		}
		
		cout << -1 << endl;
		return;
	}
	
	cout << 1 << " " << 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}