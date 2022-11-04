
// Problem : B. Up the Strip
// Contest : Codeforces - Codeforces Round #740 (Div. 1, based on VK Cup 2021 - Final (Engine))
// URL : https://codeforces.com/contest/1558/problem/B
// Memory Limit : 128 MB
// Time Limit : 6000 ms
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

const int MX = 4000005;
int n, mod, dp[MX], x[MX];

inline void sum (int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	if (a < 0) a += mod;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> mod;
	
	int acu = 0;
	x[1] = 1, x[2] = mod - 1;
	
	for (int i = 1; i <= n; i++) {
		sum(x[i], x[i - 1]);
		dp[i] = x[i];
		
		sum(dp[i], acu);
		sum(acu, dp[i]);
		
		for (int j = 2 * i, k = 2; j <= n; j += i, k++) {
			int s = min(j + k, n + 1);
			sum(x[j], dp[i]);
			sum(x[s], -dp[i]);
		}
	}
	
	cout << dp[n] << endl;
	
	return 0;
}