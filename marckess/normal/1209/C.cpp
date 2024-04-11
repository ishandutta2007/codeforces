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
int n;
string s, t, res;
int cn[256];

void solve () {
	cin >> n >> s;
	t = s;

	memset(cn, 0, sizeof(cn));
	for (char c : s)
		cn[c]++;

	sort(all(t));
	t.erase(unique(all(t)), t.end());

	res.assign(n, '2');
	int lst = 0;
	for (char c : t) {
		for (int i = lst; i < n; i++)
			if (s[i] == c) {
				lst = i;
				res[i] = '1';
				cn[c]--;
			}
		if (cn[c]) break;
	}

	t.clear();
	forn (i, n) if (res[i] == '1') t.pb(s[i]);
	forn (i, n) if (res[i] == '2') t.pb(s[i]);

	for (int i = 1; i < n; i++)
		if (t[i] < t[i-1]) {
			cout << '-' << endl;
			return;
		}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}