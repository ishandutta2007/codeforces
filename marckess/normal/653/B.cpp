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

int n, q, res;
map<pair<char, char>, char> mp;
string c = "abcdef";

int go (string s) {
	if (s.size() == n) {
		while (s.size() > 1)
			if (mp.count({s[0], s[1]})) {
				s[1] = mp[{s[0], s[1]}];
				s.erase(s.begin());
			} else {
				break;
			}

		return s == "a";
	}

	int res = 0;
	for (char t : c)
		res += go(s + t);
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	forn(i, q) {
		string a;
		char b;
		cin >> a >> b;
		mp[{a[0], a[1]}] = b;
	}

	cout << go("") << endl;

	return 0;
}