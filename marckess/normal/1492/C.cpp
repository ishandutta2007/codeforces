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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, mx[MX], mn[MX];
string s, t;

void solve () {
	cin >> n >> m >> s >> t;
	
	for (int i = 0, j = 0; i < n; i++)
		if (j < m && s[i] == t[j]) {
			mn[j] = i;
			j++;
		}
	
	for (int i = n - 1, j = m - 1; i >= 0; i--)
		if (j >= 0 && s[i] == t[j]) {
			mx[j] = i;
			j--;
		}
	
	int res = 1;
	forn (j, m - 1)
		res = max(res, mx[j + 1] - mn[j]);
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