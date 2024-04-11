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

int px, py;
string s;

void solve () {
	cin >> px >> py >> s;
	int a = 0, b = 0, c = 0, d = 0;
	for (char h : s) {
		if (h == 'L') a--;
		if (h == 'R') b++;
		if (h == 'D') c--;
		if (h == 'U') d++;
	}
	if (a <= px && px <= b && c <= py && py <= d) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}