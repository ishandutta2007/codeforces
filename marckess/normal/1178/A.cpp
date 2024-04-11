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

int n, a[100000], s = 0, m = 0, t = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!i || a[0] >= 2 * a[i])
			s += a[i], m++;
		t += a[i];
	}

	if (2 * s <= t) 
		cout << 0 << endl;
	else {
		cout << m << endl;
		for (int i = 0; i < n; i++) {
			if (!i || a[0] >= 2 * a[i])
				cout << i + 1 << " ";
		}
	}

	return 0;
}