#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 5010;
const int64 mod = 1000000007;

string s;
int _pref[maxn][maxn];

int pref(int p1, int p2){
	if (max(p1, p2) >= (int)s.length() || s[p1] != s[p2]) return 0;
	if (_pref[p1][p2]) return _pref[p1][p2];
	return _pref[p1][p2] = 1 + pref(p1 + 1, p2 + 1);
}

bool __less__(int p1, int p2){
	int pr = pref(p1, p2);
	if (pr >= abs(p1 - p2)) return false;
	return s[p1 + pr] < s[p2 + pr];
}

int64 dp[maxn][maxn];
bool memo[maxn][maxn];

int64 solve(int b, int e){
	assert(b < e);
	if (s[b] == '0') return 0;
	if (e == s.length()) return 1;

	if (memo[b][e]) return dp[b][e];
	memo[b][e] = true;
	int64 &ans = dp[b][e];
	ans = 0;
	int sz = e - b;

	if (e + sz <= s.length()){
		if (__less__(b, e)) ans = solve(e, e + sz);
		else{
			if (e + sz + 1 <= s.length())
				ans = solve(e, e + sz + 1);
		}
	}

	ans = (ans + solve(b, e + 1)) % mod;
	// cout << b << " " << e << " " << ans << endl;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	cin >> s;

	// cout << __less__(0, 4) << endl;

	cout << solve(0, 1) << endl;

	return 0;
}