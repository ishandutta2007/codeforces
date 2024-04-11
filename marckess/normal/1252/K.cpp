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

const int MX = 1000005, mod = 1e9+7;
int p, k, res;
bitset<MX> bs;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> p >> k;

	if (!k) {
		cout << pot(p, p - 1) << endl;
		return 0;
	}

	res = k == 1;

	for (int i = 1; i < p; i++)
		if (!bs[i]) {
			res++;
			ll x = i;

			while (!bs[x]) {
				bs[x] = 1;
				(x *= k) %= p;
			}
		}

	cout << pot(p, res) << endl;

	return 0;
}