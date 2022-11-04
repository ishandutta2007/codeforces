#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (ll i = ll(a); i <= ll(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll a, b, c, d;

void main_() {
	cin >> a >> b >> c >> d;
	
	forr (x, a + 1, c) {
		ll g = __gcd(a * b, x);
		ll ot = a * b / g;
		
		if (ot > d) continue;
		
		ll y = ot * (d / ot);
		
		if (y > b) {
			cout << x << " " << y << endl;
			return;
		}
	}
	
	cout << -1 << " " << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}