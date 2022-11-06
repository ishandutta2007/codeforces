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

const int MX = 1 << 18, mod = 998244353;
int n, cn;
string s;

string dfs (int u) {
	if (u >= (1 << n)) return "";
	
	string a = dfs(2 * u);
	string b = dfs(2 * u + 1);
	
	if (a != b) cn++;
	
	string ret;
	ret.pb(s[u - 1]);
	ret += min(a, b) + max(a, b);
	return ret;
}

void main_() {
	cin >> n >> s;
	dfs(1);
	
	ll res = 1;
	while (cn--) {
		(res *= 2) %= mod;
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}