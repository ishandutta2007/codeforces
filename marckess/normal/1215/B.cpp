#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], cn[2];
ll res[2];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn(i, n) {
		int x;
		cin >> x;
		a[i] = x < 0;
	}

	cn[0] = 1;
	forn(i, n) {
		if (i) a[i] ^= a[i-1];
		res[a[i]] += cn[0];
		res[1-a[i]] += cn[1];
		cn[a[i]]++;
	}
	cout << res[1] << " " << res[0] << endl;

	return 0;
}