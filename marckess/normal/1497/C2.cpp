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

const int MX = 100005;
int n, k;

void solve () {
	cin >> n >> k;
	
	while (k > 3) {
		cout << 1 << " ";
		n--, k--;
	}
	
	if (n % 2) {
		cout << n / 2 << " " << n / 2 << " " << 1 << endl;
	} else if (n % 4) {
		cout << n / 2 - 1 << " " << n / 2 - 1 << " " << 2 << endl;
	} else {
		cout << n / 2 << " " << n / 4 << " " << n / 4 << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}