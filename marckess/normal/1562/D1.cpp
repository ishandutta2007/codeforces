
// Problem : D2. Two Hundred Twenty One (hard version)
// Contest : Codeforces - Codeforces Round #741 (Div. 2)
// URL : https://codeforces.com/contest/1562/problem/D2
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

const int MX = 300005;
int n, q, acu[MX], l[MX], r[MX];
string s;
vi res[MX], pos[MX];

void solve () {
	cin >> n >> q >> s;
	s = " " + s;
	
	for (int i = 1; i <= n; i++) {
		acu[i] = (s[i] == '+') != (i % 2 == 0) ? 1 : -1;
		acu[i] += acu[i - 1];
		
		pos[i].clear();		
	}
	
	forn (i, q) {
		cin >> l[i] >> r[i];
		pos[r[i]].pb(i);
	}
	
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		mp[-acu[i] - acu[i - 1]] = i;
		
		for (int j : pos[i]) {
			int x = l[j], y = r[j];
			
			if (acu[y] - acu[x - 1] == 0) {
				res[j] = {};
			} else {
				if (x % 2 != y % 2) {
					res[j] = {y};
					y--;
				} else {
					res[j] = {};
				}
				
				int k = acu[y] + acu[x - 1];
				res[j].pb(mp[-k]);
			}
		}
	}
	
	forn (i, q) {
		cout << res[i].size() << endl;
		
		/*for (int r : res[i])
			cout << r << " ";
		cout << endl;*/
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}