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
int n, cn[MX];
ll res = 0, b[MX];
string s[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn (i, n) {
		cin >> s[i];
		reverse(all(s[i]));
		cn[s[i].size()]++;
	}

	b[0] = 1;
	for (int i = 1; i < 25; i++)
		(b[i] = b[i-1] * 10) %= mod;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < s[i].size(); j++)
			for (int k = 1; k <= 10; k++) {
				if (j + 1 <= k) (res += cn[k] * b[2 * j] * (s[i][j] - '0')) %= mod;
				else (res += cn[k] * b[k + j] * (s[i][j] - '0')) %= mod;

				if (j + 1 <= k) (res += cn[k] * b[2 * j + 1] * (s[i][j] - '0')) %= mod;
				else (res += cn[k] * b[k + j] * (s[i][j] - '0')) %= mod;
			}

	cout << res << endl;

	return 0;
}