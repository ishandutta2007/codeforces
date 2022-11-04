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
int n, k, m, x[MX], res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;

	res = n-1;
	while (k--) {
		cin >> m;
		for (int i = 0; i < m; cin >> x[i++]);
		sort(x, x+m);
		for (int i = 0; i < m; i++) {
			if (x[i] != i+1) break;
			if (i) res-=2;
		}
		res += m-1;
	}

	cout << res << endl;

	return 0;
}