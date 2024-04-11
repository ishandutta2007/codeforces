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
int n, a[MX];
ll res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, 2 * n)
		cin >> a[i];
	sort(a, a + 2 * n);
	res = ll(a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);

	for (int i = 1; i < n; i++)
		res = min(res, ll(a[n - 1 + i] - a[i]) * (a[2 * n - 1] - a[0]));
	cout << res << endl;


	return 0;
}