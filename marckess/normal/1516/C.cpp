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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n, a[MX], sum, g, mem[MX][MX * 2005];

int dp (int i, int j) {
	if (2 * j == sum) return 1;
	if (i == n) return 0;
	
	int &res = mem[i][j];
	if (res != -1) return res;
	
	return res = dp(i + 1, j) | dp(i + 1, j + a[i]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	forn (i, n) {
		cin >> a[i];
		g = __gcd(g, a[i]);
	}
	
	forn (i, n) {
		a[i] /= g;
		sum += a[i];
	}
	
	memset(mem, -1, sizeof(mem));
	if (dp(0, 0)) {
		cout << 1 << endl;
		forn (i, n)
			if (a[i] & 1) {
				cout << i + 1 << endl;
				break;
			}
	} else {
		cout << 0 << endl;
	}
	
	return 0;
}