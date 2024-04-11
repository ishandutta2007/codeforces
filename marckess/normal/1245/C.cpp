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

const int MX = 100005, mod = 1000000007;
int n, f[MX];
ll res = 1;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	f[0] = f[1] = 1;
	for (int i = 2; i < MX; i++)
		f[i] = (f[i-1] + f[i-2]) % mod;

	cin >> s;
	n = s.size();

	int x = 0, y = 0;
	for (int c : s) {
		if (c == 'm' || c == 'w') {
			cout << 0 << endl;
			return 0;
		}

		if (c == 'u') {
			x++;
		} else {
			(res *= f[x]) %= mod;
			x = 0;
		}

		if (c == 'n') {
			y++;
		} else {
			(res *= f[y]) %= mod;
			y = 0;
		}
	}

	(res *= f[x]) %= mod;
	(res *= f[y]) %= mod;

	cout << res << endl;

	return 0;
}