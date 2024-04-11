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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 55;
int n;
ll a[MX], s;

void solve () {
	cin >> n;
	
	s = 0;
	forn (i, n) {
		cin >> a[i];
		s += a[i];
	}
	
	forn (i, n) {
		ll j = 0;
		while ((1 << j + 1) <= a[i])
			j++;
		cout << (1 << j) << " ";
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	
		
	return 0;
}