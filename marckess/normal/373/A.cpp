#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int k;
int a[10];
char c;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> k;
	for (int i = 0; i < 16; i++) {
		cin >> c;
		if (c != '.') {
			a[c-'0']++;
			if (a[c-'0'] > 2 * k) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;

	return 0;
}