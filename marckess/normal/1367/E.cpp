#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
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

const int MX = 2005;
int n, k, cn[MX], res;
string s;

void solve () {
	cin >> n >> k >> s;

	memset(cn, 0, sizeof(cn));
	for (char c : s)
		cn[c]++;

	res = 1;
	for (int i = 1; i <= n; i++) {
		int g = __gcd(i, k);
		int acu = 0;

		for (int k = 'a'; k <= 'z'; k++)
			acu += cn[k] / (i / g);

		if (acu >= g)
			res = max(res, i);
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