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

const int MX = 100005;
int n, res[MX], sq;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	int i = 1, j = 1000, rep = 15;
	while (rep--) {
		int m = (i+j)/2;
		if (m * m >= n) j = m;
		else i = m; 
	}

	sq = j;

	for (int i = 1, j = sq; i <= n; i += sq, j = min(j+sq, n)) {
		for (int k = 0; k < sq && i+k <= n; k++)
			cout << j-k << " ";
	}
	cout << endl;

	return 0;
}