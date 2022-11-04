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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, mx, ind;
int a[MX], izq[MX], der[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
		izq[i] = a[i] | izq[i - 1];

	for (int i = n; i > 0; i--)
		der[i] = a[i] | der[i + 1];

	mx = 0;
	ind = 1;
	for (int i = 1; i <= n; i++) {
		int x = a[i] & ~(izq[i - 1] | der[i + 1]);
		if (x > mx) {
			mx = x;
			ind = i;
		}
	}

	cout << a[ind] << " ";
	for (int i = 1; i <= n; i++)
		if (i != ind)
			cout << a[i] << " ";
	cout << endl;

	return 0;
}