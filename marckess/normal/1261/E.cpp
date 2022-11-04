#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
typedef bitset<MX> row;

int n, a[MX], o[MX], res[MX][MX];

bool eq (int x, int y) {
	int f = 1;
	forn (i, n)
		f &= res[x][o[i]] == res[y][o[i]];
	return f;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	iota(o, o + n, 0);
	sort(o, o + n, [&] (int i, int j) {
		return a[i] < a[j];
	});
	
	forn (i, n)
		forn (j, a[o[i]])
			res[(i + j) % (n + 1)][o[i]] = 1;
	
	if (eq(n, n - 1)) {
		forn (i, n)
			if (res[n][o[i]]) {
				int ind = n;
				while (res[ind][o[i]])
					ind--;
				
				swap(res[n][o[i]], res[ind][o[i]]);
				
				if (eq(ind, ind + 1)) {
					swap(res[n][o[i]], res[ind][o[i]]);
					swap(res[n][o[i + 1]], res[ind][o[i + 1]]);
				}
				
				break;
			}
	}
	
	cout << n + 1 << endl;
	forn (i, n + 1) {
		forn (j, n)
			cout << res[i][j];
		cout << endl;
	}

	return 0;
}