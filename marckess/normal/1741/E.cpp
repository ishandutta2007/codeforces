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

const int MX = 200005;
int n, b[MX], dp[MX];

void main_() {
	cin >> n;
	forn (i, n) {
		cin >> b[i];
		dp[i] = 0;
	}
	dp[n] = 1;
	
	set<int> suf;
	
	for (int i = n - 1; i >= 0; i--) {
		if (i + b[i] < n) {
			dp[i] |= dp[i + b[i] + 1];
		}
		
		if (suf.count(i)) {
			dp[i] |= 1;
		}
		
		if (dp[i + 1]) {
			suf.insert(i - b[i]);
		}
	}
	
	if (dp[0]) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}