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
#define sz(v) v.size()
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
	ll n; cin >> n;
	v_ll v(n);
	v_ll dp(n + 1);
	dp[0] = 0;
	rep(i, 0, n) {
		cin >> v[i];
		dp[i + 1] = v[i] + dp[i];
	}
	ll q;
	cin >> q;
	rep(i, 0, q) {
		ll l, r; cin >> l >> r;
		cout << (dp[r] - dp[l - 1]) / 10 << '\n';
	}
	//system("pause");
}