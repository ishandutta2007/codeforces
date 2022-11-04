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

const int MX = 300005, mod = 998244353;
int n, bs[MX];
ll m;

void main_() {
	cin >> n >> m;
	
	ll res = 0, acu = 1, x = 1;
	
	forr (i, 1, n) {
		if (!bs[i])
			x *= i;
		if (x > m) break;
		(acu *= (m / x) % mod) %= mod;
		(res += acu) %= mod;
	}
	
	acu = 1;
	ll tot = 0;
	
	forr (i, 1, n) {
		(acu *= m % mod) %= mod;
		(tot += acu) %= mod;
	}
	
	cout << MOD(tot - res, mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	bs[1] = bs[0] = 1;
	forr (i, 2, MX - 1)
		if (!bs[i])
			for (int j = 2 * i; j < MX; j += i)
				bs[j] = 1;
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}