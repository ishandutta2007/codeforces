#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
ll t;
string s;
vi a;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> t >> s;
	
	forn (i, n - 2) {
		a.pb(2 << (s[i] - 'a'));
		t += 1 << (s[i] - 'a');
	}
	
	t += 1 << (s[n - 2] - 'a');
	t -= 1 << (s[n - 1] - 'a');
	
	sort(all(a), greater<ll>());
	
	for (ll x : a)
		if (t >= x)
			t -= x;
		
	if (t) cout << "No" << endl;
	else cout << "Yes" << endl;
	
	return 0;
}