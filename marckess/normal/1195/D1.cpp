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
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005, mod = 998244353;
int n;
ll res = 0;
string s[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn (i, n) cin >> s[i];
	for (ll i = s[0].size() - 1, x = 1; i + 1; i--, (x *= 100) %= mod)
		for (int j = 0; j < n; j++)
			(res += 11 * n * (s[j][i] - '0') * x) %= mod;
 	cout << res << endl;

	return 0;
}