/*input
8
23 2 7 5 15 8 4 10

3
3 3 3

5
1 2 3 1 2

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define int long long
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
const int N = 1e6 + 5;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}

int n;
int a[N];
int dp[N][2][2];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	loop(i, 1, n) {
		cin >> a[i];
	}
	memset(dp, -127, sizeof(dp));
	dp[0][1][1] = 0; dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = -1e18;
	// pos, have smallest, have biggest
	loop(i, 1, n) {
		dp[i][1][0] = max(dp[i][1][0], dp[i - 1][1][1] - a[i]);
		dp[i][1][0] = max(dp[i][1][0], dp[i - 1][1][0]);

		dp[i][0][1] = max(dp[i][0][1], dp[i - 1][1][1] + a[i]);
		dp[i][0][1] = max(dp[i][0][1], dp[i - 1][0][1]);

		dp[i][1][1] = max(dp[i][1][1], dp[i - 1][0][1] - a[i]);
		dp[i][1][1] = max(dp[i][1][1], dp[i - 1][1][0] + a[i]);
		dp[i][1][1] = max(dp[i][1][1], dp[i - 1][1][1]);
	}
	cout << dp[n][1][1] << endl;
}