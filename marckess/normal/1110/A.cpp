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

const int MX = 100005;
ll n, k, a[MX], s, b = 1;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;

	forn (i, k) cin >> a[i];
	reverse(a, a + k);

	forn (i, k) {
		s += b * a[i] % 2;
		b *= n;
		b %= 2;
	}

	if (s % 2) cout << "odd" << endl;
	else cout << "even" << endl;

	return 0;
}