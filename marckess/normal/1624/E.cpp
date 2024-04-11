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

int dp[1111];

void main_() {
	map<string, vi> st;
	int n, m;
	cin >> n >> m;
	
	forn (j, n) {
		string s;
		cin >> s;
		
		forn (i, m) {
			if (i + 1 < m)
				st[s.substr(i, 2)] = {i + 1, i + 2, j + 1};
				
			if (i + 2 < m)
				st[s.substr(i, 3)] = {i + 1, i + 3, j + 1};
		}
	}
	
	forn (i, m + 5)
		dp[i] = 0;
	dp[m] = 1;
	
	string s;
	cin >> s;
	
	for (int i = m - 2; i >= 0; i--)
		for (int j = 2; j <= 3; j++)
			if (i + j <= m && st.count(s.substr(i, j)))
				dp[i] |= dp[i + j];
				
	if (!dp[0]) {
		cout << -1 << endl;
		return;
	}
	
	vvi res;
	int x = 0;
	
	while (x < m) {
		if (dp[x + 2]) res.pb(st[s.substr(x, 2)]), x += 2;
		else res.pb(st[s.substr(x, 3)]), x += 3;
	}
	
	cout << res.size() << endl;
	for (vi v : res) {
		for (int x : v)
			cout << x << " ";
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}