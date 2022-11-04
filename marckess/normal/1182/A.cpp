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

int n;
ll a[65];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	a[0] = 1;
	a[2] = 2;
	for (int i = 2; i <= n; i++)
		a[i] = 2 * a[i - 2];
	cout << a[n] << endl;

	return 0;
}