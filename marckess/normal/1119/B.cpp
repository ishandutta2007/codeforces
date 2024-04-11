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

const int MX = 1005;

int n, a[MX], h;

bool can (int k) {
	sort(a, a+k);
	ll x = 0;
	for (int i = 1 - (k & 1); i < k; i += 2)
		x += a[i];
	return x <= h;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> h;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int k = 1;
	while (k <= n && can(k)) k++;
	cout << k - 1 << endl;

	return 0;
}