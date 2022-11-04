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

const int MX = 200005;
int n, a[MX];

void solve () {
	cin >> n;
	
	int x, y;
	forn (i, n) {
		cin >> a[i];
		
		if (a[i] == 1) x = i;
		if (a[i] == n) y = i;
	}
	
	if (x > y) swap(x, y);
	
	cout << n - max({y - x - 1, x, n - y - 1}) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}