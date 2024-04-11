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
int n, m, f[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	f[0] = f[1] = 1;
	for (int i = 2; i < MX; i++)
		f[i] = (f[i-1] + f[i-2]) % mod;

	cin >> n >> m;
	cout << 2ll * (f[m] + f[n] - 1) % mod << endl;

	return 0;
}