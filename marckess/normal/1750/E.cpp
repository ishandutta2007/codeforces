#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (ll i = 0; i < ll(n); i++)
#define forr(i,a,b) for (ll i = ll(a); i <= ll(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
string s;

ll f () {
	ll res = 0;
	map<int, int> mp;
	int c = 0, off = 0;
	ll acu = 0;

	forn (i, n) {
		c++;
		
		if (s[i] == '(') {
			off++;
			mp[-off + 1] += c;
			c = 0;
		} else {
			off--;
			acu += c;
			c += mp[-off];
			mp[-off] = 0;
		}
		
		res += acu;
	}
	
	return res;
}

void main_() {
	cin >> n >> s;
	
	ll res = f();
	
	reverse(all(s));
	for (char &c : s)
		c ^= 1;
	
	res += f();

	vi v = {0};
	ll acu = 0;
	
	forn (i, n) {
		if (s[i] == '(') acu++;
		else acu--;
		v.pb(acu);
	}
	sort(all(v));
	
	acu = 0;
	forn (i, v.size()) {
		res += 1ll * i * v[i] - acu;
		acu += v[i];
	}

	cout << res / 2 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}