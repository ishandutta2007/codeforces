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

int n, m, a[88], pos[88];
int mem[81][81][81 * 80 / 2];

int dp (int i, int j, int k) {
	if (k < 0) return -1e9;
	if (j == m) return (i - m) * (n - i);
	if (i == n) return -1e9;

	int &res = mem[i][j][k];
	if (res != -1) return res;
	res = 0;

	int sum = 0;
	for (int x = i; x + (m - j) <= n; x++) {
		int y = sum + dp(x + 1, j + 1, k - abs(x - pos[j]));
		if (y > res) res = y;
		sum += i - j;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		if (a[i]) pos[m++] = i;
	}
	pos[m] = n;

	memset(mem, -1, sizeof(mem));
	for (int i = 0; i <= n * (n - 1) / 2; i++)
		cout << dp(0, 0, i) << " ";
	cout << endl;

	return 0;
}