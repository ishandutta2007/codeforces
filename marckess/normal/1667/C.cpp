// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

void main_() {
	int n;
	cin >> n;
	
	vii res;
	
	int k = (2 * n + 1) / 3, f = 0;
	
	if (k % 2 == 0) {
		res.pb({1, 1});
		f = 1;
		k--;
	}
	
	for (int kk = 0, x = 1 + f, y = k / 2 + f; kk < k / 2; kk++, x++, y--)
		res.pb({x, y});
	
	for (int kk = 0, x = n, y = n - (k + 1) / 2 + 1; kk < (k + 1) / 2; kk++, x--, y++)
		res.pb({x, y});
	
	cout << res.size() << endl;
	for (auto &r : res)
		cout << r.fi << " " << r.se << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}