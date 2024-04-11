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

const int MX = 100005;
int n, k[MX], x, mx[MX], mn[MX], a[MX];
ll res;
vi v;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	memset(mn, -1, sizeof(mn));
	for (int i = 0; i < n; i++) {
		cin >> k[i];
		for (int j = 0; j < k[i]; j++)
			cin >> a[j];

		int f = 0;
		for (int j = 1; j < k[i]; j++)
			f |= a[j] > a[j-1];

		if (f) x++, res += n;
		else {
			mn[i] = a[k[i]-1];
			mx[i] = a[0];
			v.pb(mn[i]);
		}
	}

	sort(all(v));
	for (int i = 0; i < n; i++) {
		if (mn[i] == -1) continue;
		int j = lower_bound(all(v), mx[i]) - v.begin();
		res += j + x;
	}

	cout << res << endl;

	return 0;
}