// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n, a[MX], b[MX], mem[MX][MX * MX];

int dp (int i, int x, int y) {
	if (i == n) return 0;
	
	int &res = mem[i][x];
	if (res != -1) return res;
	
	return res = min(
		dp(i + 1, x + a[i], y + b[i]) + x * a[i] + y * b[i],
		dp(i + 1, x + b[i], y + a[i]) + x * b[i] + y * a[i]
	);
}

void main_() {
	cin >> n;
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> b[i];
	
	memset(mem, -1, sizeof(mem));
	
	ll p = 0;
	forn (i, n) {
		p += a[i] * a[i] * (n - 1);
		p += b[i] * b[i] * (n - 1);
	}
	
	cout << p + 2 * dp(0, 0, 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}