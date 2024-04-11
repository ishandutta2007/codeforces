#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

ll n, sum = 0;

ll gcd (ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i++)
		sum += i;

	for (int i = 1; i <= n; i++)
		if (gcd(sum, i) > 1) {
			cout << "Yes" << endl;
			cout << 1 << " " << i << endl;
			cout << n-1;
			for (int j = 1; j <= n; j++)
				if (j != i)
					cout << " " << j;
			cout << endl;
			return 0;
		}

	cout << "No" << endl;

	return 0;
}