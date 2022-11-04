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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, x, y, fx, fy, k;
int arr[MX], aba[MX], izq[MX], der[MX];
ll res;
string s;

void no () {
	cout << -1 << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> x >> y >> s;

	if (s[0] == 'U') fx = -1;
	else fx = 1;

	if (s[1] == 'L') fy = -1;
	else fy = 1;

	if (m % 2 == 0) k += n;
	else k += 2 * ((n + 1 - (x + y) % 2) / 2);

	if (n % 2 == 0) k += m;
	else k += 2 * ((m + 1 - (x + y) % 2) / 2);

	while (k) {
		if (x == 1) {
			if (!arr[y]) k--;
			arr[y]++;
			if (arr[y] == 3) no();
			fx = 1;
		}

		if (x == n) {
			if (!aba[y]) k--;
			aba[y]++;
			if (aba[y] == 3) no();
			fx = -1;
		}

		if (y == 1) {
			if (!izq[x]) k--;
			izq[x]++;
			if (izq[x] == 3) no();
			fy = 1;
		}

		if (y == m) {
			if (!der[x]) k--;
			der[x]++;
			if (der[x] == 3) no();
			fy = -1;
		}

		if (!k) break;

		int d;

		if (fx == -1) d = x - 1;
		else d = n - x;

		if (fy == -1) d = min(d, y - 1);
		else d = min(d, m - y);

		res += d;
		x += fx * d;
		y += fy * d;
	}

	cout << 1 + res << endl;

	return 0;
}