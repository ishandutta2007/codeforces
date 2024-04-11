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

const int MX = 1000005;
int n, mod;
ll fac[MX], res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> mod;
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = i * fac[i-1] % mod;

	for (int i = 1; i <= n; i++) {
		res += ll(n - i + 1) * (n - i + 1) % mod * fac[i] % mod * fac[n - i];
		res %= mod;
	}

	cout << res << endl;

	return 0;
}