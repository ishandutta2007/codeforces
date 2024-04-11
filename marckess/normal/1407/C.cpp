#include <bits/stdc++.h>

//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 10005;
int n, a[MX];

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	int act = 1;
	for (int i = 2; i <= n; i++) {
		int x, y;

		cout << "? " << i << " " << act << endl;
		cin >> x;

		cout << "? " << act << " " << i << endl;
		cin >> y;

		if (x > y) {
			a[i] = x;
		} else {
			a[act] = y;
			act = i;
		}
	}

	a[act] = n;

	cout << "!";
	for (int i = 1; i <= n; i++)
		cout << " " << a[i];
	cout << endl;

	return 0;
}