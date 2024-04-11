#include <bits/stdc++.h>

//#define endl '\n'
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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int x = 0;
	string s;
	cin >> s;

	for (char c : s)
		if (c != 'a') x++;

	if (x & 1) {
		cout << ":(" << endl;
		return 0;
	}

	int n = s.size() - x / 2;
	string a = s.substr(0, n), b = a;

	n = a.size();
	for (int i = 0; i < n; i++)
		if (a[i] != 'a')
			a.pb(a[i]);

	if (a == s) cout << b << endl;
	else cout << ":(" << endl;

	return 0;
}