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
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 300005;
int n;
ll a[2][MX], izq[2][MX], der[2][MX], sum[2][MX], res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < 2; i++)
		for (int j = n-1; j >= 0; j--) {
			sum[i][j] = sum[i][j+1] + a[i][j];
			izq[i][j] = izq[i][j+1] + sum[i][j];
		}

	for (int i = 0; i < 2; i++)
		for (int j = n-1; j >= 0; j--)
			der[i][j] = der[i][j+1] + (n - j) * a[i][j];

	res = izq[0][0] + der[1][0] + n * sum[1][0];

	int x = 0, y = 0, p = 1;
	ll acu = 0;

	while (y < n) {
		acu += p * a[x][y];

		res = max(res, 
			acu + izq[x][y+1] + p * sum[x][y+1]
			+ der[1-x][y+1] + (n-y-1+p) * sum[1-x][y+1]);

		if (x % 2 == y % 2)
			x = 1 - x;
		else y++;

		p++;
	}

	cout << res - sum[1][0] - sum[0][0] << endl;

	return 0;
}