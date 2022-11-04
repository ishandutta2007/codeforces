#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
#define MOD(n,k) ((((n) % (k)) + (k)) % (k))
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int gcd (int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, a[100005];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int d = a[0];
	for (int i = 1; i < n; i++)
		d = gcd(d, a[i]);

	for (int i = 0; i < n; i++) {
		int x = a[i] / d;
		
		while (x % 2 == 0)
			x /= 2;
		while (x % 3 == 0)
			x /= 3;

		if (x > 1) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;

	return 0;
}