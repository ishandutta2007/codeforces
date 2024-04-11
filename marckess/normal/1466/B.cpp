#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

int n;
vi a;

void solve () {
	cin >> n;
	a = vi(n + 1);
	
	forn (i, n) cin >> a[i];
	
	a[n] = 1e9;
	for (int i = n - 1; i >= 0; i--)
		if (a[i] + 1 < a[i + 1])
			a[i] += 1;
	
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	
	cout << (int)a.size() - 1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}