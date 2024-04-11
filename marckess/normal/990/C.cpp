#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, cn[MX];
string s[MX];
ll res = 0;

int val (string &s, bool f) {
	int c = 0;
	for (char h : s) {
		if ((h == '(') ^ f) c++;
		else c--;
		if (c < 0) return -1;
	}
	return c;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		int d = val(s[i], 0);
		if (d != -1) cn[d]++;
	}

	for (int i = 0; i < n; i++) {
		reverse(all(s[i]));
		int d = val(s[i], 1);
		if (d > 0) res += cn[d];
	}

	cout << res + cn[0] * ll(cn[0]) << endl;

	return 0;
}