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

const int MX = 40005, mod = 1000000007;
int n, dp[MX];
vi p;

bool isPal (int x) {
	string s = to_string(x);
	int i = 0, j = (int)s.size() - 1;
	while (i < j) {
		if (s[i] != s[j]) {
			return 0;
		}
		i++, j--;
	}
	return 1;
}

void main_() {
	int n;
	cin >> n;
	cout << dp[n] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for (int i = 1; i < MX; i++)
		if (isPal(i))
			p.pb(i);
	
	dp[0] = 1;
	for (int x : p)
		forn (i, MX - x)
			(dp[i + x] += dp[i]) %= mod;
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}