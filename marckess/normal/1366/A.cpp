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

int a, b, res;

void solve () {
	cin >> a >> b;
	if (a > b) swap(a, b);
	res = 0;

	int d = min(a, b - a);
	a -= d;
	b -= 2 * d;
	res += d;

	d = min(a, b) / 3;
	a -= 3 * d;
	b -= 3 * d;
	res += 2 * d;

	if ((a >= 2 && b >= 1) || (b >= 2 && a >= 1))
		res++;

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}