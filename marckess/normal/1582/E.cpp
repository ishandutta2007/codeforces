
// Problem : E. Pchelyonok and Segments
// Contest : Codeforces - Codeforces Round #750 (Div. 2)
// URL : https://codeforces.com/contest/1582/problem/E
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

const int MX = 100005, SQ = 450;
int n, a[MX];
ll dp[MX][SQ], acu[MX];

ll sum (int i, int j) {
	if (i) return acu[j] - acu[i - 1];
	return acu[j];
}

void main_() {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		
		acu[i] = a[i];
		if (i) acu[i] += acu[i - 1];
	}
	
	forn (i, n)
		memset(dp[i], 0, sizeof(dp[i]));
	
	for (int i = n - 1; i >= 0; i--)
		for (int j = 1; j < SQ; j++) {
			if (i + 1 < n) dp[i][j] = dp[i + 1][j];
			if (i + j - 1 >= n || i - j + 1 < 0) continue;
			
			if (j == 1 || sum(i - j + 1, i) < dp[i + j - 1][j - 1])
				dp[i][j] = max(dp[i][j], sum(i - j + 1, i));
		}
	
	int res = 0;
	forn (j, SQ)
		if (dp[0][j])
			res = j;
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}