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

int a[3];

void solve () {
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	
	if ((a[0] + a[1] + a[2]) % 9 == 0 && 6 * a[0] >= (a[1] + a[2] - 2 * a[0])) cout << "yes" << endl;
	else cout << "no" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	
		
	return 0;
}