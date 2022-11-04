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

const int MX = 255;
int n, m, a[MX], acu[MX];
int mem[MX][MX][MX];

int dp (int i, int act, int pre) {
	if (act < 0) return 1e9;
	if (pre > m) return 1e9;
	
	if (i == n) {
		if (pre == m)
			return 0;
		return 1e9;
	}
	
	int &res = mem[i][act][pre];
	if (res != -1) return res;
	
	res = min(
		dp(i, act - 1, pre),
		dp(i + 1, act, pre + act) + abs(acu[i] - (pre + act))
	);
	
	return res;
}

void main_() {
	cin >> n >> m;
	
	forn (i, n) {
		cin >> a[i];
		
		acu[i] = a[i];
		if (i) acu[i] += acu[i - 1];
	}
	
	memset(mem, -1, sizeof(mem));
	
	cout << dp(0, m, 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}