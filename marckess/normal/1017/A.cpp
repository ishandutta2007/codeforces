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

const int MX = 1005;
int a[MX], x, n, q[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> x;
			a[i] += x;
		}
	}

	iota(q, q+n, 0);
	sort(q, q+n, [&] (int i, int j) {
		if (a[i] == a[j]) return i  < j;
		return a[i] > a[j];
	});

	for (int i = 0; i < n; i++)
		if (!q[i])
			cout << i+1 << endl;

	return 0;
}