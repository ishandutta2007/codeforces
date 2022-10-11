#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <string>
#include <unordered_set>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define pb push_back
#define all(v) v.begin(), v.end()
#define v_ll vector <long long>
#define v_b vector <bool>
#define v_c vector <char>
#define v_s vector <string>
#define v_p vector < pair <long long, long long> >
#define FIXED cout << fixed << setprecision(10) <<
#define str string
#define getl getline
#define res resize
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define ll long long
#define ld long double
#define rep(i, l, r) for (long long i = l; i < r; i++)
#define per(i, r, l) for (long long i = r; i >= l; i--)

using namespace std;

void print_v(v_ll v)
{
	for (auto i : v) {
		cout << i << " ";
	}
}

signed main()
{
	FAST;
	ll n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	vector <ll> dp(n);
	dp[0] = 1;
	ll now = 1;
	rep(i, 1, n) {
		now += 2;
		dp[i] = dp[i - 1] + now;
	}
	cout << dp[n - 1] + dp[n - 2];
	//system("pause");
}