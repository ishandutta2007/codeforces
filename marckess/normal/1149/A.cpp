#include <bits/stdc++.h>

#define endl '\n'
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

const int MX = 200005;
int n, x, a[3];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[x]++;
	}

	if (a[2]) {
		cout << 2 << " ";
		a[2]--;
	}

	if (a[1]) {
		cout << 1 << " ";
		a[1]--;
	}

	while (a[2]) {
		cout << 2 << " ";
		a[2]--;
	}

	while (a[1]) {
		cout << 1 << " ";
		a[1]--;
	}

	cout << endl;

	return 0;
}