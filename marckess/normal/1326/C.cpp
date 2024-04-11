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
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005, mod = 998244353;
int n, k, a[MX], f;
ll res = 1, cn = 1, s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > n - k) {
			if (f) (res *= cn) %= mod;
			cn = 1;
			f = 1;
			s += a[i];
		} else {
			cn++;
		}
	}
	cout << s << " " << res << endl;

	return 0;
}