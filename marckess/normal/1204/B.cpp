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

ll mn, mx;
int n, l, r;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> l >> r;
	mn = n;
	mx = n * ll(1 << (r - 1));

	for (int i = 1; i < l; i++)
		mn += (1 << i) - 1;
	for (int i = 0; i < r - 1; i++)
		mx += (1 << i) - (1 << (r - 1));
	cout << mn << " " << mx << endl;

	return 0;
}