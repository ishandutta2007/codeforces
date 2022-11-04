
// Problem : F1. Korney Korneevich and XOR (easy version)
// Contest : Codeforces - Codeforces Round #750 (Div. 2)
// URL : https://codeforces.com/contest/1582/problem/F1
// Memory Limit : 512 MB
// Time Limit : 1500 ms
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

const int MX = 100005;
int n, a[MX], dp[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	forn (i, (1 << 9))
		dp[i] = MX;
	dp[0] = -1;
	
	forn (i, n)
		forn (j, (1 << 9))
			if (dp[j] < a[i])
				dp[j ^ a[i]] = min(dp[j ^ a[i]], a[i]);
	
	int res = 0;
	forn (i, (1 << 9))
		res += dp[i] < MX;
	
	cout << res << endl;
	forn (i, (1 << 9))
		if (dp[i] < MX)
			cout << i << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}