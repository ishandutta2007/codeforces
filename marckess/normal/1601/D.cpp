
// Problem : D. Difficult Mountain
// Contest : Codeforces - Codeforces Round #751 (Div. 1)
// URL : https://codeforces.com/contest/1601/problem/D
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, d;
ii a[MX];

void main_() {
	cin >> n >> d;
	
	forn (i, n)
		cin >> a[i].fi >> a[i].se;
	
	sort(a, a + n, [&] (const ii &a, const ii &b) {
		if (max(a.fi, a.se) ^ max(b.fi, b.se))
			return max(a.fi, a.se) < max(b.fi, b.se);
		return min(a.fi, a.se) < min(b.fi, b.se);
	});
	
	int res = 0;
	forn (i, n)
		if (d <= a[i].fi) {
			res++;
			d = max(d, a[i].se);
		}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}