#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 200005;
int n, x[MX], y[MX];
map<ii, int> mp;
ll res = 0;

void obtRes () {
	mp.clear();

	for (int i = 0; i < n; i++) {
		int d = min(x[i], y[i]);
		ii p(x[i] - d, y[i] - d);
		res += mp[p];
		mp[p]++;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	obtRes();

	for (int i = 0; i < n; i++)
		x[i] = 1000 - x[i] + 1;

	obtRes();

	cout << res << endl;

	return 0;
}