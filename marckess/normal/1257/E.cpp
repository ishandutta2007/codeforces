#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, k[3], a[MX], mem[MX][3];

int dp (int i, int j) {
	if (j == 3) return 1e9;
	if (i == n + 1) return 0;
	int &res = mem[i][j];
	if (res != -1)
		return mem[i][j];
	return res = min(
		dp(i + 1, j) + (a[i] != j),
		dp(i, j + 1)
	);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> k[0] >> k[1] >> k[2];

	for (int i = 0; i < 3; i++) {
		n += k[i];
		while (k[i]--) {
			int x;
			cin >> x;
			a[x] = i;
		}
	}

	memset(mem, -1, sizeof(mem));
	cout << dp(1, 0) << endl;

	return 0;
}