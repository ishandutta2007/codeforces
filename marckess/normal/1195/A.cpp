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

int n, k, res, x;
int cn[1005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cn[a]++;
	}

	for (int i = 1; i <= k; i++) {
		if (cn[i] & 1) res += cn[i] - 1, x++;
		else res += cn[i];
	}
	cout << res + (x + n % 2) / 2 << endl;
 
	return 0;
}