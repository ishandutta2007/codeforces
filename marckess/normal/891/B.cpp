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
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, a[25], b[25];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn(i, n) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b+n);

	forn(i, n) {
		forn(j, n)
			if (a[i] == b[j]) {
				a[i] = b[(j+1)%n];
				break;
			}
	}

	forn(i, n) cout << a[i] << " ";
	cout << endl;

	return 0;
}