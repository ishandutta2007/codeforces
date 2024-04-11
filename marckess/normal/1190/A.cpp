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

const int MX = 100005;
ll n, m, k, a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		a[i]--;
	}

	int res = 0;
	for (int i = 0; i < m;) {
		ll q = (a[i] - i) / k;
		int j = i;
		while (j < m && (a[j] - i) / k == q)
			j++;
		i = j;
		res++;
	}
	cout << res << endl;

	return 0;
}