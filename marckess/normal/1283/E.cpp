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

const int MX = 200005;
int n, a[MX], b[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;
		a[in]++;
	}

	for (int i = 1; i <= n; i++)
		if (!b[i] && !b[i-1])
			b[i+1] = bool(a[i]);

	cout << accumulate(b, b+MX, 0) << " ";

	memset(b, 0, sizeof(b));
	for (int i = 1; i <= n; i++) {
		if (!b[i-1] && a[i]) {
			b[i-1] = 1;
			a[i]--;
		}

		if (!b[i] && a[i]) {
			b[i] = 1;
			a[i]--;
		}

		if (!b[i+1] && a[i]) {
			b[i+1] = 1;
			a[i]--;
		}
	}

	cout << accumulate(b, b+MX, 0) << endl;

	return 0;
}