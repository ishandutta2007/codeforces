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

string tbs (ll n) {
	string s;
	for (int i = 60; i >= 0; i--) {
		if ((n & (1ll << i)) || s.size()) {
			s.pb('0' + bool(n & (1ll << i)));
		}
	}
	return s;
}

ll n, k, mem[65][3];
string s;

ll dp (int i, int f) {
	if (f == 2 && i + 1 == s.size())
		return 1;

	if (i == s.size())
		return f != 2;
	
	ll &res = mem[i][f];
	if (res != -1)
		return res;
	res = 1;
	
	if (f == 0) {
		if (s[i] == '1') {
			res += dp(i + 1, 0);
			res += dp(i + 1, 1);
		} else {
			res += dp(i + 1, 2);
			res += dp(i + 1, 0);
		}
	} else {
		res += 2 * dp(i + 1, f);
	}

	return res;
}

ll esPos (ll m) {
	if (m > n) return 0;

	string t = tbs(m);
	ll acu = 0;
	int f = 0, g = 0, ind;
	
	for (int i = 0; i < t.size(); i++)
		if (s[i] > t[i]) {
			f = 1;
			ind = i;
			break;
		} else if (s[i] < t[i]) {
			f = 2;
			ind = i;
			break;
		}

	memset(mem, -1, sizeof(mem));
	if (t.back() == '0') {
		if (f == 0) {
			acu += dp(t.size(), 0);
			memset(mem, -1, sizeof(mem));
			acu += dp(t.size(), 2);
		} else {
			acu += dp(t.size(), f);
			memset(mem, -1, sizeof(mem));
			if (ind + 1 == t.size())
				acu += dp(t.size(), 0);
			else
				acu += dp(t.size(), f);
		}
	} else {
		acu += dp(t.size(), f);
	}

	return acu;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	s = tbs(n);

	ll res = 0;
	for (int i = 60; i >= 0; i--)
		if (esPos(res | (1ll << i)) >= k)
			res |= 1ll << i;

	cout << res << endl;

	return 0;
}