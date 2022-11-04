#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int cn, mx = 0, a = 0, b = 0, n;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> s;
	n = s.size();
	forn(i, n) {
		if (!i || s[i] == s[i-1]) cn = 1;
		else cn++;
		mx = max(cn, mx);
	}

	if (s[0] != s.back()) {
		a = 1;
		while (a < n && s[a] != s[a-1]) a++;

		b = 1;
		while(b < n && s[n - b] != s[n - b - 1]) b++;
	}

	cout << min(n, max(mx, a + b)) << endl;
 
	return 0;
}