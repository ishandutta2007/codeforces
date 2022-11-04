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

const int MX = 505;
int n, l, k, a[MX], d[MX], mem[MX][MX];

int dp (int i, int k) {
	if (k < 0) return 1e9 + 5;
	if (i == n) return 0;
	
	int &res = mem[i][k];
	if (res != -1) return res;
	res = 1e9 + 5;
	
	for (int j = i; j < n; j++)
		res = min(res, (d[j + 1] - d[i]) * a[i] + dp(j + 1, k - (j - i)));
	return res;
}

void main_() {
	cin >> n >> l >> k;
	forn (i, n) cin >> d[i];
	forn (i, n) cin >> a[i];
	
	memset(mem, -1, sizeof(mem));
	d[n] = l;
	
	cout << dp(0, k) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}