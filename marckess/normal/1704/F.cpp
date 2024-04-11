#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

const int MX = 500005;
int n, dp[MX];
string s;

void main_() {
	cin >> n >> s;
	
	int x = 0, y = 0;
	for (char c : s) {
		if (c == 'R') {
			x++;
		} else {
			y++;
		}
	}
	
	if (x > y) {
		cout << "Alice" << endl;
		return;
	}
	
	if (x < y) {
		cout << "Bob" << endl;
		return;
	}
	
	int acu = 0, cn = 0;
	forn (i, n) {
		if (!i || s[i] != s[i - 1])
			cn++;
		else {
			acu ^= dp[cn];
			cn = 1;
		}
	}
	acu ^= dp[cn];
	
	if (acu) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	dp[0] = dp[1] = 0;
	for (int i = 2; i < MX; i++) {
		if (i > 1000) {
			dp[i] = dp[i - 34];
			continue;
		}
			
		set<int> st;
		for (int j = 0; j <= i - 2; j++)
			st.insert(dp[j] ^ dp[i - 2 - j]);
		
		dp[i] = 0;
		while (st.count(dp[i]))
			dp[i]++;
	}
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}