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
typedef vector<ll> vi;
typedef vector<ii> vii;

const int MX = 400005;
int n, a[MX], b[MX], res;

int f (int j) {
	ll res = 0;
	sort(b, b + n);

	for (int i = 1; i < n; i++) {
		int l = lower_bound(b, b + i, (1 << j) - b[i]) - b;
		int r = upper_bound(b, b + i, (1 << j + 1) - 1 - b[i]) - b;
		res += r - l;

		l = lower_bound(b, b + i, (1 << j + 1) + (1 << j) - b[i]) - b;
		r = upper_bound(b, b + i, (1 << j + 2) - 1 - b[i]) - b;
		res += r - l;
	}

	return res % 2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int j = 0; (1 << j) <= 20000000; j++) {
		for (int i = 0; i < n; i++)
			b[i] = a[i] & ((1 << j + 1) - 1);
		res |= f(j) << j;
	}

	cout << res << endl;

	return 0;
}