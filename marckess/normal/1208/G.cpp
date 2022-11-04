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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1000005;
int n, k, phi[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;

	if (k == 1) {
		cout << 3 << endl;
		return 0;
	}

	iota(phi, phi+n+1, 0);
	for (int i = 2; i <= n; i++)
		if (phi[i] == i)
			for (int j = i; j <= n; j += i)
				phi[j] -= phi[j] / i;

	ll res = 2;
	sort(phi+3, phi+n+1);
	for (int i = 0; i < k; i++)
		res += phi[3+i];
	cout << res << endl;

	return 0;
}