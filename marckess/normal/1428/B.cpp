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

string s;
int x, y, n;

void solve () {
	cin >> n >> s;
	n = s.size();
	x = y = 0;
	
	for (char c : s) {
		if (c == '>') x++;
		if (c == '<') y++;
	}
	
	if (!x || !y) cout << n << endl;
	else {
		int res = 0;
		forn (i, n)
			if (s[i] == '-' || s[(i + 1) % n] == '-')
				res++;
		cout << res << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}