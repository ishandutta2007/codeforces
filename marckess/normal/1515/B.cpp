#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;

bool isSq (int n) {
	int m = sqrt(n);
	
	for (ll i = m - 10; i <= m + 10; i++)
		if (i * i == n)
			return 1;
	
	return 0;
}

void solve () {
	cin >> n;
	
	if (n % 2 == 0)
		if (isSq(n / 2)) {
			cout << "YES" << endl;
			return;
		}
	
	if (n % 4 == 0)
		if (isSq(n / 4)) {
			cout << "YES" << endl;
			return;
		}
	
	cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}