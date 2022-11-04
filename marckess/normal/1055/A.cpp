#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, a[MX], b[MX], s;

void no () {
	cout << "NO" << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	if (!a[0]) no();
	
	if (!a[s-1]) {
		bool res = 0;
		for (int i = s; i < n; i++)
			res |= a[i] && b[i];
		if (!res || !b[s-1]) no();
	}

	cout << "YES" << endl;

	return 0;
}