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
typedef vector<ii> vii;

const int MX = 10005;
int n;
ll a[MX], x, d;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> x >> d;
	for (ll i = 0, k = 1; i < 30; i++, k += 4 * d)
		if (x & (1 << i)) {
			forn (j, i) {
				a[n] = k;
				n++;
			}
			a[n] = k + 2 * d;
			n++;
		}

	cout << n << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}