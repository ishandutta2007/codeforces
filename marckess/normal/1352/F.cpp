#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 8005;
int n0, n1, n2;

void solve () {
	deque<int> res;
	int f = 1;

	cin >> n0 >> n1 >> n2;
	
	if (n0 + n1)
		cout << 0;

	while (n0--)
		cout << 0;

	if (n1) {
		cout << 1;
		f = 0;
		n1--;
	} else if (n2) {
		cout << 1;
	}

	while (n2--)
		cout << 1;

	while (n1--) {
		cout << f;
		f = 1 - f;
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