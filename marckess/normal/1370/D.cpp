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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, k, a[MX];

bool esPos (int m) {
	int i = 0, j = 0;

	while (j < n && i < k) {
		if (a[j] <= m) {
			j += 2, i += 2;
		} else {
			j++;
		}
	}

	j -= 2;
	if (i >= k && (k % 2 == 1 || j + 1 < n))
		return 1;

	i = 1, j = 1;
	while (j < n && i < k) {
		if (a[j] <= m) {
			j += 2, i += 2;
		} else {
			j++;
		}
	}

	j -= 2;
	if (i >= k && (k % 2 == 0 || j + 1 < n))
		return 1;

	return 0;
}

void solve () {
	cin >> n >> k;
	forn (i, n)
		cin >> a[i];

	int i = 1, j = 1e9 + 5, rep = 35;
	while (rep--) {
		int m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}

	cout << j << endl;
}	

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	return 0;
}