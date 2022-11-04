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

const int MX = 10;
int cn[MX + 5];
string s = "codeforces";
ll k;

void solve () {
	forn (i, MX) cn[i] = 1;
	ll acu = 1;
	cin >> k;

	int i = 0;
	while (acu < k) {
		i %= MX;
		acu /= cn[i];
		cn[i]++;
		acu *= cn[i];
		i++;
	}

	forn (i, MX) {
		while (cn[i]--)
			cout << s[i];
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	return 0;
}