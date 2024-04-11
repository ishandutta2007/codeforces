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
	
	int n, a[1000];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ind = -1;
	for (int i = 0; i < n; i++) {
		bool f= true;
		for (int j = 0; j < n; j++) {
			if (gcd(a[i], a[j]) != a[i]) {
				f = false;
			}
		}
		if (f)
			ind = i;
	}

	if (ind == -1) {
		cout << -1 << endl;
		return 0;
	}

	cout << n*2 << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " " << a[ind] << " ";
	}
	cout << endl;
	return 0;
}