#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
ll in, res = 0, acu[MX];
int n, a[MX], cn[MX][2];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	cn[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		cin >> in;
		
		a[i] = __builtin_popcountll(in);
		acu[i] = a[i] + acu[i-1];

		cn[i][0] = cn[i-1][0];
		cn[i][1] = cn[i-1][1];
		cn[i][acu[i]%2]++;
	}

	for (int i = 1; i <= n; i++) {
		int x = 0, mx = 0;

		for (int j = i; j > 0 && j > i - 60; j--) {
			x += a[j];
			mx = max(mx, a[j]);
			if (x % 2 == 0 && x >= mx * 2) res++;
		}

		if (i-61 >= 0) res += cn[i-61][acu[i]%2];
	}

	cout << res << endl;

	return 0;
}