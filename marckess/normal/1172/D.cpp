#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1005;
int n, r[MX], c[MX], m, fr[MX], fc[MX];
vii a, b;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn(i, n) {cin >> r[i+1]; fr[r[i+1]] = i + 1;}
	forn(i, n) {cin >> c[i+1]; fc[c[i+1]] = i + 1;}

	forr (i, 1, n) {
		if (r[i] == i && c[i] == i) continue;
		a.pb(i, fc[i]), b.pb(fr[i], i);
		swap(r[i], r[fr[i]]);
		swap(c[i], c[fc[i]]);
		forr(j, i + 1, n)
			fr[r[j]] = j, fc[c[j]] = j;
	}

	cout << a.size() << endl;
	forn(i, a.size())
		cout << a[i].fi << " " << a[i].se << " " << b[i].fi << " " << b[i].se << endl;

	return 0;
}