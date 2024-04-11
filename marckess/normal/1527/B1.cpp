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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
string s;

void solve () {
	cin >> n;
	cin >> s;
	
	int f = 0;
	for (char c : s)
		if (c == '0')
			f++;
	
	if (!f) cout << "DRAW" << endl;
	else if (n % 2 && s[n / 2] == '0' && f > 1) cout << "ALICE" << endl;
	else cout << "BOB" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	
	
	return 0;
}