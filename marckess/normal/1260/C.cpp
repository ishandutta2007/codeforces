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

#define sq(n) (ll(n)*(n))

void solve () {
	int a, b, k;
	cin >> a >> b >> k;

	if (a == b) {
		cout << "OBEY" << endl;
		return; 
	}

	int g = __gcd(a, b);
	a /= g;
	b /= g;

	if (a > b)
		swap(a, b);

	if (1 + (b - 2) / a >= k) {
		cout << "REBEL" << endl;
	} else {
		cout << "OBEY" << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	while (n--)
		solve();	

	return 0;
}