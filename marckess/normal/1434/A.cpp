#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 100005;
int n, a[MX], b[MX], ptr[MX], res = 2e9;
set<ii> ms;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	forn (i, 6) cin >> a[i];
	sort (a, a + 6, greater<int>());
	cin >> n;
	forn (i, n) {
		cin >> b[i];
		ms.emplace(b[i] - a[0], i);
	}
	while (1) {
		res = min(res, ms.rbegin()->fi - ms.begin()->fi);
		auto it = *ms.begin();
		ms.erase(ms.begin());
		if (++ptr[it.se] == 6) break;
		ms.emplace(b[it.se] - a[ptr[it.se]], it.se);
	}
	cout << res << endl;
	
	return 0;
}