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
typedef vector<ll> vl;
typedef vector<ii> vii;
 
int n, mem[52][52][52][52];
char c[52][52];

int dp (int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2) {
		return c[x1][y1] == '#';
	}

	int &res = mem[x1][y1][x2][y2];
	if (res != -1) return res;
	res = max(x2 - x1 + 1, y2 - y1 + 1);

	for (int x = x1; x < x2; x++)
		res = min(res, dp(x1, y1, x, y2) + dp(x+1, y1, x2, y2));
	for (int y = y1; y < y2; y++)
		res = min(res, dp(x1, y1, x2, y) + dp(x1, y+1, x2, y2));
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 	memset(mem, -1, sizeof(mem));

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	cout << dp(0, 0, n-1, n-1) << endl;

	return 0;
}