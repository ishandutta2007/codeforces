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

const int MX = 200005;
int n, b[MX];
ii a[MX];
vector<vii> v;
map<int, int> mp;

void main_() {
	cin >> n;
	
	forn (i, n) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a, a + n);
	
	v = vector<vii>(n + 1);
	mp.clear();
	
	forn (i, n) {
		v[mp[a[i].fi]].pb(a[i]);
		mp[a[i].fi]++;
	}
	
	forn (i, n + 1)
		forn (j, v[i].size())
			b[ v[i][(j + 1) % v[i].size()].se ] = v[i][j].fi;
	
	forn (i, n)
		cout << b[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}