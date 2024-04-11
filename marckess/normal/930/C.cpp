#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, l, r, a[MX], izq[MX], der[MX], res = 0;
vi lis;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		a[l]++;
		a[r+1]--;
	}

	for (int i = 1; i <= m; i++)
		a[i] += a[i-1];

	for (int i = 1; i <= m; i++) {
		int j = upper_bound(ALL(lis), a[i]) - lis.begin();
		if (j == lis.size()) lis.pb(a[i]);
		else lis[j] = a[i];
		izq[i] = lis.size();
	}

	lis.clear();
	for (int i = m; i >= 1; i--) {
		der[i] = lis.size();
		int j = upper_bound(ALL(lis), a[i]) - lis.begin();
		if (j == lis.size()) lis.pb(a[i]);
		else lis[j] = a[i];
	}

	for (int i = 1; i <= m; i++)
		res = max(res, izq[i] + der[i]);

	cout << res << endl;

	return 0;
}