#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, ft[MX], to[MX];
ll res;
string s;
vi pos[255];

void update (int i, int k) {
	i++;
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i) {
	i++;
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

void solve () {
	cin >> n >> s;
	
	forn (i, n) pos[s[i]].pb(i);
	
	for (int i = 'a'; i <= 'z'; i++) {
		vi ot;
		for (int x : pos[i])
			ot.pb(n - x - 1);
		
		reverse(all(ot));
		forn (j, ot.size()) to[ot[j]] = pos[i][j];
	}
	
	forn (i, n) update(i, 1);
	update(0, -1);
	
	forn (i, n) {
		res += query(to[i]) - i;
		update(0, 1);
		update(to[i], -1);
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();	
	
	return 0;
}