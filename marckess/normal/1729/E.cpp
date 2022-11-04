#include <bits/stdc++.h>

// #define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll query (ll a, ll b) {
	cout << "? " << a << " " << b << endl;
	ll res;
	cin >> res;
	if (!res) exit(0);
	return res;
}

void main_() {
	ll res = 0;
	
	forr (i, 2, 2 + 25 - 1) {
		ll x = query(1, i);
		ll y = query(i, 1);
		
		if (x == -1) {
			res = i - 1;
			break;
		}
		
		if (x != y) {
			res = x + y;
			break;
		}
		
		res = x + y;
	}
	
	cout << "! " << res << endl;
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}